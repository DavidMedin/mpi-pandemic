all: pandemic.bin

run: # Run without compiling or copying first
	mpirun     --hostfile hostfile      `pwd`/pandemic.bin $(ARGS)
# 	 run   |< with these computers >|   |<     this program on each computer  >|

run-c: pandemic.bin # Run with compiling first, but not copying
	mpirun --hostfile hostfile `pwd`/pandemic.bin $(ARGS)

run-cc: copy # Run with compiling and copying first
	mpirun --hostfile hostfile `pwd`/pandemic.bin $(ARGS)

copy: pandemic.bin
	./copy.sh < hostfile

pandemic.bin: main.c
	mpicc src/pandemic.c -o pandemic.bin
