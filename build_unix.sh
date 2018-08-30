#!/bin/bash
cmake -H. -Bbuild &&
cmake --build build -- -j3 &&
clear &&
./bin/Cipher-Encryption-Project.out