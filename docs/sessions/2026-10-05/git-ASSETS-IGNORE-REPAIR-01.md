# Git — ASSETS-IGNORE-REPAIR / 01

- 날짜: 2026-10-05 (Asia/Seoul)
- 역할 / 작업 ID: Git / Assets 제외 규칙 복구
- 브랜치 / 작업 공간: codex/restore-assets-ignore / assets-ignore-repair-worktree
- 기준 커밋: dev 669eb13727bc7cf6d59d30e5d05f9e5055cccfae
- 관련 PR: 기존 #9의 충돌 해결 이후 누락 복구

## 목표와 수행 내용

PR #9 병합 결과에서 기존 루트 /Assets/ 제외가 빠진 것을 원격 head와 dev 양쪽에서 확인했다. 사용자 기존 로컬 전용 정책을 복원하도록 .gitignore에 /Assets/만 추가했다. 나머지 세 제외 규칙은 변경하지 않았다. 이번 변경은 새 정책이 아니며 main과 다른 checkout의 사용자 변경을 갱신하지 않았다.

## 어려움과 해결 시도

기존 PR은 이미 병합되어 최신 dev 기반 별도 작업 브랜치로 수정 PR을 준비했다. LFS smudge를 생략한 문서·설정 작업 공간에서 공개 에셋을 새로 추가하지 않았다.

## 검증

git check-ignore -v로 Assets/, Content/Assets/, Content/TripoModels/, Tripo 설치 경로를 확인한다. staged diff --check와 두 파일의 변경 범위·시크릿 패턴을 확인한다. Assets 실제 파일 내용은 출력하거나 스테이징하지 않는다. .gitattributes·Source·Config·uproject 변경 없음. UE 빌드·실행 및 외부 에셋 백업은 미검증이다.

## 결정과 학습

충돌 해결은 한쪽 규칙 선택으로 기존 제외 정책을 잃지 않도록 최종 규칙 집합을 검사해야 한다. 이번 PR 병합은 사용자 별도 결정이다.

## 인수인계

복구 PR을 첨부하고 PM에 head·범위·검증 결과를 보고한다. 실제 병합은 하지 않는다.
