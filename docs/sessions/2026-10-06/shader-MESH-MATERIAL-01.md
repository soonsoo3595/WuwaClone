# 셰이더·머티리얼 — MESH-MATERIAL / 01

- 날짜·시간: 2026-10-06 (Asia/Seoul)
- 역할 / 작업 ID: 셰이더·머티리얼 / MESH-MATERIAL
- 브랜치 / 작업 공간: feat/19-camera-basic-animation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 커밋하지 않음
- 관련 Issue / PR / 명세: 사용자 지정 FemaleRover.uasset에 머티리얼 적용 요청

## 목표와 수행 내용

- /Game/TripoModels/FemaleRover/FemaleRover의 tripo_mat_8e182a8f 슬롯을 FemaleRover_Mat에서 /Game/Materials/MI_FemaleRover_Toon으로 변경하고 저장.

## 어려움과 해결 시도

- 없음.

## 검증

- set_material true, save_assets true, get_material로 변경된 참조 확인, is_dirty false.
- 런타임·Android 검증은 미실행.

## 결정과 학습

- 기본 슬롯 변경은 별도 override가 없는 모델 인스턴스에 반영됨. 외곽선은 추가 컴포넌트 방식이므로 메시 기본 머티리얼만으로는 포함되지 않음.

## 인수인계

- 모델은 Git 제외 경로 Content/TripoModels에 그대로 유지. 공개 업로드하지 않음.
