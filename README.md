# MPI Pandemic

## Requirements
These Ubuntu packages are required to run this project
* openmpi-bin
* openmpi-common  (maybe, not sure)
* libopenmpi-devel
* openmpi-doc (this one is optional)
You can install these with this command (as root):
```bash
apt install openmpi-bin openmpi-common libopenmpi-devel openmpi-doc
```

## Project Structure
There is a `Makefile` that is used to perform common tasks.
For example, to compile the project, run `make`. To run the project, run `make run`.\
The command `make copy` will copy the program `pandemic.bin` to the other computer I have setup.

|command|description|
|-------|-----------|
|`make`| Compile the program.|
|`make run`| Run the program.|
| `make run-c`| Run the program, but compile first.|
| `make run-cc`| Run the program, but compile and copy first.|

You will need to supply your own `hostfile`, because we shouldn't have our IP addresses public in this repo.
>>>>>>> a4bd76a (Added project structure)
