# Git — ASSETS-PATH-CORRECTION / 01

- 날짜: 2026-10-05 (Asia/Seoul)
- 기준: dev 669eb13
- 브랜치: codex/correct-assets-docs

## 목표와 수행 내용

사용자는 루트 /Assets/가 잘못된 폴더라고 정정했다. PR #11을 미병합 폐쇄하고 원격 복원 브랜치를 제거했다. 로컬 복원 커밋은 제외된 Saved/GitSetup/discarded-assets-restore-backup의 bundle로 보존했다. 운영 문서의 루트 Assets 설명을 Content/Assets로 정정했고 기존 Content/TripoModels와 Tripo 설치 배포본 제외는 유지한다. 과거 세션 로그와 status의 과거 기록 절은 소급 변조하지 않는다.

## 어려움과 해결 시도

앞선 /Assets/ 복원 제안은 사용자 최종 정책과 달라 폐기했다. 실제 Assets 폴더나 파일은 삭제하지 않았으며 main의 기존 변경은 덮어쓰지 않았다.

## 검증

최신 dev의 .gitignore에 /Assets/ 없음, 두 Content 경로와 Tripo 설치 경로 있음 확인. 이번 PR은 운영 문서와 정정 로그만 변경하고 에셋·Config·ignore 파일은 수정하지 않는다. 공백·시크릿 패턴·파일 범위를 검사한다. UE 실행·외부 백업 복원은 미검증.

## 결정과 학습

과거 /Assets/ 유지 주장과 복구 제안은 현재 정책이 아니다. 현재 유효 경로는 사용자 최종 지정에 따른다.

## 인수인계

PM에 폐기 결과와 새 문서 PR을 보고한다. 새 PR 병합은 사용자 결정이다.
