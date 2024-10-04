#!/bin/bash

cd ..

for testfile in tests/rv32ui-p-*.hex; do
    testname=$(basename ${testfile%.hex})
    TEST_OUTPUT_FILE="CPU_rvtests_"$testname
    iverilog -o $TEST_OUTPUT_FILE CPU.v <(sed -e "s:tests/rv32ui-p-.*\.hex:$testfile:" CPU_tb.v)
    vvp $TEST_OUTPUT_FILE|grep "gp(x3): 00000001" > /dev/null
    if [ $? -eq 0 ]; then
        printf "%-20s\tpassed\n" $(basename ${testfile%.hex})
        rm $TEST_OUTPUT_FILE
    else
        printf "%-20s\tfailed\n" $(basename ${testfile%.hex})
        vvp $TEST_OUTPUT_FILE|grep "gp(x3): [0-9]*"
    fi
done
