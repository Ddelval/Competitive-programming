#bin/bash


#A="$(ls)"
#for a in $A
#do
#    b="$( ls $a/| grep -v ".cpp")"
#    #mv $a/$a/main.cpp $a.cpp
#    for c in $b
#    do
#        echo "$a/$c/$c/main.cpp\n\n"
#        mv $a/$c/$c/main.cpp $a/$c.cpp
#    done 
#    
#done

IFS=$'\n'
#A=$(find . -name "*.cpp"|grep -v "xcode"| sed  's_/[0-9]*/__p'| sed 's_^.__p'| sed 's_main__p'| sed 's_/__p'| uniq)
A="$(ls| grep -e '^[0-9][0-9][0-9][0-9]_' ) "
arr=($A)
#B=$(find . -name "*.cpp"|grep -v "xcode"| sed 's_^./__p'|uniq)
arr2=($B)
for a in $A
do
    mv $a 0$a
done 