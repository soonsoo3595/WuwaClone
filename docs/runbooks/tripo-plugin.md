# Tripo 플러그인 별도 설치

## 공개 저장소와 로컬 설치

Tripo Bridge 1.0.5는 로컬에서 사용하는 Editor 전용 플러그인이다. 설치 패키지와 공식 설치 안내에서 플러그인 및 동봉 라이브러리의 공개 재배포 허용 근거를 확인하지 못했다. 공개 저장소에는 배포본의 소스·리소스·머티리얼·정적 라이브러리·실행 바이너리를 포함하지 않는다. 설치 파일은 로컬 `Plugins/Tripo3DUEBridge-UE5.8-Win64/`에 보관하며 이 경로 전체를 Git에서 제외한다.

`WuwaClone.uproject`는 `Tripo3DUEBridge`를 Editor 타깃에만 활성화하고 `Optional: true`로 지정한다. 배포본을 설치하지 않은 체크아웃에서도 플러그인을 필수 의존성으로 요구하지 않기 위한 설정이다. 플러그인 사용 시 별도 설치가 필요하다. 이 설정의 UE 빌드·실행 동작은 이번 Git 정리에서 검증하지 않았다.

## 설치 절차

1. [Tripo 공식 DCC Bridge 설치 안내](https://www.tripo3d.ai/blog/tripo-dcc-bridge-for-ue)에 따라 Tripo Studio에서 패키지를 받는다. API 플러그인과 DCC Bridge를 구분한다.
2. 에디터를 종료하고 사용 중인 엔진과 맞는 배포본을 프로젝트 `Plugins` 폴더에 설치한다. 현재 로컬 폴더명은 `Tripo3DUEBridge-UE5.8-Win64`이며 메타데이터상 엔진 버전은 5.8.0, 지원 플랫폼은 Win64다.
3. 해당 엔진에서 에디터를 열고 필요한 경우 플러그인을 빌드한다. `Window → Tripo Bridge`에서 패널을 열고 Tripo Studio의 DCC Bridge 연결을 확인한다.
4. 플러그인 버전이나 설치 폴더명이 바뀌면 새 경로의 Git 제외 여부를 확인한다. 공개 재배포 조건이 확인되기 전 배포본을 추가하지 않는다.

## 생성 모델과 로컬 설정

생성 모델은 `Content/TripoModels/` 전체를 Git에서 제외한다. 기존 모델 파일을 삭제하지 않는다. 다른 `Content` 에셋과 기존 Git LFS 규칙은 유지한다. 모델을 다른 폴더로 옮기면 제외 규칙이 적용되지 않으므로 공개 조건을 별도로 확인한다.

main 작업 폴더의 `Config/DefaultEditor.ini`와 `Config/DefaultEngine.ini` 변경은 이번 PR 범위가 아니다. 로컬 연결 토큰을 공개 커밋에 포함하지 않는다.

## 검증 범위

Git 제외 규칙·변경 경로·JSON 설정·공백 검사를 수행한다. 기존 로컬 설치의 동작 확인과 새 체크아웃 재현 검증을 구분한다. 이 Git 정리에서는 UE 빌드·모델 전송·런타임·서버 검증을 수행하지 않는다.
