# PM — DEV-PROTECTION / 01

- 날짜: 2026-10-05 (Asia/Seoul)
- 작업 대상: soonsoo3595/WuwaClone의 dev 브랜치 보호

## 목표와 수행 내용

사용자의 명시적 요청으로 GitHub dev 브랜치 보호를 해제했다. main 보호는 변경하지 않았다. 변경 전 보호 설정은 제외된 Saved/GitSetup/dev-protection-removal-20261005에 보관했다.

## 어려움과 해결 시도

샌드박스에서 GitHub 연결이 차단되어 사용자 승인으로 실제 사용자 환경에서 실행했다.

## 검증

GitHub API DELETE 성공 후 dev 보호 조회에서 Branch not protected를 확인했다. dev에 적용되는 ruleset 규칙은 0개였다. main 보호 API 응답은 변경 전후 동일했다. 실제 시험 push와 QA·코드 리뷰는 수행하지 않았다.

## 결정과 학습

dev 직접 push를 허용한다. 기존 문서의 main/dev 모두 보호한다는 설명은 이 사용자 결정으로 dev에 대해서 폐기됐다. main 보호와 사용자 요청에 따른 QA·코드 리뷰 정책은 유지한다.

## 인수인계

현재 기록은 로컬 파일이며 자동 커밋·push하지 않았다. 운영 문서 갱신 시 dev 보호 해제 결정을 반영한다.
