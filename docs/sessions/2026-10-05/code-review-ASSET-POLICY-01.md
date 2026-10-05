# 코드 리뷰 — ASSET-POLICY / 01

- 날짜·시간: 2026-10-05 14:39 (Asia/Seoul)
- 역할 / 작업 ID: 코드 리뷰 / ASSET-POLICY
- 브랜치 / 작업 공간: 루트 main에서 Git 객체를 읽고, assets-policy-worktree의 원본을 읽기 전용으로 대조. 별도 checkout 전환·worktree 생성 없음. 이 리뷰 로그만 작성.
- 기준 커밋 / 결과 커밋: dev 1fa3f5f3ef97624c6631033868efc1b12d9f8cb3 / 검토 head f553ffdff36104d7d6c705b1244b87d3c58e8c2d. 리뷰 커밋 없음.
- 관련 Issue / PR / 명세: PR #10 https://github.com/soonsoo3595/WuwaClone/pull/10 ; 통합 비교 PR #9 head 247077b05cff8e7070d2a05e1d0cab4e75c86959 ; 사용자 최종 지정 Content/Assets/ 및 Content/TripoModels/만 추가 공개 제외.

## 목표와 수행 내용

- AGENTS.md, team.md, dev의 repository.md/status.md, 세션 템플릿을 읽었다.
- PR #10의 GitHub 메타데이터와 로컬 head 일치를 확인하고 전체 변경 범위, ignore 규칙, LFS 규칙, 정책 설명과 로컬 원본을 검토했다.
- PR #9는 공통 .gitignore 통합 범위만 검토했다. 해당 PR의 플러그인 설정 전체에 대한 승인이나 실행 검증은 아니다.
- 구현·정책 파일 수정, 브랜치 전환, merge, commit, push, 역사 재작성은 수행하지 않았다.

## 어려움과 해결 시도

- 루트는 main이며 .gitignore 및 Config 두 파일에 기존 미커밋 변경이 있다. 이를 수정하지 않고 고정 커밋의 git show/diff/ls-tree로 검토했다.
- assets-policy-worktree의 status에는 .gitattributes 수정 표시가 있었다. git diff에는 내용 변경 없이 LF/CRLF 경고만 나왔다. 리뷰 기준은 고정 head이며 해당 작업 트리의 상태를 정리하지 않았다.
- git merge-tree의 전통적인 3인자 읽기 방식으로 두 순서의 통합을 확인했다. 이 명령의 종료 코드만으로 충돌 여부를 판단하지 않고 충돌 마커와 changed in both 출력을 확인했다.

## 검증

실제 수행한 검증:

- GitHub get_pr_info #10/#9: 두 PR 모두 open, base dev 1fa3f5f, 각각 지정한 head 확인. 각 PR이 현재 dev와 mergeable인 것과 두 PR 사이 충돌은 구분한다.
- git diff --name-only --diff-filter=D 1fa3f5f f553ffd: 삭제 95개, 지정 경로 밖 삭제 0개. 모두 Content/Assets/이며 TripoModels는 기존 추적 파일 없음.
- git ls-tree -r로 기준의 지정 폴더 밖 Content와 head Content를 Compare-Object: 658개, 경로·모드·blob 차이 0개.
- 삭제 경로별 git show 1fa3f5f:<경로>의 LFS oid와 assets-policy-worktree 실제 파일 Get-FileHash SHA256 대조: 95/95 일치, 누락·불일치 0개. 현재 원본과 기준 LFS 내용의 일치이며 작업 전후 해시 기록 자체를 독립 재현한 것은 아니다.
- git diff --name-status 1fa3f5f f553ffd: 콘텐츠 삭제 외 .gitignore, docs/project/assets.md, 새 Git 작업 로그만 변경. .gitattributes, Source, Config, uproject 변경 없음.
- git check-ignore -v --no-index: Content/Assets 및 Content/TripoModels 테스트 경로에 각각 .gitignore 7/8행 적용. Characters, __ExternalActors__, __ExternalObjects__ 테스트 경로는 제외되지 않음.
- git check-attr --source=f553ffd filter: Characters의 .uasset 및 ThirdPerson의 .umap에 lfs 유지. .gitattributes blob은 변경 없음.
- git diff --check 1fa3f5f f553ffd: 종료 코드 0.
- git merge-tree 1fa3f5f 247077b f553ffd 및 역순: .gitignore의 동일 삽입 위치에서 충돌. 다른 changed in both 항목 없음. checkout/index/refs를 변경하지 않음.
- 고정 head DefaultEngine.ini의 기본 맵/게임 모드는 /Game/ThirdPerson 경로. 삭제 폴더를 직접 기본 경로로 지정하지 않지만 바이너리 내부 의존성의 무결성을 보장하는 검증은 아니다.

