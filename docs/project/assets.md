# 에셋 출처와 공개 관리

최종 갱신: 2026-10-04 (Asia/Seoul)

사용자는 현재 프로젝트에 UE 기본 템플릿 외의 에셋을 추가하지 않았다고 확인했다. 기존 Content/의 Characters/Mannequins, LevelPrototyping, Input, ThirdPerson, Variant_Combat, Variant_Platforming, Variant_SideScrolling 및 맵 외부 액터·오브젝트는 이 확인에 근거해 생성된 템플릿 콘텐츠로 관리한다. 해당 변형의 존재는 프로젝트 기능 구현 완료를 뜻하지 않는다.

[Epic의 Unreal Engine EULA](https://www.unrealengine.com/eula/unreal)는 Samples와 Templates에 해당하는 Examples를 정의하고, Sharing Examples 조항에서 Examples의 소스·오브젝트 형태 공유를 허용한다. 이 확인은 현재 기본 템플릿에 한정한다. 엔진 소스, Starter Content, Fab·마켓플레이스나 다른 외부 에셋에 자동 적용하지 않는다. Epic 템플릿에 프로젝트 자체의 포괄적 코드 라이선스를 부여하지 않는다.

현재 Content/의 .uasset와 .umap는 Git LFS 대상이다. 공개하지 않을 원본이나 외부 에셋은 프로젝트 루트 Assets/에 로컬 보관한다. Assets/ 전체는 Git에서 제외된다. Assets/에서 Content/로 가져오면 공개 대상이 되므로 가져오기 전에 출처와 원본 공개 조건을 기록한다. 게임에 포함한 배포 허용 여부와 원본 저장소 공개 허용 여부는 구분한다.

새 외부 에셋 기록에는 경로, 제작자·제공자, 원본 주소, 사용한 라이선스·이용 조건, 원본 공개 허용 여부, 게임 배포 허용 여부와 확인 날짜를 포함한다. 공개 여부를 확인하지 못했다면 업로드하지 않는다. 코드 라이선스 선택은 아직 미확정이다.
