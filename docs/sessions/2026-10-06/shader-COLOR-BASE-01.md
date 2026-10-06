# 셰이더·머티리얼 — COLOR-BASE / 01

- 날짜·시간: 2026-10-06 (Asia/Seoul)
- 역할 / 작업 ID: 셰이더·머티리얼 / COLOR-BASE
- 브랜치 / 작업 공간: feat/19-camera-basic-animation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 커밋하지 않음
- 관련 Issue / PR / 명세: 사용자 색·밝기 조절 후속 진행 요청

## 목표와 수행 내용

- 비교용 머티리얼을 복제하여 Content/Materials/M_FemaleRover_ColorBase 생성.
- RGB → Power(ColorContrast) → Multiply(ColorTint) → Multiply(Brightness) → Emissive Color. Alpha → Opacity Mask 유지. Unlit / Masked / Skeletal Mesh 사용 유지.
- MI_FemaleRover_ColorBase 생성·저장. ColorContrast 1.25, Brightness 0.85, ColorTint (1, 0.96, 0.98, 1) 설정.
- LV_Test의 SkeletalMeshActor_1.SkeletalMeshComponent0에 인스턴스 적용. 기존 비교용 에셋은 유지. 레벨의 기존 미저장 변경은 함께 저장하지 않음.

## 어려움과 해결 시도

- 부위별 마스크가 없는 상태이므로 전체 색·밝기와 어두운 색의 대비를 조절함. 얼굴 전용 조정이나 툰 조명은 아직 추가하지 않음.

## 검증

- MCP recompile 오류 없이 완료, 두 신규 에셋 save_assets true 및 is_dirty false.
- 인스턴스의 Brightness 0.85 / ColorContrast 1.25 읽기 확인. Alpha 연결 유지 확인.
- 기존 카메라 위치에서 캡처 확인: 머리카락과 의상 어두운 색이 짙어지고 피부 밝기는 소폭 감소, 얼굴 평평한 인상 유지.
- Android·런타임·성능 검증은 미실행.

## 결정과 학습

- 텍스처 자체 수정 없이 색 보정 파라미터로 진행. 노출·톤 매핑 영향은 여전히 존재.
- 마스터 기본값은 대비·밝기 1, 색 흰색으로 중립 설정. 조정값은 인스턴스에 저장.

## 인수인계

- 현재 단계는 색 보정 기반이며 툰 조명·외곽선은 미구현.
- 캐릭터 적용은 미저장 레벨 상태. 원본 모델과 Blueprint는 변경하지 않음.
- 외부 텍스처는 Git 제외 경로 참조이므로 공개 업로드·커밋 없이 로컬에서 유지.
