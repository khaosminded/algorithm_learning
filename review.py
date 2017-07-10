# -*- coding: utf-8 -*-
def yang():
    L=[1]
    while True:
        yield L
        L.append(0)
        for i in range(1,len(L)):
            L[-i]=L[-i]+L[-i-1]
        
    return 'done'

def test():
    n=0
    for t in yang():
        print(t)
        n=n+1
        if n==10:
            break
    return 0
    
'''
1 2 1 0
      (1,4)
      i=1 2 3
      i=1
      L[-1]=L[-1]+[0]

'''
import time


def log(func):
    def wrapper(*args,**kw):
        print('call %s():'% func.__name__)
        return func(*args,**kw)
    return wrapper
def log2(text):
    def decorator(func):
        def wrapper(*args,**kw):
            print(text+':%s()'% func.__name__)
            return func(*args,*kw)
        return wrapper
    return decorator



def now():
    print(time.strftime('%Y-%m-%d %X',time.localtime()))

now=log2('excute')(now)
