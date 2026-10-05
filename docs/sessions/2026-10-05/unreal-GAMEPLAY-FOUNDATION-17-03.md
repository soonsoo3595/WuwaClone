# 언리얼 개발 — GAMEPLAY-FOUNDATION-17 / 03

- 날짜·시간: 2026-10-05 (Asia/Seoul, 날짜 기록)
- 역할 / 작업 ID: 언리얼 개발 / GAMEPLAY-FOUNDATION-17
- 브랜치 / 작업 공간: codex/17-gameplay-foundation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 사용자 미커밋 코드·문서 유지 / 미커밋
- 관련 Issue / PR / 명세: Issue #17 / PR 없음 / coding-standards.md 사용자 확정 추가 규칙

## 목표와 수행 내용

사용자는 PM 전달을 직접 요청할 때만 하도록 변경했다. 코드의 LogWuwa 변경을 읽어 확인하고 기존 수정은 보존했다. bool 부정은 == false, UObject 포인터 검사에는 IsValid 사용, 필수 에셋은 에디터 사전 할당·검증 방향이라는 규칙을 코딩 규약과 학습 노트에 반영했다. 이번에는 코드나 Blueprint를 수정하지 않았다.

## 어려움과 해결 시도

필수 설정과 런타임 객체 수명 검사를 구분했다. UObject용 IsValid를 일반 C++ 포인터에 적용할 수 없다는 기술적 범위를 문서에 명시했다. EditDefaultsOnly 자체는 필수 할당을 강제하지 않아 에디터 검증 구현 여부와 정책 합의를 구분했다.

## 검증

현재 Controller.cpp, 공통 로그 헤더, 규약·학습 노트, git status를 읽었다. Epic 공식 Data Validation 문서를 확인했다. 코드 컴파일·플레이·에디터 검증·자동 QA/리뷰는 수행하지 않았다. PM 메시지를 보내지 않았다.

## 결정과 학습

확정: PM 전달은 사용자 요청 시에만. 사용자가 코드 검토·추가 수정 진행. LogWuwa 사용. 조건 부정 명시 및 UObject IsValid 검사. 필수 사전 할당 에셋의 검증은 에디터 단계로 이동하는 방향. 에디터 검증 구현은 아직 없다.

## 인수인계

사용자 코드 수정 상태를 유지한다. 추가 코드 수정 및 에디터 검증 구현은 사용자의 명시 요청에 따라 진행한다. 커밋·push·PR은 하지 않았다.

## 후속 논의: 필수 할당 단정 검사

사용자는 check/ensure 매크로를 사용할 계획이라고 설명했다. 필수 설정 누락에는 초기화 시점 checkf를 제안하고 ensure는 실패 후 안전한 처리가 필요함을 설명한다. 초기화 검사와 편집/저장 단계의 검증을 구분하며 Data Validation 도입을 확정한 것으로 해석하지 않도록 문서를 갱신했다. Epic Asserts 공식 문서와 로컬 엔진 Build.h를 확인했다. 코드 수정·빌드·PM 전달은 하지 않았다.
