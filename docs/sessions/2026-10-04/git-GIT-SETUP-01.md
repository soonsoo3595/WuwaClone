# Git — GIT-SETUP / 01

- 날짜·시간: 2026-10-04 (Asia/Seoul)
- 역할 / 작업 ID: Git·GitHub 설정 / GIT-SETUP
- 브랜치 / 작업 공간: main (unborn) / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 없음 / 없음
- 관련 Issue / PR / 명세: docs/project/repository.md

## 목표와 수행 내용

공개 GitHub 저장소 생성과 최초 업로드를 요청받았다. AGENTS.md와 프로젝트 운영·저장소·상태 문서를 읽었다. Git 2.53.0.windows.3과 Git LFS 3.7.1이 Codex 번들에서 실행된다. gh는 PATH와 확인한 일반 설치 경로에서 발견하지 못했다. main에는 아직 커밋이 없고 remote도 없다. GitHub 인증은 아직 확인하지 못했다.

현재 추적 후보는 856개이며 .uasset 749개, .umap 4개다. .gitattributes에 이 두 확장자의 LFS 규칙이 있다. 실제 인덱스 포인터·업로드·재다운로드 검증은 하지 않았다. 현재 사용자 Git 설정에서 작성자 이름·이메일은 발견했지만 공개 커밋 작성자로 확정하지 않았다. 계정·저장소명·작성자 정보와 에셋 출처를 사용자에게 요청했다.

## 어려움과 해결 시도

일반 명령과 Node 도구가 Windows 샌드박스 초기화 오류로 실행되지 않았다. 승인된 별도 실행에서 문서를 읽었다. 저장소 소유자가 샌드박스 계정이라 사용자 계정의 Git 명령이 dubious ownership으로 차단됐다. 이후 이 프로젝트에 한해 명령별 -c safe.directory 옵션을 사용해 읽기 검사를 했다. 전역 safe.directory는 바꾸지 않았다.

추가 읽기 검사에 대한 별도 실행 승인이 거절되어 해당 검사를 실행하지 않았다.

## 검증

- 실행: Git·LFS 버전, Git 상태·remote·추적 후보, .gitignore·.gitattributes·Issue/PR 양식 읽기.
- 설정 파일 검사 중 Config/DefaultEngine.ini의 Android File Server SecurityToken 값이 출력에 노출됐다. 값을 이 로그에 재기록하지 않는다. 공개 전 제거와 로컬 보관이 필요하며 아직 수행하지 않았다.
- Epic 공식 EULA의 템플릿 Examples 공유 조건을 조사했다. 로컬 에셋 출처 확인은 아직 완료하지 못했다.
- 미실행: LFS 속성 명령 검증, 용량 집계, 전체 비밀 정보 검사, 최초 커밋, dev 생성, 원격 생성·인증·push, Issues/Projects·브랜치 보호 설정, UE 빌드·런타임 검증.

## 결정과 학습

작성자·라이선스·공개 저장소 소유자를 임의로 정하지 않는다. 기존 Variant_Combat 소스와 에셋은 생성된 프로젝트에 이미 존재하며 이 세션에서 전투 구현을 추가하지 않았다.

## 인수인계

사용자의 GitHub 소유자·저장소명·공개 작성자 정보와 에셋 출처 답변이 필요하다. 실행 권한 제한을 해결한 뒤 공개 파일의 토큰 제거, LFS·제외·비밀 검증, 인증과 업로드를 이어간다. 상태 문서에는 완료하지 않은 내용을 완료로 기록하지 않는다.
