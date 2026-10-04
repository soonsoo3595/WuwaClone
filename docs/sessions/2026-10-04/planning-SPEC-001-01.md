# 기획 — SPEC-001 / 01

- 날짜·시간: 2026-10-04 16:36 (Asia/Seoul)
- 역할 / 작업 ID: 기획 / SPEC-001
- 브랜치 / 작업 공간: docs/1-controls-spec / C:/Unreal Projects/WuwaClone/Saved/GitSetup/controls-spec-worktree
- 기준 커밋 / 결과 커밋: 12a06a20b875a8ff0591e5aa381759431523d861 / 없음
- 관련 Issue / PR / 명세: Issue #1 / PR 없음 / docs/specs/SPEC-001-controls.md

## 목표와 수행 내용

- PM 배정 범위인 걷기·달리기·점프·3인칭 카메라의 핵심 질문 5개를 사용자 입력으로 제시했다.
- 추천안은 미확정으로 표시했고 사용자 답변은 아직 없다.
- Git 담당이 제공한 dev 기반 작업 공간에서 초안을 작성했다. 로컬 동작과 서버 이동 동기화 확인 항목을 구분했다.
- 공격·전투·수집·로그인 구현과 공통 상태 문서 수정은 하지 않았다.

## 어려움과 해결 시도

- 웹 도구의 Issue #1 조회는 Cache miss로 실패했다. Git 담당이 GitHub CLI로 조회한 본문을 전달해 범위와 완료 조건을 확인했다.
- 작업 공간에서 git status --short --branch 실행 시 공통 .git/lfs/tmp 파일 생성에 Access is denied 오류가 발생하고 LFS clean filter가 실패했다. 오류 원인은 아직 검증하지 않았다. Git 담당에게 조사 요청하며 별도 승인·ACL 변경·설정 우회는 하지 않는다.

## 검증

- 실행: git show dev:docs/project/team.md, repository.md, status.md와 git ls-tree로 기존 명세 경로 확인. 명령 성공, 기존 docs/specs·docs/roles 파일 출력 없음.
- 읽기: 작업 공간의 AGENTS.md, 운영 문서, docs/sessions/TEMPLATE.md. 초기 운영 합의는 확인했고 이후 재읽기 일부 출력은 잘렸다.
- 실행 실패: 작업 공간 git status --short --branch의 LFS clean filter 오류. 전체 작업 트리 clean 상태는 기획 채팅에서 재검증하지 못했다.
- rg --files -g AGENTS.md docs는 일치 파일 없이 종료 코드 1이었다.
- 작성 문서를 Get-Content로 읽고 미확정 표기와 구현 완료 주장 여부를 확인했다. UE 빌드·런타임·Android·서버 네트워크 검증은 실행하지 않았다.
- Git 담당 조사 후 git status --short --branch -- docs와 git diff --check -- docs를 직접 실행해 모두 종료 코드 0을 확인했다. 새 명세 디렉터리와 세션 로그는 untracked로 표시됐다. diff --check는 untracked 본문을 검사하지 않으므로 신규 문서 본문 검증으로 취급하지 않는다.

## 결정과 학습

- 확정한 조작 규칙 없음. 추천안을 사용자가 수락한 것으로 해석하지 않는다.
- 입력·움직임 규칙과 조정 수치는 구분하고, 네트워크 허용 오차·시간·환경 조건도 후속 검토 대상으로 둔다.
- Issue #1의 명세 완료와 기능 구현 완료를 구분한다.

## 인수인계

- 사용자 답변 이후 초안을 갱신한다.
- PM에 질문·초안 준비와 답변 대기를 보고한다.
- Git 담당에게 LFS 오류를 보고했다. 조사 결과에 따르면 일반 샌드박스의 공통 .git 쓰기 보호가 LFS clean 임시 파일 작성을 차단한 상황이며 초기화 실패 재발과 구분된다. 어떤 파일 상태 차이가 clean을 유발했는지와 바이너리 변경 여부는 미검증이다. 문서 작업은 docs 범위의 상태 조회를 사용한다.
- 커밋·push·PR·병합은 아직 요청하지 않는다.
