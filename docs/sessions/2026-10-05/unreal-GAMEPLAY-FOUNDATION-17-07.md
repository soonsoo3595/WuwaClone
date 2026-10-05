# 언리얼 개발 — GAMEPLAY-FOUNDATION-17 / 07

- 날짜·시간: 2026-10-05 (Asia/Seoul, 날짜 기록)
- 역할 / 작업 ID: 언리얼 개발 / GAMEPLAY-FOUNDATION-17
- 브랜치 / 작업 공간: codex/17-gameplay-foundation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 87e2528 이후 템플릿 삭제가 있는 작업 트리 / 미커밋
- 관련 Issue / PR / 명세: Issue #17 / PR 없음 / Base·Playable 캐릭터 기본 템플릿 요청

## 목표와 수행 내용

사용자가 생성한 AWuwaBaseCharacter와 AWuwaPlayableCharacter의 상속을 유지하며 기본 템플릿을 정리했다. C++ 기반 클래스는 Abstract로 지정하고 실제 사용은 Blueprint 자식으로 한다. Base의 비어 있는 BeginPlay/Tick/SetupPlayerInputComponent 재정의를 제거했다. ACharacter의 기본 Tick·이동·충돌·메시 처리는 유지한다.

Playable 생성자는 Controller 몸체 회전을 끄고 CharacterMovement의 이동 방향 회전을 사용한다. 사용자 지정 단발 점프에 맞춰 JumpMaxHoldTime=0을 명시했다. 이동 속도·점프 초기 속도·캡슐 크기 수치는 추가 지정하지 않았다. 입력 바인딩은 기존 Controller에 유지하고 별도 카메라 컴포넌트, 공격·달리기·서버 동기화 확장은 추가하지 않았다.

## 어려움과 해결 시도

공통 Base에 플레이어 전용 설정을 넣지 않았다. 생성 템플릿의 빈 함수만 제거하고 엔진의 기존 Character 처리 경로를 유지했다. 이번 템플릿에는 사전 할당 에셋이 없어 비어 있는 ValidateAssignedAssets 함수를 추가하지 않았다.

## 검증

- 현재 브랜치와 운영 문서, 실제 Base/Playable/Controller 소스를 읽었다.
- 변경 파일의 공백과 불필요한 입력·Tick 재정의 참조를 확인한다.
- 미실행: 사용자 담당 컴파일·빌드, Blueprint 재부모화 및 설정 변경, PIE, 별도 QA/리뷰.

## 결정과 학습

공통 동작은 Base, 플레이어용 기본값은 Playable, 입력 의도는 Controller로 분담한다. 기능이 필요한 시점에 수명 주기 함수·에셋 검증·새 컴포넌트를 추가한다.

## 인수인계

실제 플레이어 Blueprint의 부모를 AWuwaPlayableCharacter로 연결해야 플레이어용 기본값을 사용한다. 기존 Blueprint에서 이미 재정의한 값은 별도로 확인해야 한다. 이전 템플릿 삭제 변경은 유지했고 이번 요청의 커밋·푸시, PM 전달, 학습 노트 추가는 하지 않았다.
