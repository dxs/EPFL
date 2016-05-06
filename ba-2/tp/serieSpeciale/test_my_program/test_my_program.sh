#!/bin/bash

executable_name=$1
input_name=$2
first_index=$3
last_index=$4
file_extension=$5
output_name=$6

i=$first_index

while [ $i -le $last_index ]
do
        echo "$i. input is under process."
        ./$executable_name < $input_name$i$file_extension >> $output_name$i$file_extension
        let i++
done

