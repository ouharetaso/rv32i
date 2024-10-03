# Makefile for compiling test.s using riscv-unknown-elf-as

PREFIX = riscv64-unknown-elf-
AS = $(PREFIX)as
ASFLAGS = -march=rv32i
TARGET = test
SRC = test.s

all: $(TARGET).hex

$(TARGET).o: $(SRC)
	$(AS) $(ASFLAGS) -o $@ $<

$(TARGET).bin: $(TARGET).o
	$(PREFIX)objcopy -O binary --only-section=.text $< $@ 

$(TARGET).hex: $(TARGET).bin
	hexdump -v -e '1/4 "%08x" "\n"' $< > $@

clean:
	rm -f $(TARGET).o