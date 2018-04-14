#! /bin/bash


if [ -d "$PWD/trash" ]; then  
    echo "Trash directory exists"
else 
    mkdir -p trash
fi

for stuff in "$@" ; do if [ -e $stuff ]; then
        mv $stuff $PWD/trash
else 
       echo $stuff "File does not exist"
fi  ; done ;