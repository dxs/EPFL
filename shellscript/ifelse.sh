#!/bin/bash

NUM=$1

if [ $NUM -le 6 ]; then
	if [ $NUM -le 3 ]; then
		echo "NUM is less than or equal to 3"
	else
		echo "NUM is between 3 and 6"
	fi
else
	echo "NUM IS GREATER THAN 6"
fi
