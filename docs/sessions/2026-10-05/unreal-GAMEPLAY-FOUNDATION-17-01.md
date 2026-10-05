# 언리얼 개발 — GAMEPLAY-FOUNDATION-17 / 01

- 날짜·시간: 2026-10-05 (Asia/Seoul, 날짜 기록)
- 역할 / 작업 ID: 언리얼 개발 / GAMEPLAY-FOUNDATION-17
- 브랜치 / 작업 공간: codex/17-gameplay-foundation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: PM 전달 기준 dev d900e863143b1e53c7d0383e77cfedbbb0848da0 (HEAD 동일 여부 별도 확인 안 함) / 미커밋
- 관련 Issue / PR / 명세: Issue #17 / PR 없음 / 사용자 직접 작성, 설계·설명 지원

## 목표와 수행 내용

운영 문서와 현재 템플릿 GameMode/PlayerController/Character의 헤더·구현 및 Config 연결을 읽었다. GameModeBase·PlayerController·Character 직접 상속이며 세 클래스는 UCLASS(abstract)다. GameMode 생성자는 stub이고 PC는 입력 매핑·모바일 UI, Character는 이동·점프·카메라를 포함한다. DefaultEngine.ini는 BP_ThirdPersonGameMode를 기본 모드로 지정한다. Blueprint 내부 기본 클래스와 맵별 override는 확인하지 않았다.

## 어려움과 해결 시도

C++ 파일만으로 실제 Blueprint 연결까지 단정하지 않았다. 기존 템플릿 확장과 새 기반 클래스 작성은 사용자 선택으로 남긴다.

## 검증

- git status --short --branch: codex/17-gameplay-foundation 확인, 기존 PM 로그만 미추적.
- Get-Content: 운영 문서 및 템플릿 6개 소스 읽기.
- rg: Config/Source의 GlobalDefaultGameMode, DefaultPawnClass, PlayerControllerClass, GameModeOverride 검색.
- Epic 공식 GameMode/GameState, APlayerController 및 GameMode 설정 문서로 역할과 실행 위치 확인.
- 미실행: 코드/Blueprint 생성·수정, 빌드·실행 QA, 코드 리뷰, 커밋·push. 기존 PM 로그 보존.

## 결정과 학습

GameMode는 서버 규칙과 기본 클래스 선택, PlayerController는 플레이어와 Pawn의 연결 및 로컬 입력/UI, Character는 월드의 몸체와 이동 컴포넌트를 담당한다. 캐릭터 공통 기반은 ACharacter 상속을 우선 제안하되 클래스명과 구조는 미확정이다. 기존 템플릿을 확장할지 엔진 기반 클래스로 새로 작성할지 사용자와 논의한다.

## 인수인계

사용자가 직접 작성한다. 구현을 자동 시작하지 않는다. 사용자 선택 및 추가 질문에 따라 설계·설명을 지원한다. 자동 리뷰/QA 요청은 하지 않는다.
