#!/bin/bash
gcc-9 -Wall -lstdc++ -std=c++17 $1.cpp -o $1 2>&1 >/dev/null | grep -v -e '^/var/folders/*' -e '^[[:space:]]*\.section' -e '^[[:space:]]*\^[[:space:]]*~*'

