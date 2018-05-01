#!/bin/python3

import os
import sys

def hcf(a, b):
    while (a>0 and b>0):
        if a>=b :
            a=a%b
        else:
            b=b%a
    return a+b

def lcm(a, b):
    return (a * b) / hcf(a, b) 



def getTotalX(a, b):
    
    hcf_b=0
    for i in b:
        hcf_b = hcf( hcf_b , i)
    #print("hcf of array B =" + hcf_b)
    
    lcm_a = 1
    for i in a:
        lcm_a= lcm( lcm_a , i)
        if lcm_a > hcf_b :
            return 0
    
    if (hcf_b % lcm_a != 0):
        return 0
    #print( "lcm of array a= " + lcm_a)
    
    value= hcf_b / lcm_a
    
    max_val= max(lcm_a, value)
    totalX =1
    
    for i in range(int(lcm_a), int(hcf_b)):
        if (hcf_b % i == 0) and (i % lcm_a == 0):
            totalX += 1
    return totalX
        
    
    

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    a = list(map(int, input().rstrip().split()))

    b = list(map(int, input().rstrip().split()))

    total = getTotalX(a, b)

    f.write(str(total) + '\n')

    f.close()
