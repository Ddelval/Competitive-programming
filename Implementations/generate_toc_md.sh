#!/bin/bash
pandoc --toc  --toc-depth=2 --template=toc-only  \
Range_Queries/range_queries.tex \
Strings/strings.tex \
Graphs/graphs.tex \
Mathematics/maths.tex \
Strings/strings.tex \
Geometry/geometry.tex \
--to markdown \
|
sed -e "s/\(#.*\)//g" -e "s/\[//g" -e "s/\]//g" -e "s/($//g" >toc.md
