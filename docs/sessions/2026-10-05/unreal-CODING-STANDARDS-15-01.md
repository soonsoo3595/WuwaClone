# 언리얼 개발 — CODING-STANDARDS-15 / 01

- 날짜·시간: 2026-10-05 (Asia/Seoul, 날짜 기록)
- 역할 / 작업 ID: 언리얼 개발 / CODING-STANDARDS-15
- 브랜치 / 작업 공간: codex/15-coding-standards / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 07b57950068a8960e0434f9115cb08444da0a57b / 미커밋
- 관련 Issue / PR / 명세: Issue #15 / PR 없음 / docs/project/coding-standards.md 초안

## 목표와 수행 내용

사용자 요청을 전달받아 규약 논의용 단일 초안을 작성했다. 필수·권장·사용자 결정 대기와 Epic 기준·프로젝트 선택을 구분했다. C++ 스타일, 이름, include/모듈, UObject 수명, Blueprint 경계, 오류/로그, 네트워킹과 주석을 다뤘다. C#은 적용 영역만 구분했다. 현재 브랜치를 확인했으며 새 브랜치/worktree는 만들지 않았다. 기존 PM 로그는 수정하지 않았다.

## 어려움과 해결 시도

규약 채택과 실제 구현 승인, Epic 관례와 엔진 제약을 혼동하지 않도록 초안 상태와 적용 범위를 명시했다. 공식 문서에 기반한 참조 수명·RPC 조건과 프로젝트 선택을 나눴다. 세 가지 주요 선택은 사용자 결정 대기로 남겼다.

## 검증

- 실행: git status --short --branch로 작업 브랜치 및 기존 PM 미추적 로그 확인.
- 실행: 운영 문서와 세션 템플릿, WuwaCloneCharacter.h, WuwaClone.Build.cs 읽기.
- 실행: git rev-parse HEAD로 기준 커밋 확인.
- 읽기 확인: Epic Coding Standard, Object Pointers, IWYU, Networked Character Movement, RPC 공식 문서. 링크는 초안에 기록.
- 미실행: 게임 코드 수정, 빌드·런타임·네트워크 QA, CI 구현, 커밋·push·PR.

## 결정과 학습

초안은 확정 규약이 아니다. 사용자 결정 대기: 주석/로그 언어, Blueprint 분담, auto 허용 범위. 제안은 신규·변경 코드부터 적용하고 기존 템플릿은 일괄 변경하지 않는 것이다. 사용자 답변은 아직 없다.

## 인수인계

사용자와 세 선택 및 규칙 수준을 논의한다. 확정/커밋·push의 파일 범위는 이후 정한다. 초안 준비 사실을 사용자와 PM에 보고한다. 추가 세션 메시지나 자동 검토 요청은 하지 않는다.
