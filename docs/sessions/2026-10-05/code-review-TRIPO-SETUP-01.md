# 코드 리뷰 — TRIPO-SETUP / 01

- 날짜·시간: 2026-10-05 15:10 (Asia/Seoul)
- 역할 / 작업 ID: 코드 리뷰 / TRIPO-SETUP
- 브랜치 / 작업 공간: main에서 로컬 Git 객체와 GitHub 고정 SHA 파일을 읽기 전용 검토. checkout·refs·다른 worktree 변경 없음. 이 로그만 작성.
- 기준 커밋 / 결과 커밋: PR base f784c3d38a0e2f0cfbddca22f284f6a29188be33 / 최신 head 3044ed1281fc6c008e612361a725751081b7958b. 기존 head 247077b05cff8e7070d2a05e1d0cab4e75c86959와 비교. 이미 병합된 결과 669eb13727bc7cf6d59d30e5d05f9e5055cccfae도 확인.
- 관련 Issue / PR / 명세: Issue #8, PR #9 https://github.com/soonsoo3595/WuwaClone/pull/9 ; PR #10의 두 콘텐츠 경로 제외 및 기존 /Assets/ 유지.

## 목표와 수행 내용

- 운영 지침과 dev의 repository/status, 로그 템플릿을 읽었다. 로컬 dev가 최신 원격 상태를 반영한다고 가정하지 않았다.
- GitHub 최신 PR 메타데이터와 diff, 고정 head/병합 커밋의 네 변경 파일을 읽었다.
- 요청에는 아직 최종 승인이 없다고 되어 있으나 실제 조회는 merged=true, 병합 시각 2026-10-05 15:06:21 KST였다. 사실을 PM에 즉시 전달했고 승인 여부나 병합 주체를 추정하지 않았다. 리뷰 채팅에서 병합을 수행하지 않았다.
- 로컬 최신 head/병합 Git 객체가 없어 git cat-file이 실패했다. git fetch나 checkout 갱신 대신 GitHub 읽기 API로 고정 SHA의 내용을 확인했다.

## 어려움과 해결 시도

- get_pr_diff 첫 호출의 repository_full_name 인자가 스키마와 맞지 않았다. 요구된 repo_full_name으로 재호출해 성공했다.
- 로컬 엔진 위치는 기존 sln의 상대 경로로 확인했다. 최초 UBT descriptor 경로 추정은 존재하지 않아 실패했으며 실제 UEBuildTarget와 C++ descriptor/PluginManager의 처리부로 검증했다.
- 기존 루트 .gitignore와 Config 두 파일의 미커밋 상태는 그대로 두었다. 고정 원격 파일을 현재 루트 파일과 혼동하지 않았다.

## 검증

- GitHub get_pr_info: head 3044ed1, base f784c3d, merged=true, merge 669eb13, changed_files=4 확인.
- GitHub get_pr_diff: .gitignore, WuwaClone.uproject, runbook, Git 작업 로그만 변경. 콘텐츠·배포본·Config·LFS 규칙 변경 없음.
- head와 병합 커밋의 네 파일 fetch_file: 각각 blob SHA 동일. 따라서 발견된 ignore 회귀가 병합 결과에도 존재한다.
- 최신 JSON을 JSON.parse: Tripo3DUEBridge Enabled=true, Optional=true, TargetAllowList=[Editor] 확인. 이전 head의 설정·문서 blob과 동일하며 사용자 충돌 해결은 ignore 내용을 바꿨다.
- .gitignore 전체 읽기: Content/Assets, Content/TripoModels, Plugins/Tripo3DUEBridge-UE5.8-Win64는 정확한 루트 고정 경로로 유지. /Assets/는 사라졌고 이를 대신할 일반 Assets 규칙도 없다. PR diff에 -/Assets/가 나타난다. 충돌 마커 없음.
- 로컬 Tripo3DUEBridge.uplugin: VersionName 1.0.5, EngineVersion 5.8.0, Win64, 모듈 Type=Editor 확인. 프로젝트 설정 이름과 일치한다. 이 로컬 배포본이 공개 PR에 포함됐다는 뜻은 아니다.
- 로컬 UE 소스 읽기: PluginReferenceDescriptor.cpp 64~81행의 타깃 허용 목록, 144/161행의 JSON 필드 파싱; UEBuildTarget.cs 5837행의 타깃 필터와 5877행의 없는 optional 플러그인 무시; PluginManager.cpp 2425행 타깃 필터와 2478행 없는 optional 플러그인 무시 확인.
- Epic 공식 FPluginReferenceDescriptor API 문서도 Optional/TargetAllowList 의미와 일치: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Projects/FPluginReferenceDescriptor . 실제 프로젝트 실행 성공으로 확대 해석하지 않는다.

