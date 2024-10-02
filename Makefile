# Makefile for compiling test.s using riscv-unknown-elf-as

AS = riscv64-elf-as
ASFLAGS = -march=rv32i
TARGET = test
SRC = test.s

all: $(TARGET).hex

$(TARGET).o: $(SRC)
	$(AS) $(ASFLAGS) -o $@ $<

$(TARGET).bin: $(TARGET).o
	riscv64-elf-objcopy -O binary --only-section=.text $< $@ 

$(TARGET).hex: $(TARGET).bin
	hexdump -v -e '1/4 "%08x" "\n"' $< > $@

clean:
	rm -f $(TARGET).o