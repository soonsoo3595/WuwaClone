# 셰이더·머티리얼 — TOON-FINISH / 01

- 날짜·시간: 2026-10-06 (Asia/Seoul)
- 역할 / 작업 ID: 셰이더·머티리얼 / TOON-FINISH
- 브랜치 / 작업 공간: feat/19-camera-basic-animation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 커밋・업로드하지 않음
- 관련 Issue / PR / 명세: 사용자 요청으로 약한 툰 음영·외곽선·적용 저장 진행

## 목표와 수행 내용

- Content/Materials/M_FemaleRover_Toon 및 MI_FemaleRover_Toon 생성. 기존 ColorBase 및 UnlitCompare 보존.
- 색 보정 출력에 Custom HLSL의 부드러운 2단계 음영 적용. PixelNormalWS와 LightDirection의 내적을 사용.
- 이 아틀라스의 얼굴 UV 영역(u 2/3~1, v 1/3~2/3)을 구분하여 얼굴 음영은 약하게 유지. 다른 아틀라스에는 재설정 필요.
- ShadowStrength 0.32, FaceShadowStrength 0.06, ShadowThreshold 0.05, ShadowFeather 0.06, ShadowTint (0.7,0.67,0.78). 기존 Brightness 0.85 / ColorContrast 1.25 / ColorTint 유지.
- LightDirection (-0.64,0.116,0.761)은 현재 태양 방향에 근사한 표현용 파라미터이며 레벨 조명 변경을 자동 추적하지 않음. Unlit 기반이므로 환경 조명·다중 광원·수신 그림자는 재현하지 않음.
- M_FemaleRover_Outline / MI_FemaleRover_Outline 생성. VertexNormalWS에 따른 외곽 확장과 backface-only alpha mask 사용. 최종 OutlineWidth 0.055cm, OutlineColor (0.018,0.012,0.025).
- LV_Test의 SkeletalMeshActor_1 본체에 MI_FemaleRover_Toon 적용. ToonOutline SkeletalMeshComponent를 추가하고 본체에 부착, LeaderPoseComponent를 본체로 지정. NoCollision, overlap false, CastShadow false 적용.
- 변경 전 디스크 레벨을 Saved/ShaderWork/2026-10-06/LV_Test-before-toon-230208.umap에 백업. LV_Test 및 신규 머티리얼·인스턴스 저장 완료. 레벨에 기존 미저장 편집 내용도 함께 보존하여 저장됨. Blueprint·원본 모델·기존 머티리얼은 변경하지 않음.

## 어려움과 해결 시도

- MCP의 Custom Inputs 배열 설정은 크기 변경과 요소 변경을 동시에 처리하지 못해 최초 컴파일 실패. 기존 입력의 전체 직렬화 구조를 보존하여 배열 크기를 먼저 변경한 후 이름과 연결을 설정하여 해결.
- 외곽선 첫 두께 0.12cm가 머리카락에서 강해 보여 0.055cm로 감소하고 색을 완화함. 모델의 열린 면/노멀 경계에서는 선 품질에 한계가 있음.

## 검증

- 최종 두 마스터 recompile 오류 없이 완료, 지정 에셋 save_assets true.
- 레벨 및 4개 신규 에셋 is_dirty false 확인.
- 툰 Custom 입력 9개 연결 읽기 확인. 인스턴스 Brightness 유지 확인.
- 외곽선 LeaderPose 참조·NoCollision·CastShadow false·머티리얼 참조 읽기 확인.
- 정면 및 사선 뷰포트 캡처로 밝은 얼굴 유지, 약한 몸체 음영, 얇은 실루엣 확인.
- Git status로 LV_Test 변경 및 Content/Materials 신규 파일 확인.
- Android·패키징·런타임 애니메이션·GPU 비용 검증은 미실행. LeaderPose 설정 확인을 애니메이션 실행 검증으로 취급하지 않음.

## 결정과 학습

- 사용자는 시각 작업을 이 세션이 맡아 완료하도록 명시 요청함. 추가 단위마다 사용자에게 수동 제작을 요구하지 않음.
- 엔진 수정이나 전체 화면 후처리 대신 캐릭터 머티리얼과 외곽선용 추가 메시 사용. 외곽선은 메시를 한 번 더 그리는 비용이 있음.
- 외부 텍스처 및 모델은 Content/TripoModels 제외 경로 참조. 공개 업로드하지 않으며 새 clone만으로 재현되지 않음.

## 인수인계

- 테스트 레벨의 FemaleRover 외관 제작·적용·저장 완료. 플레이어 Blueprint로의 통합은 이번 작업에 포함하지 않음.
- Android 실제 기기 외관·성능 및 애니메이션 동작은 후속 검증 항목. 공통 상태 문서는 수정하거나 PM에 자동 전달하지 않음.
