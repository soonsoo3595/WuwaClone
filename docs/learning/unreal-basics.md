# 언리얼 학습 노트

질문한 문법과 이번 프로젝트에서 사용한 개념을 기록한다. 2026-10-05 작성.

## PublicIncludePaths와 폴더 구분

`PublicIncludePaths`는 컴파일러가 헤더를 찾을 검색 경로를 추가한다. C++ 클래스의 `public/private` 접근 지정자와 별개다. 현재 `WuwaClone.Build.cs`에는 모듈 루트 `WuwaClone`이 이미 등록되어 있다.

예를 들어 `Source/WuwaClone/Player/WuwaBasePlayerController.h`는 다음처럼 포함할 수 있다.

```cpp
#include "Player/WuwaBasePlayerController.h"
```

모듈 루트를 추가해도 모든 하위 폴더의 헤더를 파일명만으로 찾지는 않는다. `Public` 폴더는 다른 모듈에 공개할 헤더, `Private` 폴더는 내부 구현을 구분하는 UE 관례다. 모듈 내부에만 필요한 추가 검색 경로는 `PrivateIncludePaths`로 제한할 수 있다. 현재 프로젝트는 폴더를 나누지 않은 구조를 유지한다.

근거: [Module Properties](https://dev.epicgames.com/documentation/unreal-engine/module-properties-in-unreal-engine).

## UCLASS(Abstract)

```cpp
UCLASS(Abstract)
class WUWACLONE_API AWuwaGameMode : public AGameModeBase
```

`Abstract`는 엔진에서 그 클래스 자체를 일반 게임 인스턴스로 직접 생성·스폰하는 용도로 쓰지 않도록 지정한다. 구체적인 Blueprint 자식이나 C++ 자식은 사용할 수 있다. 부모 타입 포인터로 참조하거나 공통 함수를 호출하는 것도 가능하다. C++의 순수 가상 함수 문법과는 별개이고, 엔진은 추상 클래스에도 기본값용 CDO를 만든다.

Blueprint 상속 허용 여부는 `Blueprintable`과 관련되며 `Abstract`만으로 결정하지 않는다. Blueprint 자식을 실제 사용하려면 그 자식의 Generate Abstract Class 설정은 끈다. 이 노트 작성으로 기존 클래스에 Abstract를 일괄 추가하지 않았다.

근거: [Class Specifiers](https://dev.epicgames.com/documentation/en-us/unreal-engine/class-specifiers).

## Controller의 걷기·점프 입력 템플릿

현재 구현: `Source/WuwaClone/Player/WuwaBasePlayerController.h/.cpp`.

입력 경로는 키 → Mapping Context → Input Action → Controller 콜백 → 조종 중인 Character다. Controller는 의도를 전달하고 CharacterMovement가 실제 이동을 처리한다. Character를 이동시키려고 매 프레임 위치를 직접 변경하지 않는다.

| 문법/API | 역할 |
| --- | --- |
| `SetupInputComponent() override` | 부모의 입력 초기화 뒤 Controller 액션을 바인딩 |
| `Super::SetupInputComponent()` | 부모 클래스 초기화 보존 |
| `UPROPERTY(EditDefaultsOnly)` | Blueprint 클래스 기본값에서 에셋 지정. 각 배치 인스턴스 편집은 열지 않음 |
| `TObjectPtr` + `UPROPERTY` | Input Action/Mapping Context를 GC가 추적하는 멤버 참조로 유지 |
| `IsLocalPlayerController()` | 로컬 플레이어의 입력/UI 처리 여부. 서버 권위 검사와 다름 |
| `AddMappingContext(Context, 0)` | 로컬 플레이어에 키 매핑을 우선순위 0으로 활성화 |
| `BindAction(Action, Event, this, &Class::Function)` | 액션 이벤트에 멤버 함수 연결 |
| `Value.Get<FVector2D>()` | Axis2D 입력 값 읽기. 액션 타입과 일치해야 함 |
| `GetCharacter()` | 지금 조종하는 Character 조회. Pawn이 없거나 Character가 아니면 null 가능 |
| `AddMovementInput(Direction, Scale)` | 월드 방향과 입력 크기로 이동 의도 전달 |
| `Jump()` / `StopJumping()` | 점프 요청 시작/종료. 실제 점프는 Character가 판단하고 처리 |

이동 액션은 `Triggered`, 점프는 `Started`에 연결했다. `Completed`와 `Canceled`에서는 점프 요청을 종료한다. 점프 액션에 별도 Hold/Pressed 트리거를 넣는 정책은 이번 템플릿에 포함하지 않는다. 값이 들어오는 동안 유지되는 기본 Digital 액션을 사용한다.

이동 값은 X=좌우, Y=전후다. ControlRotation에서 Yaw만 사용하므로 시선 Pitch에 따라 위로 걷지 않는다. 이번 작업에는 카메라 회전 입력을 추가하지 않아 Yaw가 별도로 바뀌지 않으면 현재 수평 방향이 유지된다. 이동 속도는 CharacterMovement의 `MaxWalkSpeed`, 점프 높이에 영향을 주는 초기 속도는 `JumpZVelocity`로 조절할 수 있지만 이번 템플릿에서는 수치를 변경하지 않았다.

### 에디터에서 연결하기

컴파일 후 `AWuwaBasePlayerController`를 상속한 Blueprint의 Class Defaults에서 다음을 지정한다.

| 프로퍼티 | 기존 에셋 예시 |
| --- | --- |
| Default Mapping Context | `/Game/Input/IMC_Default` |
| Move Action | `/Game/Input/Actions/IA_Move` (Axis2D) |
| Jump Action | `/Game/Input/Actions/IA_Jump` (Digital/bool) |

Mapping Context가 지정한 Move/Jump 액션과 같은 에셋을 참조하는지 확인한다. 새로 매핑한다면 D=+X, A=-X, W=+Y, S=-Y다. 키 입력 기본 축은 X이므로 W/S에는 Swizzle로 Y축 전환, A/S에는 Negate가 필요하다. 점프는 Space 등 원하는 키에 매핑한다.

GameMode Blueprint의 PlayerControllerClass/DefaultPawnClass는 해당 Controller/Character Blueprint로 연결한다. 새 Controller 부모는 기존 템플릿 Controller를 상속하지 않으므로 기존 Mapping Context 기본값이 자동으로 복사되지는 않는다.

Controller C++에서 이미 처리하는 같은 액션을 Character Blueprint에서 중복 바인딩하지 않는다. Blueprint가 `Block Input`으로 하위 입력을 막으면 Controller 입력 전달에도 영향을 줄 수 있다. 현재 Blueprint 그래프·기본값·매핑 내부를 변경하거나 실행 확인하지 않았다.

### 범위와 확인할 항목

이번 코드는 걷기·점프 입력의 시작점이다. 카메라, 달리기, Android 터치 UI, 리스폰/입력 컨텍스트 전환, 별도 RPC·서버 동기화 확장은 포함하지 않는다. PIE에서 전후좌우 이동, 점프 누름/뗌, Pawn 미보유 상태, 잘못된 에셋 설정 로그를 확인하면 된다. 별도 실행 QA나 서버 동기화 검증을 통과했다고 보지 않는다.

근거: [Enhanced Input](https://dev.epicgames.com/documentation/unreal-engine/enhanced-input-in-unreal-engine), [Input Overview](https://dev.epicgames.com/documentation/unreal-engine/input-overview-in-unreal-engine), [ACharacter::Jump](https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/Engine/ACharacter/Jump).

## 에디터에서 정하는 설정과 런타임 객체 검사

2026-10-05 사용자 결정: 개발자가 미리 지정해야 하는 에셋은 에디터 단계에서 할당·검증한다. DefaultMappingContext, MoveAction, JumpAction의 누락이나 잘못된 타입은 콘텐츠 설정 오류로 다룬다. 런타임 입력 처리마다 설정 누락을 검사하는 방향으로 작성하지 않는다.

`EditDefaultsOnly`는 편집 가능한 위치를 클래스 기본값으로 제한할 뿐, 필수 에셋의 할당을 강제하지 않는다. 에디터에서 누락을 실제로 발견하려면 Data Validation의 IsDataValid 또는 에디터 Validator 같은 별도 검증을 구성해야 한다. 해당 검증은 아직 구현하지 않았다. [Data Validation 공식 문서](https://dev.epicgames.com/documentation/unreal-engine/data-validation-in-unreal-engine)

반면 `GetCharacter()`는 미소유 상태에서 null일 수 있고 런타임 객체는 파괴될 수 있다. 이런 UObject를 검사할 때는 아래 프로젝트 규약을 적용한다.

```cpp
if (IsValid(ControlledCharacter) == false)
{
    return;
}
```

프로젝트 규칙은 bool 부정에 `!` 대신 `== false`를 쓰고 UObject 포인터 검사를 IsValid로 통일하는 것이다. UObject용 IsValid는 일반 C++ 포인터 검사에 사용할 수 없다. 사전 할당 에셋 검증과 런타임 객체의 수명 검사는 목적이 다르다.

사용자는 공통 로그 카테고리를 LogWuwaClone에서 LogWuwa로 변경했다. 초기 템플릿의 에셋 런타임 검사 코드는 사용자 검토 중이며 이 문서 갱신에서는 코드를 변경하지 않았다. 위의 '잘못된 에셋 설정 로그' 확인 항목은 초기 템플릿에 대한 기록이고, 이후 검사 방식은 아래 논의를 따른다.

## 필수 할당에 check와 ensure 사용하기

사용자는 필수 할당을 check/ensure 매크로로 확인할 계획이라고 설명했다. 권장안은 '없으면 동작할 수 없는 개발자 필수 설정'에 checkf를 초기화 시점 한 번 사용하는 것이다. 아래는 제안 예시이며 실제 코드에 추가하지 않았다.

```cpp
checkf(IsValid(DefaultMappingContext) == true,
    TEXT("Controller Blueprint에 DefaultMappingContext를 지정해야 합니다."));
```

| 매크로 | 조건 실패 시 | 이 경우의 적합성 |
| --- | --- | --- |
| checkf | 활성 빌드에서 실행 중단, 원인 메시지 출력 | 필수 설정 누락을 즉시 개발 오류로 발견 |
| ensureMsgf | 비치명적 진단 후 계속 진행 | 실패 시 기능을 건너뛰는 등 안전한 경로가 있는 경우 |

ensure를 호출한 뒤 무효 객체를 그대로 역참조하면 안전해지지 않는다. ensure를 선택한다면 반환값으로 분기해 안전한 실패 처리를 해야 한다. 이는 사용자가 줄이려는 런타임 실패 분기를 다시 필요로 한다.

check는 기본 Shipping 게임 빌드에서 검사가 비활성화된다. 필수 설정이 맞다는 보증을 개발 단계에서 잡는 수단으로 사용하고, 매크로 안에 에셋 로딩·상태 변경 같은 반드시 실행할 동작을 넣지 않는다. ensure는 표현식을 모든 빌드에서 평가하지만 진단 활성 여부는 빌드 설정에 따라 다르다. ensure 계열은 기본적으로 같은 호출 지점의 첫 실패만 보고하고 Always 계열은 반복 보고한다.

초기화 함수에 넣은 매크로는 PIE/게임이 해당 코드를 실행할 때 검사한다. Blueprint 기본값 편집이나 저장만으로 자동 실행되는 에셋 검증은 아니다. 편집·저장 단계에서 발견하려면 별도 에디터 검증 호출 경로가 필요하다. 앞 절의 Data Validation은 가능한 선택지를 설명한 것이며 도입을 확정하거나 구현한 상태는 아니다.

근거: [Epic Asserts 문서](https://dev.epicgames.com/documentation/en-us/unreal-engine/asserts-in-unreal-engine), 로컬 UE 5.8.2의 Engine/Source/Runtime/Core/Public/Misc/Build.h. 최종 매크로 선택과 검사 위치는 아직 코드에 반영하지 않았다.
