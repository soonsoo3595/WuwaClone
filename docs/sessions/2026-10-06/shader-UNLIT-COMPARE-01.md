# 셰이더·머티리얼 — UNLIT-COMPARE / 01

- 날짜·시간: 2026-10-06 (Asia/Seoul)
- 역할 / 작업 ID: 셰이더·머티리얼 / UNLIT-COMPARE
- 브랜치 / 작업 공간: feat/19-camera-basic-animation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 커밋하지 않음
- 관련 Issue / PR / 명세: 사용자의 Content/Materials 생성 요청

## 목표와 수행 내용

- Unreal Editor MCP로 `/Game/Materials/M_FemaleRover_UnlitCompare` 생성·저장 및 에디터 열기 완료.
- 기존 FemaleRover_basecolor_png를 BaseColorTex 파라미터의 기본 텍스처로 사용. RGB → Emissive Color, Alpha → Opacity Mask.
- Unlit / Masked / Skeletal Mesh 사용 설정. 기존 머티리얼·모델·레벨은 수정하지 않음.

## 어려움과 해결 시도

- 다른 기능 브랜치에 코드·바이너리·문서의 로컬 변경이 존재하여 브랜치 전환 없이 별도 신규 에셋만 추가함. 이 작업을 별도 커밋·PR로 통합하려면 변경 분리가 필요함.

## 검증

- MCP recompile 오류 없이 완료, save_assets true, is_dirty false.
- 설정 및 RGB/Alpha 출력 연결을 MCP로 읽어 확인.
- git status로 Content/Materials 신규 파일 확인.
- 캐릭터 적용 후 외관 비교, Android 실행·성능 검증은 미실행.

## 결정과 학습

- 완성 툰 셰이더가 아니라 엔진 조명이 추가한 명암을 비교하기 위한 기본색 출력 머티리얼임. 노출과 톤 매핑은 계속 영향을 줄 수 있음.
- Git 제외 경로의 외부 텍스처를 참조하므로 텍스처 없이 새 clone에서 재현되지 않음. 업로드·커밋하지 않음.

## 인수인계

- 다음 단계는 사용자 요청 시 캐릭터에 적용하여 기존 표현과 비교하고 툰 음영 범위를 정하는 것.
