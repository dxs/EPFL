#!/bin/bash

rm result.txt

let "i = $2"

while [ $i -le $3 ]
do
     echo "Test $i" >> result.txt
	./$1 < test_$i.txt >> result.txt
	let "i++"
done


