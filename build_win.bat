@cmake.exe -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=RELEASE -H. -B build
@cmake.exe --build build --target ../bin/Cipher-Encryption-Project.exe -- -j4
"./bin/Cipher-Encryption-Project.exe"