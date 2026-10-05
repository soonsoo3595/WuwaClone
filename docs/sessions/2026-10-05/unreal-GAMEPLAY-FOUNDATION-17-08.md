# 언리얼 개발 — GAMEPLAY-FOUNDATION-17 / 08

- 날짜·시간: 2026-10-05 (Asia/Seoul, 날짜 기록)
- 역할 / 작업 ID: 언리얼 개발 / GAMEPLAY-FOUNDATION-17
- 브랜치 / 작업 공간: codex/17-gameplay-foundation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 87e2528 이후 사용자 작업 트리 / 미커밋
- 관련 Issue / PR / 명세: Issue #17 / PR 없음 / 캐릭터 책임 분담 사용자 정정

## 목표와 수행 내용

사용자가 회전·점프 기본값을 전체 캐릭터 공통 특성으로 Base에 두고 Playable에는 SpringArm/Camera를 추가하도록 정정했다. Controller 회전 사용 해제, 이동 방향 회전, JumpMaxHoldTime=0을 Base 생성자로 옮겼다.

Playable은 CameraBoom과 FollowCamera를 기본 서브오브젝트로 생성한다. Root → SpringArm 소켓 → Camera로 연결하고 SpringArm이 Pawn ControlRotation을 사용하며 Camera는 이를 별도로 적용하지 않는다. 초기 암 길이는 400cm이고 Blueprint 컴포넌트 기본값에서 조정할 수 있다. 포인터는 UPROPERTY/TObjectPtr로 유지하고 컴포넌트는 Blueprint에서 확인 가능하게 했다.

## 어려움과 해결 시도

직전 템플릿에서 플레이어 설정으로 분류했던 회전·점프 기본값을 사용자의 공통 특성 정의에 맞춰 Base로 이동했다. 사용자 수정된 헤더를 읽어 현재 상태를 보존했다. 컴포넌트는 C++ 생성자가 생성하므로 에디터 필수 할당 검사 함수는 추가하지 않았다.

## 검증

수정 전 네 소스를 읽고 변경 후 공백 검사를 수행했다. 입력 바인딩은 Controller에 유지했다. 컴파일·빌드·PIE·Blueprint 편집·카메라 회전 입력 구현은 수행하지 않았다.

## 결정과 학습

Base는 캐릭터 공통 회전·점프 특성, Playable은 플레이어 전용 카메라 구성을 담당한다. SpringArm/Camera 추가와 시점 입력 구현은 구분한다.

## 인수인계

사용자가 컴파일·빌드를 수행한다. 플레이어 Blueprint의 부모 및 기존 컴포넌트 중복·재정의한 값을 확인해야 한다. 커밋·푸시·PM 전달·학습 노트 추가는 하지 않았다.
