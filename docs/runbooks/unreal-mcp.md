# Unreal MCP와 Codex 로컬 연동

UE 5.8.2에 포함된 Epic `ModelContextProtocol`과 `AllToolsets`를 사용한다. 두 플러그인은 프로젝트에서 Editor 타깃에만 활성화한다. 엔진 소스나 플러그인 배포본을 저장소에 복사하지 않는다.

## 로컬 설정

1. 에디터에서 작업을 저장하고 종료한 뒤 플러그인 설정을 적용한다.
2. 에디터 사용자 설정의 Model Context Protocol에서 Auto Start Server를 켠다. 기본 주소는 `http://127.0.0.1:8000/mcp`다. 사용자 설정은 `Saved/Config/WindowsEditor/EditorPerProjectUserSettings.ini`에 보관하고 커밋하지 않는다.
3. Codex 설정에 아래 항목을 추가한다. 기존 설정과 같은 이름의 서버를 덮어쓰지 않는다. 이 프로젝트에서는 역할 세션이 공유하도록 사용자 전역 설정을 사용한다.

```toml
[mcp_servers.unreal_editor]
url = "http://127.0.0.1:8000/mcp"
startup_timeout_sec = 30
tool_timeout_sec = 120
enabled = true
```

4. Unreal Editor를 먼저 연다. 필요하면 콘솔에서 `ModelContextProtocol.StartServer 8000`을 실행한다. 명령행의 `-ModelContextProtocolStartServer -ModelContextProtocolPort=8000`으로도 시작할 수 있다.
5. Codex의 MCP 설정을 다시 불러오거나 앱/세션을 재시작한 뒤 `unreal_editor` 도구 연결을 확인한다. 서버 설정 등록과 실제 도구 호출 성공은 구분한다.

## 검증과 역할 운영

첫 검증은 MCP initialize, tools/list, list_toolsets 등 읽기 요청으로 한다. Tool Search가 켜져 있으면 기본 도구는 `list_toolsets`, `describe_toolset`, `call_tool`이며 실제 작업 기능은 도구 집합에서 탐색한다. 작업 대상이 WuwaClone인지 확인한 뒤 사용한다.

PM이 에디터 변경 작업의 담당 세션을 지정한다. 여러 세션이 같은 에디터에 겹치는 변경 요청을 보내지 않는다. 같은 바이너리 에셋을 동시에 수정하지 않는다. 승인 정책을 전부 자동 승인으로 바꾸지 않는다.

공식 MCP는 실험 기능이며 로컬 연결용이다. 인증 없는 서버를 홈 서버, 외부 네트워크, 터널에 공개하지 않는다. 게임 서버·Android 실행용 MCP로 취급하지 않는다. 에디터 연결 성공이 게임 빌드·네트워크 QA·패키징 성공을 뜻하지 않는다.

## 복구

Codex 연결을 비활성화하려면 해당 서버의 `enabled`를 `false`로 설정한다. 에디터의 Auto Start Server를 끄고 `ModelContextProtocol.StopServer`로 중단한다. 플러그인 항목을 제거할 때는 에디터를 먼저 종료하고 다른 프로젝트 변경을 보존한다.

## 근거

- [Epic Unreal MCP](https://dev.epicgames.com/documentation/unreal-engine/unreal-mcp-in-unreal-editor)
- [Codex MCP 설정](https://learn.chatgpt.com/docs/extend/mcp?surface=cli)
