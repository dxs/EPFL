#!/bin/bash

name=('Richard' 'Laura' 'Henry' 'Marie' 'Antoine')

n=${name[@]}
nameFound=0

if [ -z $1 ]; then
	echo "You must enter a name!"
else
	for((i=0;i<n;++i)); do
		if [ $1 == ${n[${i}]} ]; then
			let nameFoun=1
			break
		fi
	done
	if [ $nameFound -eq 0 ]; then
		echo "$1 is not in the list!"
	else
		echo "$1 is in the list!"
	fi
fi
