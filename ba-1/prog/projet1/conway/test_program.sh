#!/bin/bash
# imput parameter you may use
# -inter -i (test rendu1|intermediate)
# -final -f (test rendu2|final)
# -save  -s (save files)

for i in "$@"
do
case $i in
    -s|--save)
    SAVE=true
    shift # past argument
    ;;
    -i|--inter)
    IS_INTER=true
    LAST_INTER=6
    LAST_FINAL=0
    shift # past argument
    ;;
    -f|--final)
    IS_INTER=false
    IS_FINAL=true
    LAST_INTER=6
    LAST_FINAL=12
    shift # past argument
    ;;
    #--default)
    #DEFAULT=YES
    #;;
    *)
    echo "uncknown argument"
            # unknown option
    ;;
esac
shift # past argument or value
done

# make sure a test parameter was given
if [ "$IS_INTER" != true ] && [ "$IS_FINAL" != true ]; then
	echo "you must specify whether you are testing the intermediate or final 
	version with one of the commands: -i --inter -f --final"
	exit 1
fi

# required files
SOURCE_FILE="conway.c"
TEST_FILE="conway.x"
FINAL_FILE="final_conway.x"
INTER_FILE="inter_conway.x"

# compile SOURCE_FILE
echo "RELAX WHILE I COMPILE AND TEST YOUR CODE!"
gcc "$SOURCE_FILE" -o "$TEST_FILE" -lm

# counter for test files nbr
let "i = 1"

# create result files
echo "tests 1 to 6" > "my_out1to6.txt"
echo "tests 1 to 6" > "out1to6.txt"

WRONG=""

# iterates through the first 6 test files
while [ $i -le $LAST_INTER ]; do
	
	# print current test number
	echo
	echo "TEST $i"
	
	# run TEST_FILE for test i , print and save results
	MY_OUT_STRING=$("./$TEST_FILE" < "test$i.txt")
	echo "OUTPUT IS: ""$MY_OUT_STRING"
	echo "test$i: ""$MY_OUT_STRING" >> "my_out1to6.txt"
	
	# run INTER_FILE for test i , save results
	OUT_STRING=$("./$INTER_FILE" < "test$i.txt")
	echo "test$i: ""$OUT_STRING" >> "out1to6.txt"
	
	# compare output of the programs
  	if [ "$MY_OUT_STRING" == "$OUT_STRING" ]; then
  		echo "BINGO!"
	else
		echo "NOT QUITE, IT SHOULD BE: ""$OUT_STRING"
		WRONG="$WRONG$i "
	fi
	let "i++"
done

# keep results?
if [ "$SAVE" != true ]; then
	rm "my_out1to6.txt"
	rm "out1to6.txt"
fi


# counter for test files nbr
let "i = 7"

# iterates through the last 6 test files
while [ $i -le $LAST_FINAL ]; do
	
	# print current test number
	echo
	echo "TEST $i"
	
	# run FINAL_FILE for test i, save resulting image
	OUT_IMAGE=$("./$FINAL_FILE" < "test$i.txt")
	echo "$OUT_IMAGE" >> "out$i.pbm"
	
	# run TEST_FILE for test i, save resulting image
	MY_OUT_IMAGE=$("./$TEST_FILE" < "test$i.txt")
	echo "$MY_OUT_IMAGE" >> "my_out$i.pbm"
	
	# compare out.pbm to the correct ouptput, if all pixels are equal the output is 0	
	OUT_ERROR=$(compare -metric AE "my_out$i.pbm" "out$i.pbm" null: 2>&1) 
	
	# test if the image differences is 0
  	if [ "$OUT_ERROR" == "0" ]; then
  		echo "BINGO!"
	else
		echo "BAD ANSWER"
		WRONG="$WRONG$i "
	fi
	
	# keep resulting images?	
	if [ "$SAVE" != true ]; then
		rm "out$i.pbm"
		rm "my_out$i.pbm"
	fi
	
	let "i++"
done

echo
if [ "$WRONG" != "" ]; then
	echo "your program did not passed test(s) $WRONG"
else
	echo "you program passed all tests, GOOD JOB!!!"
fi
echo
