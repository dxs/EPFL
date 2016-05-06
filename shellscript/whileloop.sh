#!/bin/bash

a=1

while [ $a -lt 6 ]
do
	echo "Next number is $a"
	let a=a+1
done
