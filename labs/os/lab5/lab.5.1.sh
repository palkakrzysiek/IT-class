#!/bin/bash


center()
{
     
     COLUMNS="`tput cols`"
     for((i=1;i<=$COLUMNS;i++)); do echo -ne "="; done
     value="$1" 
     if [[ $value -lt $COLUMNS ]] ; then
       width=$(( (  $COLUMNS - ${#value} ) / 2 ))
       printf "%${width}s\n"  "$1"
     else
        echo "$1"
     fi
     for((i=1;i<=$COLUMNS;i++)); do echo -ne "="; done
}


center "test"


files=( * )
numoffiles=0
for i in "${files[@]}"
do
    files[$numoffiles]="${numoffiles}. ${i}"
    echo ${files[$numoffiles]}
    (( numoffiles++ ))
done

for i in $files
do
    echo $i
done
