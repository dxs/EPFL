#!/bin/bash

echo "You entered $# numbers."

result=0;

for a in $*
do
	let result=result+a
done 
echo "Sum of the numbers is $result"
