# 언리얼 개발 — GAMEPLAY-FOUNDATION-17 / 06

- 날짜·시간: 2026-10-05 (Asia/Seoul, 날짜 기록)
- 역할 / 작업 ID: 언리얼 개발 / GAMEPLAY-FOUNDATION-17
- 브랜치 / 작업 공간: codex/17-gameplay-foundation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 87e2528 / 미커밋
- 관련 Issue / PR / 명세: Issue #17 / PR 없음 / 사용자 요청: 옛 C++ 템플릿 삭제

## 목표와 수행 내용

Source/WuwaClone의 Variant_Combat, Variant_Platforming, Variant_SideScrolling 폴더와 WuwaCloneCharacter/GameMode/PlayerController의 헤더·구현을 삭제했다. 삭제 소스는 82개다. 삭제 전에 모든 절대 경로가 Source/WuwaClone 안에 있는지 확인하고 PowerShell의 LiteralPath로 제거했다.

Build.cs에서 해당 Variant include 경로를 제거하고 모듈 루트 경로를 유지했다. DefaultEngine.ini의 기본 GameMode를 새 BP_WuwaGameMode로 바꾸고 삭제된 클래스에 대한 TP_ThirdPerson 클래스 리다이렉트 3개를 제거했다. 신규 기반 클래스와 사용자 미추적 WuwaPlayableCharacter 소스는 보존했다. 기존 템플릿 Content 에셋과 모듈 의존성은 삭제하지 않았다.

## 어려움과 해결 시도

설정의 옛 기본 GameMode와 클래스 리다이렉트가 제거 대상 클래스를 가리켰으므로 새 프로젝트 GameMode 연결과 삭제된 리다이렉트 제거를 함께 수행했다. Content의 기존 템플릿 Blueprint·레벨에는 삭제한 C++ 부모 클래스 참조가 남을 수 있으며 이를 자동 삭제하거나 재부모화하지 않았다.

## 검증

- git status로 현재 브랜치 및 사용자 미추적 WuwaPlayableCharacter를 확인했다.
- Source/Config의 삭제된 클래스명·Variant 경로 참조를 검색했다.
- Build.cs와 DefaultEngine.ini 변경에 git diff --check를 수행했다.
- 남은 소스 목록을 확인했다.
- 미실행: 사용자 담당 컴파일·빌드, PIE, 바이너리 에셋 참조 검사·수정, 별도 QA/리뷰.

## 결정과 학습

사용자의 템플릿 삭제 요청을 C++ 소스 범위로 수행했다. 새 기반 클래스와 실제 게임 Blueprint는 보존했다.

## 인수인계

기존 템플릿 Content를 사용할 경우 부모 클래스가 사라져 로딩/패키징에 영향을 줄 수 있다. 해당 에셋 정리는 별도 범위다. 이번 삭제는 커밋·푸시하지 않았으며 PM 전달과 학습 노트 추가도 하지 않았다.
