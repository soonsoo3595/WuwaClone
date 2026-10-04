# Git — GIT-SETUP / 04

- 날짜·시간: 2026-10-04 (Asia/Seoul)
- 역할 / 작업 ID: Git·GitHub 설정 / GIT-SETUP
- 브랜치 / 작업 공간: docs/GIT-SETUP-results / Saved/GitSetup/results-worktree
- 기준 커밋: d533fb5e1301d81fe4cf38e9dfd7f45d392a41e0 (main/dev 최초 커밋)
- 관련 명세: docs/project/repository.md
- 저장소: https://github.com/soonsoo3595/WuwaClone
- Project: https://github.com/users/soonsoo3595/projects/6

## 목표와 수행 내용

공개 GitHub 저장소를 생성하고 origin으로 연결했다. `Chore | 초기 프로젝트와 Git 운영 설정 추가`로 최초 커밋을 작성하고 main/dev를 업로드했다. 커밋 작성자는 사용자 GitHub 계정의 이름과 noreply 이메일이다.

공개 Project를 생성·저장소에 연결하고 Status를 Backlog → Ready → In Progress → Review → Done으로 설정했다. 처음에는 project 권한이 부족해 사용자의 추가 기기 인증으로 권한을 확보했다. Issues #1 조작 명세, #2 빌드·실행 절차, #3 이동·카메라와 서버 이동 동기화 검증을 생성하고 Backlog에 연결했다. #3에는 blocked와 선행 작업을 기록했다. 다른 기존 Projects는 변경하지 않았다.

main/dev에 PR, 리뷰 대화 해결, 관리자 적용, 강제 push·삭제 금지 보호를 적용했다. 승인자 수 0과 필수 CI 없음으로 단독 개발을 막지 않는다. squash와 merge commit을 허용하고 rebase merge를 비활성화했다. 기능과 release/hotfix의 병합 방식은 운영 지침에 따라 선택한다. 실제 병합은 하지 않았다.

완료 상태 문서와 README·운영 문서를 dev 기반 결과 브랜치에 기록하고 PR로 제출한다. 사용자 최종 병합 결정은 남겨 둔다.

## 어려움과 해결 시도

Windows 샌드박스 초기화 오류 때문에 승인된 별도 실행을 사용했다. 앱 worktree 생성 도구는 Git is unavailable로 실패했다. 기존 Git CLI로 dev 기반 전용 worktree를 제외된 Saved/GitSetup 아래에 만들었다. 바이너리 에셋은 수정하지 않았다.

최초 전체 공백 검사는 기본 UE 템플릿의 기존 공백·들여쓰기 때문에 실패했다. 무관한 템플릿 서식을 수정하지 않고 새 운영 문서와 규칙 파일의 공백 검사를 별도로 실행해 통과했다.

## 검증

- 에셋 753개의 스테이징된 LFS 포인터 형식을 검사했다.
- 로컬 git lfs fsck 통과.
- 첫 push: LFS 753/753, 약 141MB 전송 완료. 원본 에셋 용량은 약 134.42MiB다.
- 새 clone에서 git lfs pull 및 git lfs fsck 통과. 검증 clone은 Saved/GitSetup/verify-clone에 둔다.
- git ls-remote로 main/dev가 모두 기준 커밋을 가리키는 것을 확인했다.
- GitHub API로 PUBLIC, 기본 브랜치 main, 두 브랜치 보호, 병합 설정을 확인했다.
- Project Status 5개와 초기 Issues 3개의 Backlog 상태를 API로 확인했다.
- 이전 회차에서 Assets/·빌드·로컬 백업 제외와 공개 텍스트 비밀 패턴 의심 파일 0개를 확인했다.
- 미실행: UE 빌드·실행·서버 이동 QA, 실제 CI/CD와 배포. 바이너리 내부 비밀 정보 검사는 수행하지 않았다.

## 결정과 학습

사용자 커밋 메시지 규칙을 초기 커밋부터 적용했다. Fix는 기능 수정, Debug는 버그 수정으로 구분한다. 최종 상태 기록은 보호된 브랜치에 직접 push하지 않고 문서 PR로 제출한다. 기본 템플릿 출처는 사용자 확인에 근거했고 외부 에셋 공개 조건은 별도 확인한다. 코드 라이선스를 임의로 정하지 않았다.

## 인수인계

저장소 생성·인증·연결·첫 업로드·LFS 검증·Issues/Projects·브랜치 보호는 완료됐다. 이 결과 문서 PR의 검토와 dev 병합은 사용자가 결정한다. 실제 UE CI와 조작 명세·재현 절차는 초기 Issues와 별도 작업으로 진행한다. 이전 PM 메시지 전달 요청은 사용자에게 거절됐으므로 이번 결과를 별도 메시지로 발송하지 않았다.
