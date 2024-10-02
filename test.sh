#!/bin/bash


iverilog -o ${1} ${1}_tb.v ${1}.v
if [ $? -eq 0 ]; then
    echo "Compilation successful"
else
    echo "Compilation failed"
    exit 1
fi
vvp ${1}
if [ $? -eq 0 ]; then
    echo "Simulation successful"
else
    echo "Simulation failed"
    exit 1
fi
gtkwave ${1}.vcd