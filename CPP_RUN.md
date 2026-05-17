# C++ 파일 실행 방법

이 프로젝트에서 `#include <bits/stdc++.h>`를 사용하는 C++ 파일은 macOS 기본 `g++`가 아니라 GNU GCC인 `g++-15`로 컴파일한다.

## 예시

프로젝트 루트에서 아래 명령을 실행한다.

```bash
g++-15 -std=c++17 src/example_code/dopa_string.cpp -o dopa_string
./dopa_string
```

## 다른 파일 실행하기

다른 C++ 파일을 실행할 때는 소스 파일 경로와 실행 파일 이름만 바꾸면 된다.

```bash
g++-15 -std=c++17 path/to/file.cpp -o 실행파일이름
./실행파일이름
```

예를 들어 `src/example_code/test.cpp`를 실행하려면:

```bash
g++-15 -std=c++17 src/example_code/test.cpp -o test
./test
```
