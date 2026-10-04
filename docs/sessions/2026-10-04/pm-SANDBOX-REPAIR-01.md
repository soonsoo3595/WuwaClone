# PM — SANDBOX-REPAIR / 01

- 날짜: 2026-10-04 (Asia/Seoul)
- 목표: 모든 역할 채팅의 운영 문서 읽기 실패 복구.
- 작업 공간: 시스템 권한 복구. 프로젝트 코드·checkout·커밋은 변경하지 않음.

## 원인과 수행

일반 exec_command에서 helper_unknown_error: setup refresh had errors 재현.
날짜별 sandbox 로그에서 .git의 deny ACE 적용을 위한 ACL 대상 열기 실패를 확인.
.git 소유자는 CodexSandboxOffline이며 실제 사용자는 ACL 관리 권한이 없었음.
Saved/SandboxRepair에 ACL 백업과 범위를 검증하는 복구 스크립트를 준비.
사용자 승인과 Windows 관리자 승인 후 .git 및 하위 항목의 소유권을 실제 사용자에게 복원하고 해당 사용자 FullControl을 부여.
기존 ACL·sandbox 보호 규칙은 보존. sandbox 설정이나 전역 safe.directory를 변경하지 않음.
복구 result.json success=true. 이후 일반 sandbox setup refresh와 문서 읽기 성공.

## 검증

PM: Get-Content docs/project/team.md; git show dev:docs/project/repository.md; git show dev:docs/project/status.md; git status --short — exit 0, 변경 파일 없음.
기획·기술 설계·언리얼 개발·캐릭터/애니메이션·백엔드/DB·인프라/배포·QA·코드 리뷰·Git의 최근 실제 명령 기록에서 일반 문서 읽기 exit 0 확인.
모든 세션에 최신 dev 문서를 checkout 변경 없이 git show로 읽도록 안내.
Git·코드 리뷰·QA·인프라·백엔드·캐릭터·언리얼 담당의 성공 보고도 수신.
기획·기술 설계까지 포함한 9개 담당 채팅 모두 최종 성공 메시지를 수신함. PM을 포함한 10개 채팅의 일반 읽기 실행을 확인함.
읽기와 초기화 복구를 검증했으며 게임 빌드·런타임·네트워크 검증은 이번 범위가 아님.

## 인수인계

새 .git/worktree를 일반 사용자 소유로 생성하고 sandbox 권한 관리가 가능한 상태를 유지.
실패 재발 시 sandbox 날짜별 로그와 해당 경로의 ACL을 확인.
복구 원본 로그·ACL 백업은 로컬 Saved/SandboxRepair에 보관. 공개 로그에는 SID나 원본 전체를 포함하지 않음.
이 PM 로그는 Git 담당이 dev 기반 문서 작업 공간의 docs/sessions/2026-10-04/pm-SANDBOX-REPAIR-01.md로 통합할 수 있도록 로컬에 보관.
운영 문서에는 역할 채팅 미생성, PR #4 병합 대기 등 오래된 문구가 남아 있으므로 별도 PM 상태 갱신이 필요.
