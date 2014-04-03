#!/bin/bash

# requires an executable name to run
if [[ $# != 1 ]]; then
	echo "./run.sh <executable name>"
	exit 0
fi

limits=( 1000 10000 100000 1000000 10000000 100000000)
TIMEFORMAT='%U %S'

F="$1.txt"
echo "" > $F
for n in "${limits[@]}"; do
	echo $n
	for (( i = 0; i < 10; i++ )); do
		TIME=$( { time ./$1 someText $n > /dev/null; } 2>&1 )
		echo $TIME >> $F
	done
	echo "-----------" >> $F
done
