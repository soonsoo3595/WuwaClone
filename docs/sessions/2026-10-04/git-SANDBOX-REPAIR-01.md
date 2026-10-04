# Git — SANDBOX-REPAIR / 01

- 날짜·시간: 2026-10-04 (Asia/Seoul)
- 역할 / 작업 ID: Git 문서 통합 / SANDBOX-REPAIR
- 브랜치 / 작업 공간: docs/SANDBOX-REPAIR-logs / Saved/GitSetup/sandbox-docs-worktree
- 기준 커밋: 736a1a4eb56670ee3512f13e8bc0f940c4d69cc9 (origin/dev)
- 관련 Issue: https://github.com/soonsoo3595/WuwaClone/issues/5
- 관련 문서: docs/project/repository.md, pm-SANDBOX-REPAIR-01.md, git-GIT-SETUP-06.md

## 목표와 수행 내용

PM 요청으로 로컬 복구 로그를 docs/sessions/2026-10-04/pm-SANDBOX-REPAIR-01.md에 통합했다. 기존 로컬 Git 병합 로그 06도 동일 세션 디렉터리에 복사했다. 두 원본의 내용을 유지했다. 전체 프로젝트 상태 문서와 역할 등록 갱신은 PM의 별도 작업으로 남겼다.

PM 보고에 따르면 일반 실행의 setup refresh 오류 원인은 .git이 샌드박스 계정 소유이고 실제 사용자에게 ACL 관리 권한이 없었던 것이다. PM은 로컬에 기존 ACL을 백업한 뒤 사용자·Windows 관리자 승인으로 실제 사용자 소유권과 관리 권한을 복원하고 기존 샌드박스 보호 규칙을 유지했다. 복구 후 PM과 9개 담당 채팅, 총 10개 채팅의 일반 문서 읽기가 성공했다고 보고했다. Git 담당이 복구를 다시 수행하거나 다른 9개 채팅의 검증을 대신 실행한 것은 아니다.

새 Git 메타데이터를 샌드박스 계정 소유로 만들지 않도록 worktree 생성과 네트워크 Git 작업은 승인된 실제 사용자 실행을 사용했다. origin/dev 기반 전용 문서 worktree를 만들었고 main checkout은 유지했다. Git 담당은 공개 세션 문서만 선별하고 원본 ACL·SID·복구 스크립트·비밀 백업은 포함하지 않았다.

## 어려움과 해결 시도

이전 일반 명령 초기화 오류는 이번 Git 세션의 문서 읽기에서 재현되지 않았다. 새 worktree의 일반 git status는 LFS clean 필터가 공통 .git/lfs/tmp에 쓰기를 시도하다 Access is denied로 실패했다. 같은 실행에서 main 상태 조회는 성공했다. 복구 이후 .git 쓰기 보호와 초기화 장애를 구분하고 worktree의 Git 검증·커밋·push는 승인된 실제 사용자 실행으로 처리한다. .git 쓰기 권한을 완화하거나 전역 safe.directory를 변경하지 않았다. 기능 명세나 게임 개발로 범위를 확대하지 않았다.

## 검증

- 일반 실행에서 AGENTS.md, team.md와 git show dev:repository.md/status.md를 읽고 Git 상태를 확인했다. exit code 0, main checkout은 변경 파일 없이 유지됐다.
- origin/dev를 조회하고 기준 커밋에서 문서 worktree를 생성했다.
- 소유자 확인 결과 main .git과 새 worktree의 .git 파일은 샌드박스 계정 소유가 아니다. 소유자 식별자 자체는 로그에 기록하지 않았다.
- PM 로그와 Git 로그 06은 복사 직후 로컬 원본과 복사본의 SHA-256 일치를 확인했다. 공개 문서의 줄바꿈은 LF와 끝 개행 하나로 정규화하며, 본문 일치는 정규화 후 다시 확인한다.
- 문서 경로·공백과 민감 정보 패턴 검사 결과는 커밋 전 확인한다. 이 로그의 준비 단계 이후 수행한 결과는 PR 검증란과 PM 보고에 기록한다.
- 미실행: 복구 스크립트 재실행, 다른 채팅 9개의 명령 재검증, UE 빌드·런타임·네트워크 QA. 10개 채팅 성공은 PM의 복구·검증 기록이다.

## 결정과 학습

읽기 장애 복구와 보호된 Git 메타데이터 쓰기는 서로 다른 사항이다. 실제 사용자 소유권을 유지하면서 필요한 Git 명령에만 승인 절차를 사용한다. 공개 문서에는 원인·범위·검증을 기록하고 시스템의 원본 보안 자료는 제외된 로컬 백업에 둔다. 과거 Git 로그 06의 로컬 보관 안내는 당시 상태이며 이번 문서 PR에 통합한다.

## 인수인계

복구·병합 로그를 dev 대상 문서 PR로 제출한다. 최종 병합은 사용자가 결정한다. 전체 상태 문서의 오래된 PR #4 대기 문구와 역할 등록은 PM이 별도로 갱신한다. 원본 로컬 로그와 백업은 유지한다. PR 준비와 검증 결과를 PM에 보고한 뒤 다음 Git 요청을 대기한다.