미검증:

- 최신 head가 로컬 Git에 없으므로 최신 head의 git diff --check 및 git check-ignore를 실행하지 않았다. 원격 diff와 전체 규칙을 읽은 정적 검토이며 이전 head의 결과를 최신 head 실행 결과로 대체하지 않는다.
- 플러그인 미설치/설치 상태의 Editor 시작·빌드, Game/Server/Android 빌드·패키징, 모델 전송, 생성 콘텐츠의 플러그인 의존성.
- 공개 배포 조건에 대한 독립 법률 검토. 문서의 허용 근거 미확인과 업로드 보류를 재배포 금지 확정으로 해석하지 않는다.
- 공개 후보 시크릿 패턴 검사를 최신 head 전체에 재실행하지 않았다. Config가 diff에 없다는 확인과 별개다.
- 루트 Assets의 실제 파일이 원격에 추가됐다는 증거는 발견하거나 검사하지 않았다. 확인된 문제는 제외 규칙 상실이다.

## 결정과 학습

### 차단 결함 — [P2] 루트 Assets 제외 규칙 회귀

- 위치: 최신 head 및 병합 결과의 .gitignore 3~8행. 기준의 4행 /Assets/ 삭제.
- 조건: 루트 Assets 아래 로컬 전용 파일을 두고 git add . 등의 정상 스테이징을 수행할 때.
- 영향: 일반 시크릿/산출물 패턴에 해당하지 않는 파일이 공개 후보가 된다. 기존 로컬 전용 정책과 요청한 네 제외 경로 보존 조건을 위반한다. 원격 유출이 이미 일어났다고 단정하지 않는다.
- 개선 방향: 후속 변경에서 /Assets/를 복원하고 나머지 세 경로를 유지한다. 실제 통합된 최신 기준으로 네 경로의 check-ignore, 정상 Content 유지, diff --check를 다시 수행한다. 이미 병합됐으므로 병합 대기 안내 대신 사용자 결정에 따른 후속 수정 PR로 처리한다. 리뷰 채팅에서는 수정하지 않는다.

### 설정·문서 판단

- Optional과 Editor 타깃 제한은 별도 설치·비필수 에디터 도구라는 목적에 맞는다. Optional은 플러그인이 없는 상황을 처리하며 설치된 플러그인의 컴파일 오류나 버전 불일치를 무시한다는 보장은 없다.
- runbook 5/7행의 배포본 제외, 설치 필요, 실행 미검증 구분은 합리적이다. 정확한 설치 폴더만 제외하므로 버전·폴더 변경 시 재확인하라는 14행 안내도 필요하다.
- Git 작업 로그의 검증은 계획형 문장이고 이전 기준 커밋을 적는다. 최신 충돌 해결 결과·현재 병합 상태·실제 검증 명령을 별도 로그에 보완할 것을 권장한다. 실행하지 않은 QA를 추가 통과로 기록해서는 안 된다.

### 학습 질문 (사용자 답변 대기)

1. 텍스트 충돌이 없어졌다는 것과 기존 네 제외 정책이 모두 유지됐다는 것을 어떤 검증으로 구분할 것인가?
2. Optional은 미설치와 설치됐지만 빌드가 실패하는 상황을 각각 어떻게 처리하며, 어떤 테스트가 필요한가?
3. 공개 제외한 플러그인이나 생성 모델이 있는 환경과 없는 새 checkout에서 재현 가능한 기능 범위를 어떻게 설명할 것인가?

## 인수인계

- PM에 최신 head/이미 병합된 사실, /Assets/ 누락 차단 결함, 나머지 세 규칙 및 설정 판단, 검증·미검증을 전달한다.
- 사용자 작업을 임의로 되돌리거나 수정하지 않는다. PM/담당 개발 세션이 후속 수정 범위와 사용자 최종 결정을 조율한다.
- 로그는 루트에만 작성했다. 다른 worktree 또는 PR에 자동 공유되지 않으므로 통합은 담당 세션과 조율한다.
