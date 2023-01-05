# Build Instructions
Tars uses Conan for package management and cmake 
```conan install . -if=build -b missing -pr:b default
cmake -B build -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Release
cmake --build build
```