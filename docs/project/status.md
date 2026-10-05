# 현재 상태

최종 갱신: 2026-10-04 (Asia/Seoul), Git 설정 결과 문서 / 최종 병합은 사용자 결정

## 확정

- 단독 개발, 언리얼 게임 서버 직군 포트폴리오가 핵심 목표.
- UE 5.8.2 소스 빌드, C++·C# 사용 경험.
- PC: Ryzen 7 7800X3D / RAM 32GB / Radeon RX 9070XT. Android: Galaxy Z Flip5.
- 첫 마일스톤: 걷기·달리기·점프·카메라 조작 → 데디케이티드 서버 이동 동기화 검증. 공격·전투는 이후 단계.
- 캐릭터 모델은 사용자가 지칭한 Trippo AI 서비스를 활용할 예정. Tripo AI로 해석했으며 정확한 서비스 식별은 확인 필요.
- 서드파티 로그인과 PC·Android 공통 계정을 사용한다. 제공자 선택은 아직 미확정.
- 개발 과정부터 공개하는 단일 저장소, Git LFS, GitHub Issues/Projects, GitHub Actions.
- 작업 브랜치 → dev → release → main 전략.
- PM과 코드 리뷰 채팅을 운영 중이며, 지정된 프로젝트 세션 사이 메시지 전달을 허용.
- 일정·예산을 필수 계획 항목으로 요구하지 않는다.

## 현재 적용 상태

