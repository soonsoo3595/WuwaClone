# 현재 상태

최종 갱신: 2026-10-04 (Asia/Seoul), 담당: PM

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

## 적용 상태

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

1. GitHub 저장소 주소 또는 소유자·이름 확인과 연결 방법 확보.
2. 커밋 작성자 설정 확인, 공개 대상 파일·외부 에셋 검토 후 최초 커밋과 dev 생성.
3. remote 연결·공개 업로드, Issues/Projects와 브랜치 검사 규칙 적용.
4. 나머지 역할별 지침·채팅 구성, 조작 명세, 개발/빌드 재현 절차 작성.

제안했던 ASP.NET Core 세부 구조, Google 우선 도입, 계정 정책 및 runner 배치는 아직 최종 확정으로 취급하지 않는다.
