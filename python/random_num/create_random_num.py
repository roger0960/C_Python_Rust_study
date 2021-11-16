#!/usr/bin/python
# coding=utf-8

#python生成随机数很简单,不用像楼上那么麻烦,具体方法如下
import random
import string
import os

random_name = ""
while len(random_name) < 10:
    # s = string.ascii_letters # 所有大小写字母(a-z,A-Z)
    # a = random.choice(s) # 在s列表中随机挑选一个成员
    random_name = random_name + random.choice(string.ascii_letters)
print random_name
os.system("mkdir " + random_name);
os.system("rm -r " + random_name);