미검증:

- 외부 개인 백업의 존재·완전성, 새 checkout에서 실제 복원, 브랜치 전환 시 원본 보존.
- UE Asset Registry/Reference Viewer를 통한 남은 애셋의 삭제 경로 참조, 외부 액터·오브젝트 연결, 빌드·실행·패키징·네트워크 QA.
- 과거 Git/원격 LFS 삭제 여부의 원격 전수 검사. 이번 PR이 과거 이력을 제거하지 않는다는 커밋 구조와 문서 설명은 확인했다.

## 결정과 학습

### 병합을 막는 개별 변경 결함

검토 head의 지정 경로 제외·삭제 범위·원본 보존에 확인된 결함 없음. 이는 UE 실행 승인이나 사용자 최종 병합 승인이 아니다.

### 통합 전 해결할 사항

- .gitignore 6~8행과 PR #9의 동일 삽입 위치가 충돌한다. 어느 PR을 먼저 병합하든 후속 PR에서 충돌을 해결해야 한다. 최종 규칙은 기존 /Assets/ 및 /Content/Assets/, /Content/TripoModels/, /Plugins/Tripo3DUEBridge-UE5.8-Win64/를 함께 보존하고 나머지 ignore/LFS 규칙을 유지한다. 한쪽 전체 선택은 다른 정책을 잃는다.
- 정책 PR #10을 먼저 통합하고 PR #9를 갱신하는 순서를 권장한다. 반대 순서도 가능하며 순서만 바꾸어 충돌이 없어지는 것은 아니다. 통합 결과의 diff/check-ignore를 다시 검증한다. 실제 병합은 사용자 결정.
- 루트와 다른 기존 checkout을 갱신하기 전 외부 백업의 파일 수·해시를 검증해야 한다. git rm --cached가 한 worktree에 원본을 남겼다는 사실만으로 다른 checkout의 삭제를 막지 못한다.

### 권장 개선 (병합 차단 아님)

- assets.md 9행의 Content로 가져오면 공개 대상이라는 일반 설명에 두 예외를 직접 표기하고 3행의 갱신일을 맞추면, 15행의 최신 예외를 읽지 않은 사람이 정책을 오해할 가능성을 줄인다. repository/status의 일반 설명도 PM 담당 문서 갱신 시 같은 예외를 연결할 수 있다. 최신 절이 최종 정책을 명시하므로 전체 Content 제외로 해석하지 않는다.
- Git 작업 로그 17행은 검증을 수행한다는 계획형 문장이다. 실행 명령, 95/658개 결과, 기준/head, 해시 확인과 미검증을 완료형으로 남기면 결과가 재검토 가능해진다. PR 본문 보고와 이 리뷰의 독립 검증은 별도 증거다.

### 학습 질문 (답변 대기, 리뷰 결론을 보류시키는 조건 아님)

1. .gitignore와 LFS 규칙을 모두 둬도 기존 추적 파일에 git rm --cached가 필요한 이유는 무엇인가?
2. 현재 worktree의 SHA256 일치만으로 다른 checkout의 브랜치 전환과 백업 복원까지 보장할 수 없는 이유는 무엇인가?
3. PR #9/#10 충돌을 한쪽 전체 선택으로 해결하면 어느 제외 규칙을 잃으며, 최종 규칙을 어떻게 확인할 것인가?

사용자 답변 없음. 답변을 받으면 근거와 대안을 설명한다.

## 인수인계

- PM에 고정 head 기준 검토 결과, 통합 충돌, 백업·UE 미검증, 문서 권장 개선을 전달한다.
- 담당 Git 세션에서 사용자 승인된 순서에 따라 후속 PR 충돌 해결 및 통합 결과 재검증. 리뷰 채팅에서 구현 변경을 대신 수행하지 않는다.
- 이 로그는 루트에만 작성했으며 자동으로 다른 worktree/PR에 공유되지 않는다. 문서 담당 세션에서 필요한 통합을 조율한다.
