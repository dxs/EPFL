#!/bin/sh
# -a --all to display all results
# -r --real for professor benchmark conditions
# -h  --help only for troll purposes
FILE1=$1
FILE2=$2
FILETOTEST=$3
echo TEST ON $FILE1
time ./$FILE1 < $FILETOTEST >/dev/null
echo TEST ON $FILE2
time ./$FILE2 < $FILETOTEST >/dev/null
rm tmp
echo done
