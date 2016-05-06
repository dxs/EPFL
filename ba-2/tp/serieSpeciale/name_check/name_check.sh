#!/bin/bash

name_list=('Richard' 'Laura' 'Henry' 'Marie' 'Antoine')

# get the total number of names in the name_list
number_of_names=${#name_list[@]}

name_found=0

# check if the input is empty or not.
# if it is, print a warning
if [ -z $1 ]; then
        echo "You must enter a name!"
else
        # iterate over all the names and check if any of them
        # is equal to the input
        for((i=0;i<$number_of_names;++i)); do
                # if the input is equal to the next list element
                # set name_found 1 and leave the iteration
                if [ $1 == ${name_list[${i}]} ]; then
                        let name_found=1
                        break
                fi
        done
        if [ $name_found -eq 0 ]; then
                echo "$1 is not in the list!"
        else
                echo "$1 is in the list!"
        fi
fi

