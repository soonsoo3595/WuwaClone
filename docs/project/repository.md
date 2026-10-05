# 저장소와 작업 관리

최종 갱신: 2026-10-05 (Asia/Seoul)

## 확정한 구조

개발 과정부터 공개하는 단일 GitHub 저장소로 운영한다. 기존 UE 프로젝트 루트는 유지한다. 기존 홈 서버 인프라 저장소는 별도로 유지한다.

| 경로 | 담당 내용 |
| --- | --- |
| Source, Content, Config | UE 게임·데디케이티드 서버 및 에셋 |
| Content/Assets, Content/TripoModels | 로컬 보관 전용 에셋. 두 폴더 전체를 Git에서 제외 |
| Backend | C# API 및 DB 마이그레이션 |
| Launcher | PC 런처 |
| Deploy | 게임용 Docker·배포 설정 |
| Scripts | 빌드·실행·검증 자동화 |
| Tests | 외부 통합·부하 검증. UE 내부 테스트는 관련 Source 모듈에 둔다. |
| docs/project, roles, specs, architecture, decisions, sessions, runbooks | 프로젝트 운영·설계·기록 |
| .github/workflows | GitHub Actions |

아직 구현하지 않는 영역은 필요할 때 디렉터리를 생성한다. 폴더 존재를 기능 완료로 취급하지 않는다.

## Git 전략

- 상설 브랜치: dev(통합), main(검증된 배포·시연 버전).
- dev에서 feat/<작업ID>-<설명>, fix/<작업ID>-<설명>, docs/<작업ID>-<설명>을 분기한다.
- 한 작업은 Issue 하나·브랜치 하나·PR 하나를 기본으로 한다. 작업 브랜치를 만들면 실제 작업할 로컬 체크아웃을 해당 브랜치로 전환한 뒤 수정한다. worktree를 사용하더라도 원본 main/dev에 같은 수정본을 중복해서 남기지 않는다.
- 기능 PR은 변경에 필요한 검증 후 squash merge로 dev에 통합한다. 별도 QA와 코드 리뷰는 사용자 요청이 있을 때만 수행한다. 최종 병합은 사용자가 결정한다.
- dev에서 release/<버전>을 만들고 버전 범위를 고정한다. 새 기능은 dev에서 계속 진행한다.
- release에서 패키징·배포를 검증한 후 merge commit으로 main에 통합하고 버전 태그를 만든다. 수정은 dev에도 merge로 반영한다.
- 긴급 수정은 main에서 hotfix/<작업ID>-<설명>으로 분기한다. main, dev와 진행 중인 관련 release에 반영한다.
- 알파·베타는 초기에는 v0.1.0-alpha.1, v0.1.0-beta.1, v0.1.0 태그로 구분한다.
- 코드 리뷰(코드·설계)와 QA(실행 결과)는 별도 검토이며, 별도 사람 계정 승인 요건을 자동으로 가정하지 않는다.

## 커밋 메시지

형식은 `태그 | 작업 내용`이다. 대괄호 없이 태그를 적고 구분자 `|` 양쪽에 공백을 하나씩 둔다. 작업 내용은 한국어로 변경 결과를 간결하게 적는다. 서로 다른 목적의 변경은 가능한 한 커밋을 나눈다. 필요한 상세 설명과 검증 결과는 빈 줄 뒤 본문에 적는다. 기능 PR의 squash 커밋 제목에도 같은 형식을 사용한다.

| 태그 | 의미 | 예시 |
| --- | --- | --- |
| Feat | 새로운 기능 추가 | Feat \| 캐릭터 이동 추가 |
| Fix | 기존 기능의 동작·요구사항 수정 | Fix \| 달리기 속도 조정 |
| Debug | 결함·버그 수정 | Debug \| 점프 입력 중복 처리 수정 |
| Refactoring | 동작을 유지하면서 코드 구조 개선 | Refactoring \| 이동 입력 처리 분리 |
| Import | 에셋 임포트·갱신 | Import \| 캐릭터 모델 임포트 |
| Docs | 문서 추가·수정 | Docs \| 데디케이티드 서버 실행 절차 작성 |
| Test | 테스트 추가·수정 | Test \| 이동 입력 검증 추가 |
| Build | 빌드·패키징·의존성 설정 변경 | Build \| 서버 빌드 타깃 추가 |
| CI | 자동 검사·GitHub Actions 설정 변경 | CI \| PR 검사 워크플로 추가 |
| Chore | 저장소 설정·관리 작업 | Chore \| 초기 프로젝트와 Git 운영 설정 추가 |
| Style | 동작에 영향 없는 코드 서식 수정 | Style \| 이동 코드 들여쓰기 정리 |
| Remove | 기능·파일·에셋 제거 | Remove \| 사용하지 않는 테스트 에셋 제거 |

Fix와 Debug는 사용자 정의에 따라 구분한다. 에셋 Import 커밋도 공개 조건 확인과 Git LFS 규칙을 따라야 하며, Content/Assets/와 Content/TripoModels/ 제외 규칙을 우회하지 않는다. 새 기능과 함께 필요한 테스트처럼 같은 목적의 변경은 주된 작업 태그를 사용한다.

## 작업 관리

현재 공개 저장소는 [soonsoo3595/WuwaClone](https://github.com/soonsoo3595/WuwaClone)이며 [작업 보드](https://github.com/users/soonsoo3595/projects/6)를 연결했다. main/dev는 PR과 리뷰 대화 해결을 요구하고 관리자에게도 적용한다. 별도 승인자 수는 0, 필수 CI 검사는 없다. 강제 push와 브랜치 삭제는 금지한다. 기능 PR에는 squash merge, release/hotfix에는 merge commit을 사용한다. GitHub의 squash 기본 제목은 PR 제목이므로 PR 제목도 `태그 | 작업 내용`으로 작성한다. 실제 UE CI 워크플로와 runner는 별도 작업이다.

- GitHub Issues: 목적, 범위, 담당 역할, 선행 작업, 완료 조건, 검증 방법, 관련 문서.
- GitHub Projects 상태: Backlog → Ready → In Progress → Review → Done.
- 차단은 blocked 표시와 원인을 기록한다. Done은 dev에 병합된 상태다. 배포 여부는 release와 태그로 추적한다.
- PR: 변경·검증·코드 리뷰 증거. 문서: 확정한 명세·구조. 세션 로그: 수행 과정·어려움·인수인계.
- GitHub Actions를 사용한다. UE 소스 빌드 환경을 포함한 runner 설정과 실제 검사 워크플로는 별도 작업으로 구현한다.

## 공개 및 파일 관리

- 코드·설정·문서는 일반 Git, 바이너리 에셋은 .gitattributes에 지정한 Git LFS로 관리한다.
- 에디터 상태·캐시·빌드 결과·비밀 정보는 .gitignore로 제외한다.
- 엔진 소스는 포함하지 않고 버전·소스 커밋·빌드 절차를 기록한다.
- 외부 에셋은 원본 공개 조건과 게임에 포함한 배포 조건을 구분해서 기록한다. 포괄적인 코드 라이선스를 에셋에 자동 적용하지 않는다.
- 사용자는 현재 프로젝트 에셋이 모두 UE 기본 템플릿이라고 확인했다. Git에 올리지 않을 에셋은 Content/Assets/와 Content/TripoModels/에 보관한다. 루트 Assets/는 잘못 지정된 경로로 제외하지 않는다. 다른 Content 경로는 기존 Git LFS 대상으로 유지하고 공개 조건을 확인한다.
- 저장소의 코드 라이선스는 아직 정하지 않았다.
