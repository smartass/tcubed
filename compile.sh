#!/bin/sh
# A temporary script for compilation.

set -e

# cd to the directory of this script:
cd "$(dirname "$(readlink -f "$0")")"

g++ -c -std=c++0x -o ./obj/engine.o src/engine.cpp
g++ -c -std=c++0x -o ./obj/main.o src/main.cpp

g++ -std=c++0x -o ./bin/tcubed ./obj/main.o ./obj/engine.o
