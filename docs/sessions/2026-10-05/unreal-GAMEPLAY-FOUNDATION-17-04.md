# 언리얼 개발 — GAMEPLAY-FOUNDATION-17 / 04

- 날짜·시간: 2026-10-05 (Asia/Seoul, 날짜 기록)
- 역할 / 작업 ID: 언리얼 개발 / GAMEPLAY-FOUNDATION-17
- 브랜치 / 작업 공간: codex/17-gameplay-foundation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 사용자 미커밋 Controller 수정본 / 미커밋
- 관련 Issue / PR / 명세: Issue #17 / PR 없음 / 필수 할당 검사 책임 분리

## 목표와 수행 내용

사용자가 필수 Blueprint 에셋 검사 책임을 한 함수로 모으도록 코드 수정을 요청했다. ValidateRequiredAssets() const에 Context/Move/Jump 할당과 액션 타입 checkf를 모았다. 함수 선언·정의·호출 모두 !UE_BUILD_SHIPPING 조건 안에 둔다. 로컬 Controller의 SetupInputComponent에서 호출한다. 에셋에 대한 기존 런타임 분기·경고는 제거하고 매핑/바인딩을 수행한다. 런타임 객체 InputComponent·Subsystem·Character는 IsValid로 검사하며 bool 부정은 == false로 표현한다. 사용자 변경 LogWuwa 및 Abstract는 보존했다.

## 어려움과 해결 시도

실행 중 에디터가 기존 전체 빌드의 DLL 링크를 막았으므로 UBT SingleFile 기능을 엔진 소스에서 확인했다. 해당 컴파일을 위한 샌드박스 외부 실행 승인이 사용자에 의해 거절되어 실행하지 않았다. 승인 재요청이나 에디터 종료는 하지 않았다.

## 검증

- 현재 브랜치·운영 문서·실제 Controller 수정본을 읽었다.
- 변경 파일을 재읽어 선언·정의·호출의 Shipping 조건부 제외 및 checkf 검사 순서를 확인했다.
- 줄 끝 공백과 일본어/중국어 문자 혼입을 Select-String으로 확인했다.
- 미실행: 이번 수정의 컴파일, Shipping 빌드, PIE 및 별도 QA/리뷰. 이전 버전의 컴파일 결과를 이번 수정 통과로 간주하지 않는다.

## 결정과 학습

필수 에셋은 개발 중 설정 불변식으로 검사하고 런타임 매핑/바인딩 책임과 분리한다. 검사는 게임 초기화 시점이며 에디터 저장 단계 검증은 아니다. Shipping에서 함수가 빠지고 checkf의 기본 Test 비활성화 특성은 그대로 유지된다.

## 인수인계

사용자가 코드를 확인한 뒤 컴파일과 실제 설정을 검증할 수 있다. 학습 노트·전체 상태 문서는 수정하지 않았다. PM 전달, 커밋·push·PR은 하지 않았다.
