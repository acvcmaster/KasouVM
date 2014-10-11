# Generate loadFile obj
cd loadFile
bash "genObj.sh"
cd ..

#...

g++ "main.cpp" "loadFile/loadFile.h" "loadFile/loadFile.o" -std=c++0x -Wno-write-strings -o "bin/kasm"