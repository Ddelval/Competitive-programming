#bin/bash


A="$(ls)"
for a in $A
do
    echo "$( ls $a/$a)"
    echo "\n\n"
done