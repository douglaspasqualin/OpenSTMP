#!/bin/bash

#Compile tinySTM
echo "Compiling tinySTM ...."
cd tinySTM
make clean && make


echo "Compiling Lee-TM ...."
#compile Lee-TM
cd ../Lee-TM
make clean && make


echo "Compiling STMBench7 ...."
cd ../STMBench7
make clean && make

echo "Compiling stamp ...."
cd ../stamp
./compileForSTM.sh

echo "Done!"



