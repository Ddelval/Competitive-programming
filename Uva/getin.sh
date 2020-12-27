#!/bin/bash

problem="$(wget -O - -o /dev/null $1 | pdftotext - - -layout)"

start=$(echo "$problem" | grep -n "^Sample Input" | awk -F: '{print $1}')
end=$(echo "$problem" | grep -n "^Sample Output" | awk -F: '{print $1}')
echo "$problem" | head -n$(($end-1)) | tail -n$(($end-$start-1))>pin.in