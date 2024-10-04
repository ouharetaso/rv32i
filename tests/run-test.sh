#!/bin/bash

TEST_OUTPUT_FILE="CPU_rvtests"

cd ..

for testfile in tests/rv32ui-p-*.hex; do
    iverilog -o $TEST_OUTPUT_FILE CPU.v <(sed -e "s:tests/rv32ui-p-.*\.hex:$testfile:" CPU_tb.v)
    vvp $TEST_OUTPUT_FILE|grep "gp(x3): 00000001" > /dev/null
    if [ $? -eq 0 ]; then
        printf "%-20s\tpassed\n" $(basename ${testfile%.hex})
    else
        printf "%-20s\tfailed\n" $(basename ${testfile%.hex})
    fi
done

rm $TEST_OUTPUT_FILE