# PM — UNREAL-MCP-SETUP / 01

- 날짜·시간: 2026-10-05 (Asia/Seoul)
- 역할 / 작업 ID: PM / UNREAL-MCP-SETUP
- 브랜치 / 작업 공간: codex/unreal-mcp-setup / Saved/GitSetup/unreal-mcp-setup-worktree
- 기준 커밋: e8ede0db4b373bf1284871a871654b9e5f08611a
- 관련 문서: docs/runbooks/unreal-mcp.md

## 목표와 수행 내용

사용자는 Unreal MCP와 Codex 연동을 요청했고 구현체는 미정이라고 답했다. UE 5.8.2의 Epic 내장 ModelContextProtocol/AllToolsets와 엔진 바이너리 존재를 확인해 이 경로를 선택했다. 사용자가 에디터 저장 및 종료를 완료한 후, 두 플러그인의 프로젝트 설정을 Editor 타깃으로 제한해 추가했다.

실제 콘텐츠 실행은 원본 프로젝트에서 수행했다. worktree는 LFS 포인터 상태이므로 실행용으로 사용하지 않았다. 원본과 worktree의 uproject 변경 전 해시가 같은지 확인하고 동일 변경을 적용했다. 원본 파일은 Saved/UnrealMCPSetup에 백업했다. 사용자의 기존 Config 변경은 수정하지 않았다.

로컬 Saved/Config/WindowsEditor/EditorPerProjectUserSettings.ini에 MCP 자동 시작/포트 8000/경로 /mcp/도구 검색 설정을 추가하고 변경 전 파일을 백업했다. 사용자 실행 승인으로 전역 Codex 설정에 unreal_editor Streamable HTTP 항목을 추가했다. 기존 설정을 유지하고 사용자 설정 디렉터리에 백업했다. 이러한 개인 설정과 응답 기록은 공개 커밋에 포함하지 않는다.

## 어려움과 해결 시도

샌드박스의 Codex CLI는 사용자 홈을 찾지 못했다. 실제 사용자 환경으로 승인된 읽기 조회를 수행해 MCP 등록을 확인했다. 앱의 현재 세션 도구 목록은 새 설정으로 자동 갱신됐다고 주장하지 않는다. MCP 재로드 또는 앱 재시작 후 네이티브 도구 노출은 후속 확인한다.

## 검증

- 프로젝트 JSON 파싱 및 새 플러그인 두 항목 확인.
- 에디터 재시작 후 로그에서 MCP 메타 도구 3개 및 도구 집합 52개 등록 확인.
- HTTP initialize 성공. 응답 protocolVersion은 2025-11-25이며 serverInfo 문자열은 비어 있었다. 문서의 이름과 동일하다고 기록하지 않는다.
- notifications/initialized, tools/list, list_toolsets, describe_toolset 호출 성공.
- call_tool을 통한 EditorToolset.EditorAppToolset.GetContentBrowserPath 읽기 호출 성공. 실제 결과는 /Game/TripoModels/FemaleRover였다.
- 승인된 codex mcp get unreal_editor에서 enabled=true, streamable_http, http://127.0.0.1:8000/mcp, startup 30초/tool 120초 확인.
- 응답은 제외된 Saved/UnrealMCPSetup에 보관. 에셋 생성/수정, PIE, 게임 빌드, 전용 서버, Android 패키징은 수행하지 않았다.

## 결정과 학습

공식 내장 MCP를 먼저 사용한다. 플러그인 활성화는 Editor에 한정한다. 연결 서버는 로컬 전용으로 운영하고 PM이 에디터 변경 담당 세션을 조율한다. HTTP 호출 성공과 Codex 네이티브 MCP 도구 호출 성공을 구분한다.

## 인수인계

코드 리뷰 후 프로젝트 설정/절차/로그의 PR을 준비한다. 최종 병합은 사용자 결정이다. Codex MCP 재로드/재시작 후 unreal_editor 네이티브 도구로 읽기 호출을 다시 확인한다.
