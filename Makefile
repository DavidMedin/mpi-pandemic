all: pandemic.bin

run: # Run without compiling or copying first
	mpirun     --hostfile hostfile      /home/tomsgang/mpi-pandemic/pandemic.bin
# 	 run   |< with these computers >|   |<     this program on each computer  >|

run-c: pandemic.bin # Run with compiling first, but not copying
	mpirun --hostfile hostfile /home/tomsgang/mpi-pandemic/pandemic.bin

run-cc: copy # Run with compiling and copying first
	mpirun --hostfile hostfile /home/tomsgang/mpi-pandemic/pandemic.bin

copy: pandemic.bin
	./copy.sh < hostfile

pandemic.bin: main.c
	mpicc main.c -o pandemic.bin
