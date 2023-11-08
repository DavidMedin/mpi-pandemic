#!/bin/bash
while IFS="" read -r p || [ -n "$p" ] ; do
    echo "scp ./pandemic.bin \"tomsgang@$p:/home/tomsgang/mpi-pandemic/pandemic.bin\""
    scp ./pandemic.bin "tomsgang@$p:/home/tomsgang/mpi-pandemic/pandemic.bin"
done;
# Copy over SSH (using Secure CoPy) this file to user@computer:/path/to/file/to/copy/too 
