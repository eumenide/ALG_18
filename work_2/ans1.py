#!/usr/bin/env python
# coding=utf-8

# @file ans1.py
# @brief ans1
# @author Anemone95,x565178035@126.com
# @version 1.0
# @date 2018-12-26 14:23
import copy

X="1A2BD3G4H56JK"
Y="23EFG4I5J6K7"

res=set()
def ans1(x, y):
    cache=[]
    for i in range(len(x)):
        cache.append([-1 for _ in range(len(y))])
    dp(x,y,len(x)-1,len(y)-1,cache)
    get_ans(x,y,len(x)-1,len(y)-1,[],cache)
    for each in res:
        print(each + "0")

def dp(x, y, x_pos, y_pos, cache):
    if x_pos==-1 or y_pos==-1:
        return 0
    if cache[x_pos][y_pos]!=-1:
        return cache[x_pos][y_pos]
    ret=0
    if x[x_pos]==y[y_pos]:
        ret=dp(x,y,x_pos-1,y_pos-1,cache)+1
    else:
        ret=max(dp(x,y,x_pos,y_pos-1,cache), dp(x,y,x_pos-1,y_pos,cache))
    cache[x_pos][y_pos]=ret
    return ret


def get_ans(x, y, x_pos, y_pos, ret, cache):
    global res
    ret1=[]
    i,j=x_pos,y_pos
    while True:
        if i<0 or j<0:
            break
        if x[i]==y[j]:
            ret=[x[i]]+ret
            i-=1
            j-=1
        else:
            if dp(x,y,i-1,j,cache)==dp(x,y,i,j,cache):
                ret1=copy.copy(ret)
                get_ans(x,y,i-1,j,ret,cache)
                ret=ret1
            if dp(x,y,i,j-1,cache)==dp(x,y,i,j,cache):
                ret1=copy.copy(ret)
                get_ans(x,y,i,j-1,ret,cache)
                ret=ret1
            return
    res.add("".join(ret))

if __name__ == '__main__':
    X=input()
    Y=input()
    # X="a j"
    # Y="b kj"
    ans1(X,Y)

