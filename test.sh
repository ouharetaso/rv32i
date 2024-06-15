#!/bin/bash


iverilog -o ${1} ${1}_tb.v ${1}.v
vvp ${1}
gtkwave ${1}.vcd