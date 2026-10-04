# Git — GIT-SETUP / 02

- 날짜·시간: 2026-10-04 (Asia/Seoul)
- 역할 / 작업 ID: Git·GitHub 설정 / GIT-SETUP
- 브랜치 / 작업 공간: main (최초 커밋 전, 이전 확인 기준) / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 없음 / 커밋하지 않음
- 관련 Issue / PR / 명세: docs/project/repository.md

## 목표와 수행 내용

사용자가 현재 에셋은 모두 UE 기본 템플릿이며 Git에 올리지 않을 에셋은 Assets 폴더에 보관하겠다고 확인했다. .gitignore에 프로젝트 루트 /Assets/ 제외 규칙을 추가했다. repository.md와 status.md에 합의를 기록했다. 기존 Content/와 .gitattributes의 LFS 규칙은 유지했다.

## 어려움과 해결 시도

이전 실행에서 샌드박스 오류와 추가 실행 승인 거절이 있었다. 이번 변경은 파일 패치 도구로 적용했다. Assets/에 파일을 생성하거나 기존 에셋을 이동하지 않았다.

## 검증

- 파일 패치 적용 성공을 확인했다.
- /Assets/는 루트 Assets 폴더 전체를 제외하는 Git ignore 규칙이다.
- git check-ignore와 Content/의 LFS 속성 확인 명령을 시도했으나 Windows 샌드박스 초기화 오류로 프로세스가 시작되지 않았다. 따라서 명령 검증은 미완료다. 이전 추가 실행 승인이 거절된 상태여서 별도 실행을 반복 요청하지 않았다. 실제 GitHub 업로드와 LFS 포인터 검증도 미실행이다.

## 결정과 학습

Assets/는 로컬 보관용이며 UE 콘텐츠 경로인 Content/와 구분한다. Assets/에서 Content/로 가져온 에셋에는 이 제외 규칙이 적용되지 않으므로 공개 조건을 확인해야 한다.

## 인수인계

GitHub 소유자·저장소명·공개 커밋 작성자 확인, 연결 토큰 공개 제외 처리, 최초 커밋·dev 생성·remote·push가 남아 있다. PM에 이번 사용자 확인과 제외 규칙 적용 결과를 전달한다.
