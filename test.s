# rv32i test program


.text
.globl _start
_start:
    lui     x1, 0x12345
    addi    x1, x1, 0x678
    addi    x2, x0, 1
    addi    x3, x0, 16
    add     x4, x0, x0
loop_start:
    beq     x2, x3, loop_end
    add     x4, x4, x2
    addi    x2, x2, 1
    beq     x0, x0, loop_start
loop_end:
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    add     x0, x1, x0
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    