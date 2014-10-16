# Generate loadFile obj
cd loadFile
bash "genObj.sh"
cd ..

#...

g++ "main.cpp" "loadFile/loadFile.h" "loadFile/loadFile.o" "assembler.h" "assembler.cpp" -std=c++0x -Wno-write-strings -o "bin/kasm"
# g++ "main.cpp" "loadFile/loadFile.h" "loadFile/loadFile.o" "assembler.h" "assembler.cpp" -Wno-write-strings -o "bin/kasm"
sudo dd if="bin/kasm" of="/usr/bin/kasm"