- [공개 GitHub 저장소](https://github.com/soonsoo3595/WuwaClone)를 생성하고 origin으로 연결했다. 최초 커밋은 d533fb5이며 main/dev에 업로드했다. 초기 업로드 당시 두 상설 브랜치는 해당 커밋을 가리켰다. 이후 dev의 문서·구현 PR 반영은 별도 진행한다.
- 최초 커밋 제목은 `Chore | 초기 프로젝트와 Git 운영 설정 추가`다. 이후 커밋도 `태그 | 작업 내용`을 사용하며 Fix는 기능 수정, Debug는 버그 수정으로 구분한다. 전체 태그는 repository.md를 따른다.
- GitHub 계정 soonsoo3595로 인증했다. 커밋 작성자는 Jaehoon과 계정의 noreply 이메일을 사용한다. Git·LFS는 Codex 번들, gh 2.102.0은 임시 폴더에서 실행했다.
- 기본 브랜치는 main이다. main/dev 모두 PR, 리뷰 대화 해결, 강제 push·브랜치 삭제 금지 보호를 적용했다. 관리자도 보호 대상이다. 단독 개발이므로 별도 승인자 수는 0이며 필수 CI 검사는 아직 없다. 최종 병합은 사용자 결정이다.
- squash merge와 merge commit을 허용하고 rebase merge는 비활성화했다. dev 기능 PR은 squash, release/hotfix 반영은 merge commit을 사용한다. squash 기본 제목은 PR 제목이므로 PR 제목도 커밋 메시지 형식을 사용한다.
- 현재 UE 에셋은 모두 기본 템플릿이라고 사용자가 확인했다. 에셋 출처·공개 정책은 [assets.md](assets.md)에 기록했다. 공개하지 않을 에셋의 Content/Assets/와 Content/TripoModels/는 Git에서 제외한다. 다른 Content의 .uasset/.umap는 LFS 대상이다. 루트 Assets/ 제외는 사용자 정정으로 폐기했고 복원 PR #11은 미병합 폐쇄했다.
- UE 바이너리 에셋 753개, 약 134.42MiB를 LFS로 업로드했다. 스테이징된 에셋의 포인터 형식을 검사했고 로컬 LFS 무결성 검사도 통과했다. 새 clone에서 LFS 재다운로드와 무결성 검사까지 통과했다.
- 초기 설정 당시 Assets/, Saved/ 백업, 빌드 산출물, .env와 플러그인 빌드 산출물 제외를 명령으로 확인했다. 이 중 루트 Assets/ 정책은 폐기됐으며 현재는 Content/Assets/와 Content/TripoModels/를 제외한다. 공개 텍스트 후보의 비밀 정보 패턴 검사에서 의심 파일은 0개였다. 바이너리 내부의 비밀 정보 검사는 하지 않았다.
- Config/DefaultEngine.ini의 Android File Server 연결 토큰을 공개 설정에서 제거했다. 변경 전 설정은 로컬 Saved/GitSetup/DefaultEngine-before-public.ini에만 보관한다. Android File Server를 사용하는 경우 로컬 연결 설정을 별도로 확인해야 한다.
- [GitHub Project](https://github.com/users/soonsoo3595/projects/6)는 공개이며 저장소에 연결했다. Status는 Backlog → Ready → In Progress → Review → Done이다. 초기 Issues 3개를 Backlog에 등록했다.
- 초기 Issues: [조작 명세 확정 #1](https://github.com/soonsoo3595/WuwaClone/issues/1), [빌드·실행 재현 절차 #2](https://github.com/soonsoo3595/WuwaClone/issues/2), [이동·카메라와 서버 이동 동기화 #3](https://github.com/soonsoo3595/WuwaClone/issues/3). #3은 선행 작업 때문에 blocked로 표시했다.
- UE 빌드·런타임·네트워크 QA, 실제 GitHub Actions 워크플로·runner·배포는 아직 수행하거나 구현하지 않았다. 코드 라이선스도 아직 정하지 않았다.
- 결과 문서는 dev 기반 docs/GIT-SETUP-results 브랜치에서 PR로 제출한다. 이 문서 PR의 사용자 병합은 GitHub 설정·첫 업로드 완료와 별개다.

## 초기 설정 기록 (과거 상태)

아래 기록은 최초 설정 중 관찰한 상태이며 위의 현재 적용 상태로 갱신됐다. 이전 오류와 미완료 항목의 상세 경과는 세션 로그를 참고한다.

- 로컬 Git 저장소를 main 초기 브랜치로 초기화했다. 최초 커밋과 dev 생성은 아직 하지 않았다.
- .gitignore, .gitattributes, AGENTS.md, README, 작업/PR 양식, 세션 로그 양식을 준비했다.
- 공개 GitHub remote, Issues/Projects, 브랜치 보호, CI/CD는 아직 적용하지 않았다.
- Git과 Git LFS는 사용 가능하다. GitHub CLI 2.102.0을 임시 폴더에 준비하고 soonsoo3595 계정의 기기 인증을 완료했다.
- 사용자가 공개 커밋 작성자를 본인 계정으로 지정했다. 로컬 저장소 작성자는 Jaehoon과 GitHub 계정의 noreply 이메일로 설정했다.

### Git 담당 재확인 (2026-10-04)

- Codex 번들의 Git 2.53.0.windows.3과 Git LFS 3.7.1을 확인했다. 사용자 계정의 Git 작성자 설정은 존재하지만 공개 커밋용으로 아직 확정하지 않았다.
- main은 최초 커밋 전 상태이며 remote는 없다. 공개 저장소 소유자·이름과 작성자 정보를 사용자에게 요청했다. GitHub 인증은 미확인이다.
- 추적 후보 856개 중 UE 바이너리 에셋은 753개다. 에셋 출처를 사용자에게 요청했고 LFS 포인터 및 업로드 검증은 아직 수행하지 않았다.
- Config/DefaultEngine.ini의 Android File Server 연결 토큰을 제거했다. 변경 전 설정은 제외된 Saved/GitSetup/DefaultEngine-before-public.ini에 백업했으며 값은 상태 문서와 로그에 기록하지 않는다.
- Windows 샌드박스 초기화 오류로 일반 명령 실행이 막혔다. 승인된 별도 실행으로 초기 검사를 수행했지만 추가 검사 승인은 거절되어 실행하지 않았다.
- 세부 기록: [Git 설정 1회차](../sessions/2026-10-04/git-GIT-SETUP-01.md).
- 사용자는 현재 에셋이 모두 UE 기본 템플릿이라고 확인했다. 공개하지 않을 에셋의 로컬 보관 경로를 루트 Assets/로 정했고 .gitignore에 /Assets/ 제외 규칙을 추가했다. Content/의 LFS 규칙은 유지한다. 에셋 업로드와 LFS 포인터 검증은 아직 수행하지 않았다.
- 공개 저장소 대상은 soonsoo3595/WuwaClone으로 확정했다. 기기 인증, 로컬 LFS 설치, Assets/·백업·빌드 산출물 제외, 대표 UE 바이너리의 LFS 속성을 검증했다. 공개 텍스트 후보의 비밀 정보 패턴 검사에서 의심 파일은 0개였다. 실제 업로드와 LFS 포인터 검증은 아직 미완료다.
- 커밋 메시지는 사용자 지정 `태그 | 작업 내용`으로 통일했다. 태그 목록과 예시는 repository.md를 따른다.

## 다음 작업

1. Git 설정 결과 문서 PR을 검토하고 사용자가 dev 병합 여부를 결정한다.
2. 초기 Issues의 조작 명세와 정확한 엔진 버전·소스 커밋·빌드 재현 절차를 확정한다.
3. 나머지 역할별 지침·채팅 구성과 코드 리뷰·QA를 준비한다.
4. UE runner와 실제 GitHub Actions 검사·배포는 별도 작업으로 구현한다. 구현하지 않은 검사는 필수 조건으로 걸지 않는다.

제안했던 ASP.NET Core 세부 구조, Google 우선 도입, 계정 정책 및 runner 배치는 아직 최종 확정으로 취급하지 않는다.
