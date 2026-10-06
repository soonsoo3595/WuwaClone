# 셰이더·머티리얼 — UNLIT-COMPARE / 02

- 날짜·시간: 2026-10-06 (Asia/Seoul)
- 역할 / 작업 ID: 셰이더·머티리얼 / UNLIT-COMPARE
- 브랜치 / 작업 공간: feat/19-camera-basic-animation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 커밋하지 않음
- 관련 Issue / PR / 명세: 사용자의 다음 단계 진행 요청

## 목표와 수행 내용

- LV_Test의 SkeletalMeshActor_1이 FemaleRover 모델을 사용함을 확인.
- SkeletalMeshComponent0의 overrideMaterials를 M_FemaleRover_UnlitCompare로 설정. 변경 전 overrideMaterials는 빈 배열이며, 빈 배열로 되돌리면 모델 기본 머티리얼을 사용함.
- 모델 원본·Blueprint·기존 머티리얼 변경 없음. 레벨은 기존 미저장 변경이 있어 저장하지 않고 에디터 미리보기 상태로 유지함.

## 어려움과 해결 시도

- CaptureViewport가 스키마상 선택 사항인 인자를 생략하면 오류를 반환함. GetCameraTransform 결과와 명시적인 비활성 주석 설정을 전달하여 캡처함.

## 검증

- overrideMaterials 설정 성공 및 읽기 확인.
- 같은 카메라 위치에서 적용 전후 뷰포트 캡처 확인. 얼굴의 강한 코·볼 및 앞머리 아래 명암이 사라졌고 의상 입체 명암도 줄어듦. 피부 밝기와 회색 머리카락은 추가 조정 대상.
- 원작 완전 재현·Android·런타임 검증은 미실행.

## 결정과 학습

- 엔진의 조명 반응이 외관 차이의 큰 원인임을 비교 확인. 이 단계는 Unlit 비교이며 완성 툰 표현은 아님.

## 인수인계

- 다음은 사용자 요청 시 새 머티리얼의 색·밝기 조절 및 제한된 툰 음영 구성.
- 현재 적용은 미저장 레벨 상태이며 프로젝트를 다시 열면 유지되지 않을 수 있음.
