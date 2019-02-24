CC = g++
CC_FLAGS = -m32
AS = as
AS_FLAGS = --32
LD = ld
LD_FLAGS = 

OBJECTS = loader.o kernel.o

%.o: %.cpp
	$(CC) $(CC_FLAGS) -o $@ -c $<

%.o: %.s
	$(AS) $(AS_FLAGS)

kernel.bin: linker.ld $(OBJECTS)
	$(LD) $(LD_FLAGS) -T $< -o $@ $(OBJECTS)

install: kernel.bin
	sudo cp $< /boot/kernel.bin

clean:
	rm $(OBJECTS)
