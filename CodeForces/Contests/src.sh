#bin/bash


A="$(ls)"
for a in $A
do
    b="$( ls $a/| grep -v ".cpp")"
    #mv $a/$a/main.cpp $a.cpp
    for c in $b
    do
        echo "$a/$c/$c/main.cpp\n\n"
        mv $a/$c/$c/main.cpp $a/$c.cpp
    done 
    
done