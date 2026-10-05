# Git — ASSET-POLICY / 01

- 날짜: 2026-10-05 (Asia/Seoul)
- 작업 공간: assets-policy-worktree
- 기준: dev 1fa3f5f

## 목표와 수행 내용

사용자가 전체 에셋 제외 요청을 정정하여 Content/Assets/와 Content/TripoModels/만 제외하도록 최종 지정했다. 미커밋 전체 제외 문서와 규칙을 원상 복구하고 지정 경로만 추적 제거했다. 로컬 원본과 다른 작업 공간의 Config는 보존한다.

## 어려움과 해결 시도

전체 제외 커밋 요청은 거절되어 커밋·push되지 않았다. 그 준비 상태를 먼저 취소한 뒤 좁힌 변경을 준비해 f553ffd로 커밋하고 PR #10에 제출했다.

## 검증

기준 dev 1fa3f5f와 결과 f553ffd를 대상으로 다음 검증을 수행했다.

- git ls-files -- Content/Assets Content/TripoModels 및 git rm -r --cached --ignore-unmatch: Content/Assets의 추적 파일 95개 제거, TripoModels는 기존 추적 파일 없음.
- Get-FileHash SHA256: 제거 전후 로컬 95개 파일 해시 일치.
- git ls-files -- Content: 나머지 658개 추적 유지.
- git check-ignore -v: 두 지정 폴더 제외. Characters 테스트 경로는 제외되지 않음.
- git diff --cached --check: 통과. .gitattributes 등 전체 제외 준비 변경은 취소하여 기존 LFS 정책 유지.
- 별도 코드 리뷰에서 658개 경로·모드·blob 동일, 95개 실파일 SHA256=LFS oid, diff/check-ignore/LFS 검사를 독립 확인했다. 상세 명령과 기준은 함께 통합한 code-review-ASSET-POLICY-01.md를 따른다.

UE 빌드·실행·패키징, 외부 개인 백업 파일 수·해시·완전성 및 다른 checkout 전환·실제 복원은 미검증이다.

## 결정과 학습

경로 밖의 외부 액터·오브젝트는 임의로 제외하지 않는다. 과거 이력과 원격 LFS 정리는 별도다.

## 인수인계

PR로 PM에게 보고하고 최종 병합은 사용자 결정으로 남긴다. PR #9의 Tripo 제외와 정책상 양립하며 별도 리뷰의 양방향 merge-tree 검사에서 공통 .gitignore 충돌이 확인됐다. 어느 순서든 후속 PR에서 /Assets/, /Content/Assets/, /Content/TripoModels/, /Plugins/Tripo3DUEBridge-UE5.8-Win64/를 모두 보존해 해결하고 재검증해야 한다. 실제 병합이나 다른 checkout 갱신은 하지 않았다.
