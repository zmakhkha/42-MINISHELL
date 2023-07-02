#!/bin/bash
while true
do
    processCnt=`ps ax | grep $1 | grep -v grep | grep -v watchdog | wc -l`
    if [ $processCnt -lt 1 ]; then
        $1 
    fi  
    sleep 2
done