#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Aug 27 19:56:53 2017

@author: anant_dimri
"""
import json
import os
from time import sleep

       

#reading the json file #input
data=open("/home/anant_dimri/Desktop/input.json" ,"r")
x=json.load(data)
y=x['dependencies']


 #writing the dependencies in a text file   
with open("json_dependencies.txt" ,"w+") as f:
    for k, v in y.items():
       f.write(k+"=="+v+"\n")

flag=0     
not_installed=[]


# installing dependencies
f = open('json_dependencies.txt')
line = f.readline()
while line:
    print("installing "+ line)
    cmd = "pip install "+line
    sleep(0.8)
    z=os.system(cmd)
    if z==0:
        flag=1
    elif z!=0:
        not_installed.append(line)
        continue
    line = f.readline()
f.close()

if flag:
    print("###### success ########")
elif flag==0:
    print(" ###### not installed ######## :\n")
    for elem in not_installed:
        print(elem) 





