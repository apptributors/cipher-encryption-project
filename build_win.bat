@cmake.exe -G "MinGW Makefiles" -H. -Bbuild
@cmake.exe --build build --t -j3
"./bin/Cipher-Encryption-Project"