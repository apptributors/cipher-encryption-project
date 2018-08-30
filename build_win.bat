@cmake.exe -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=RELEASE -H. -B build
@cmake.exe --build build --target ../bin/Cipher-Encryption-Project.exe
"./bin/Cipher-Encryption-Project.exe"