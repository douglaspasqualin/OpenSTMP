#!/bin/bash

for dir in \
    bayes \
    genome \
    intruder \
    kmeans \
    labyrinth \
    ssca2 \
    vacation \
    yada
do

cd ${dir}
make -f Makefile.stm.otm clean
make -f Makefile.stm.otm
cd ..

done

