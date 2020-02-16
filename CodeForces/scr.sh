#bin/bash


A="$(ls)"
for a in $A
do
    b= "$( ls $a/$a)"
    #mv $a/$a/main.cpp $a.cpp
    echo "$b\n\n"
done