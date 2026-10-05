# 언리얼 개발 — GAMEPLAY-FOUNDATION-17 / 02

- 날짜·시간: 2026-10-05 (Asia/Seoul, 날짜 기록)
- 역할 / 작업 ID: 언리얼 개발 / GAMEPLAY-FOUNDATION-17
- 브랜치 / 작업 공간: codex/17-gameplay-foundation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 현재 작업 브랜치, 사용자 미커밋 클래스 위에서 작업 / 미커밋
- 관련 Issue / PR / 명세: Issue #17 / PR 없음 / 사용자 요청: Controller의 기본 걷기·점프 템플릿

## 목표와 수행 내용

사용자가 직접 작성 지원에서 이번 걷기·점프 기본 템플릿 작성은 명시적으로 요청했다. AWuwaBasePlayerController의 기존 생성자와 클래스명을 유지하며 SetupInputComponent와 이동·점프 콜백을 추가했다. Enhanced Input을 사용하고 Blueprint 기본값에 Context/Move/Jump 에셋을 지정하도록 했다. 현재 Character를 조회해 AddMovementInput·Jump·StopJumping을 호출하며 캐릭터/게임모드 코드는 변경하지 않았다. 카메라·달리기·기획 세부 규칙·별도 RPC는 추가하지 않았다.

docs/learning/unreal-basics.md에 PublicIncludePaths, UCLASS(Abstract), 입력 코드의 문법/API 및 Blueprint 설정 절차를 기록했다. 기존 사용자 소스·Blueprint/맵 변경과 PM 로그를 보존했다. 전체 상태 갱신은 PM에 결과를 보고한다.

## 어려움과 해결 시도

- 일반 샌드박스 Build.bat는 UBT 의존성 확인 실패로 종료했다. 사용자 승인된 별도 실행에서는 빌드가 시작됐다.
- 실행 중 UnrealEditor가 엔진 NetCore DLL을 사용해 링크가 LNK1104로 실패했다. 에디터 강제 종료나 엔진 변경으로 해결하지 않았다.
- 전체 git diff --check는 기존 사용자 맵 변경의 LFS clean 필터가 .git/lfs/tmp 접근 거부로 실패했다. Source/docs로 범위를 제한한 명령은 성공했다. 미추적 파일은 이 diff 검사에 포함되지 않으므로 작성 파일의 줄 끝 공백을 Select-String으로 따로 확인하고 기존 빈 줄의 탭 하나를 제거했다.

## 검증

- 읽기: 운영 문서·코딩 규약, 새 Controller/Character, Build.cs, DefaultInput.ini 및 UE 5.8.2 엔진 헤더의 API 선언.
- 공식 문서: Enhanced Input, Input Overview, ACharacter::Jump를 확인하고 학습 노트에 연결.
- 빌드 명령: 엔진 Build.bat WuwaCloneEditor Win64 Development -Project=<프로젝트 uproject> -WaitMutex -NoHotReloadFromIDE -Log=<Saved/Logs/ControllerTemplateBuild.log>.
- 승인 실행에서 WuwaBasePlayerController.cpp 및 WuwaBaseCharacter.cpp, Module.WuwaClone.cpp 컴파일 완료 출력 확인. 엔진 Character.h의 deprecated 경고가 출력됨.
- 전체 빌드 성공 아님: UnrealEditor-NetCore.dll과 UnrealEditor-WuwaClone.dll 링크가 실행 중 에디터 파일 잠금으로 실패함. 종료 코드 1, Result: Failed (OtherCompilationError).
- git diff --check -- Source docs 성공. 작성 파일의 공백 검사 수행.
- 미실행: Blueprint 에셋 설정·그래프 변경, PIE 걷기/점프, Android, 데디케이티드 서버 이동 검증, 별도 QA/코드 리뷰, 커밋·push·PR.

## 결정과 학습

기본 구조는 Controller 입력 → 현재 Character의 엔진 이동/점프 함수다. UPROPERTY(EditDefaultsOnly)와 TObjectPtr로 입력 에셋을 지정·유지하고 로컬 Controller에서만 매핑을 등록한다. Move는 Axis2D, Jump는 bool을 요구하며 잘못된 에셋 타입은 바인딩하지 않고 초기화 로그로 알린다. Move의 X/Y는 좌우/전후이며 ControlRotation의 Yaw를 기준으로 한다. Jump 종료는 Completed/Canceled에 연결했다.

## 인수인계

사용자가 Controller Blueprint에서 DefaultMappingContext, MoveAction, JumpAction을 지정해야 한다. 기존 IMC_Default/IA_Move/IA_Jump를 활용할 수 있으나 내부 설정과 Blueprint 중복 바인딩은 미확인이다. 에디터 종료 후 전체 빌드를 확인하고 이후 실제 플레이를 검증해야 한다. 이 결과는 게임 기능 실행 완료나 서버 동기화 검증 완료를 의미하지 않는다.
