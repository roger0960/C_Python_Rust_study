#!/usr/bin/python3

import sys
import os

file_path = sys.argv[1]

count=0
num=0
val={}
while count < len(file_path):
    if file_path[count] == '/':
        num += 1
        val[num] = count
    count += 1

print(len(val))
if len(val) == 0:
    filepath = './'
    filename = file_path
else:
    filepath = file_path[0:val[num]+1]
    filename = file_path[val[num]+1:]
print(filepath)
print(filename)
