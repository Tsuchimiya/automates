#!/bin/bash

rm asm.txt
rm interpreteur/asm.txt
touch asm.txt
make clean
make
./yacc < test.c
cp asm.txt interpreteur/
cd interpreteur
make clean
make 
./yacc < asm.txt
