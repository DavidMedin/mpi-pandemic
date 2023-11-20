all: pandemic.bin

#CFLAGS+=-DTEXT_DISPLAY # Uncomment to show text display
CFLAGS+=-DX_DISPLAY -L/usr/X11R6/lib -lX11 # Uncomment to show X display
CFLAGS+=-DSHOW_RESULTS # Uncomment to make the program print its results


run: # Run without compiling or copying first
	mpirun     --hostfile hostfile      `pwd`/pandemic.bin $(ARGS)
# 	 run   |< with these computers >|   |<     this program on each computer  >|

run-c: pandemic.bin # Run with compiling first, but not copying
	mpirun --hostfile hostfile `pwd`/pandemic.bin $(ARGS)

run-cc: copy # Run with compiling and copying first
	mpirun --hostfile hostfile `pwd`/pandemic.bin $(ARGS)

copy: pandemic.bin
	./copy.sh < hostfile

pandemic.bin: src/Pandemic.c
	mpicc $(CFLAGS) src/Pandemic.c -o pandemic.bin
	
clean: 
	rm -f pandemic.bin
