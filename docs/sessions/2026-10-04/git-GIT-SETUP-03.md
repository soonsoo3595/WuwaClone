# Git — GIT-SETUP / 03

- 날짜·시간: 2026-10-04 (Asia/Seoul)
- 역할 / 작업 ID: Git·GitHub 설정 / GIT-SETUP
- 브랜치 / 작업 공간: main (최초 커밋 전) / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 없음 / 최초 커밋 준비 중
- 관련 Issue / PR / 명세: docs/project/repository.md

## 목표와 수행 내용

사용자가 공개 저장소 소유자 soonsoo3595, 이름 WuwaClone, 커밋 작성자 본인 계정을 지정했다. GitHub 공식 API에서 계정 이름 Jaehoon과 ID 86000058을 확인하고 로컬 저장소 작성자를 Jaehoon / 86000058+soonsoo3595@users.noreply.github.com으로 설정했다. 사용자 기기 인증으로 soonsoo3595 로그인이 완료됐다. 공식 GitHub CLI 2.102.0을 임시 폴더에 준비했다.

Config/DefaultEngine.ini의 Android File Server 연결 토큰을 공개 파일에서 제거했다. 변경 전 설정은 제외된 Saved/GitSetup/DefaultEngine-before-public.ini에 백업했다. 토큰 값은 로그에 기록하지 않는다. git lfs install --local을 실행했다.

사용자는 커밋 메시지를 `태그 | 작업 내용`으로 지정했다. Feat, Fix, Debug, Refactoring, Import 의미를 유지하고 Docs, Test, Build, CI, Chore, Style, Remove를 추가했다. repository.md와 AGENTS.md에 규칙을 반영했다.

## 어려움과 해결 시도

일반 명령 실행은 Windows 샌드박스 초기화 오류로 계속 실패했다. 사용자 승인으로 별도 실행에서 작업했다. Git 저장소 소유자 차이에는 이 경로에 한한 명령별 safe.directory 옵션을 사용했다.

## 검증

- GitHub CLI 기기 인증 성공: soonsoo3595.
- git check-ignore: Assets/의 루트·중첩 파일, Saved/ 백업, Binaries/, Intermediate/, .env, 플러그인 Binaries/ 제외 확인.
- git check-attr: 대표 .uasset와 .umap의 filter/diff/merge=lfs, text=unset 확인.
- 공개 텍스트 후보의 자격 증명 패턴 검사: 의심 파일 0개. 바이너리 내부 비밀 검사는 하지 않았으며 전체 비밀 부재를 보장하는 검사로 취급하지 않는다.
- 당시 후보 859개, .uasset/.umap 753개, 약 134.42MiB.
- 실제 LFS 포인터, 최초 커밋, push·재다운로드 및 UE 실행은 아직 미검증이다.

## 결정과 학습

Fix는 기능 수정, Debug는 버그 수정으로 구분한다. 공개 이메일 대신 GitHub noreply 이메일로 계정에 연결되는 커밋을 작성한다. 소스 코드 라이선스는 아직 정하지 않는다.

## 인수인계

다음 작업은 LFS 포인터 검증, 최초 커밋, 공개 저장소 생성·main/dev 업로드, 가능한 Issues/Projects 초기 설정과 결과 기록이다. UE CI 구현과 배포는 별도 작업으로 유지한다.
