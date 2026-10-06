# 셰이더·머티리얼 — BASE-OUTLINE / 01

- 날짜·시간: 2026-10-06 (Asia/Seoul)
- 역할 / 작업 ID: 셰이더·머티리얼 / BASE-OUTLINE
- 브랜치 / 작업 공간: feat/19-camera-basic-animation / C:\Unreal Projects\WuwaClone
- 기준 커밋 / 결과 커밋: 커밋하지 않음
- 관련 Issue / PR / 명세: 사용자 승인: Base에 일반 외곽선 메시 추가, 복잡해질 때 별도 클래스 분리

## 목표와 수행 내용

- WuwaBaseCharacter.h/.cpp에 OutlineMesh 기본 서브오브젝트 추가. 본체에 부착, NoCollision, overlap false, CastShadow false, 복제 및 별도 포즈 tick 비활성화.
- OnConstruction/BeginPlay에서 본체 메시 자동 공유, SetLeaderPoseComponent(..., true, false), 전체 슬롯에 OutlineMaterial 적용. 비활성화 또는 NM_DedicatedServer이면 메시·LeaderPose·머티리얼을 비우고 숨김.
- Blueprint 기본 설정으로 bEnableOutline과 OutlineMaterial 노출. C++에 특정 머티리얼 에셋 경로는 남기지 않음.
- BP_WuwaPlayableCharacter에 MI_FemaleRover_Outline 지정·컴파일·저장. 기존 카메라·애니메이션 작업 보존. 기존 테스트 레벨의 별도 시각화용 액터는 변경하지 않음.

## 어려움과 해결 시도

- Git 상태 확인이 샌드박스의 .git/lfs/tmp 쓰기 제한으로 실패하여 승인된 실행으로 상태 확인.
- Slate Ctrl+Alt+F11만으로는 컴파일이 시작되지 않아 Live Coding 메뉴와 컴파일 버튼으로 시작함.
- 최종 Live Coding 클래스 갱신 후 첫 PIE에서 OutlineMaterial이 None으로 확인됨. 최종 클래스의 Blueprint 기본값을 다시 설정·컴파일·저장한 뒤 재실행하여 해결.

## 검증

- Live Coding 2회 컴파일·패치 링크 성공. 최종 패치 로그 시각 2026-10-06 23:18:24 (Asia/Seoul).
- Blueprint 컴파일 성공, 지정 에셋 save_assets true / is_dirty false.
- 최종 PIE: 본체 FemaleRover 공유, LeaderPoseComponent가 CharacterMesh0, MI_FemaleRover_Outline 할당, bVisible true 확인. NoCollision / CastShadow false / overlap false 확인.
- git diff --check 통과. 소스 2개와 기존 변경 중인 플레이어 Blueprint만 이번 단계에서 수정.
- PIE 시작·중지 및 화면 확인 완료. 현재 T 포즈여서 걷기·점프 애니메이션 중 외곽선 검증은 미실행.
- 에디터 종료 후 일반 전체 빌드, 데디케이티드 서버 실행, Android·패키징 검증은 미실행. Live Coding 성공을 전체 빌드 성공으로 기록하지 않음.

## 결정과 학습

- 별도 외곽선 컴포넌트 클래스 대신 Base 소유의 USkeletalMeshComponent 사용. 포즈 공유는 렌더링 추가 비용을 없애지 않음.
- 서버에서 외곽선 메시·포즈 작업은 비활성화하지만 Blueprint의 머티리얼 참조를 서버 cook에서 제외한 것은 아님.
- 런타임 본체 메시 교체 기능은 현재 없으며 향후 추가 시 UpdateOutlineMesh 갱신 연결 필요.

## 인수인계

- 플레이어 외곽선 구성 구현·Blueprint 저장·PIE 연결 확인 완료.
- 사용자의 명시 요청 없이 다른 세션에 구현·검토 요청 또는 PM 상태 전달하지 않음.
