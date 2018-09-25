"""
python基础题，在面试前程无忧python工程师的时候出的一道基础的编程题。当时不会做，真的，python基础确实没怎么注重。
接下来除了刷算法题，也学一下python基础。

请分别写出result1~result5的值：
-----------------------------------------
def some_func():
    try:
        return 'from_try'
    finally:
        return 'from_finally'

result1 = some_func()                 <1>      
-----------------------------------------
def some_func(default_arg = []):
    default_arg.append("some_string")
    return default_arg
result2 = some_func()                 <2>
result3 = some_func()                 <3>
result4 = some_func([])               <4>
result5 = some_func()                 <5>
------------------------------------------
"""

__author__ = Qiufeng

def some_func1():
    try:
        return 'from_try'
    finally:
        return 'from_finally'

result1 = some_func1()
print("result1 =",result1)

def some_func(default_arg = []):
    default_arg.append("some_string")
    return default_arg
result2 = some_func()
print("result2 =",result2)
result3 = some_func()
print("result3 =",result3)
result4 = some_func([])
print("result4 =",result4)
result5 = some_func()
print("result5 =",result5)

#输出,电脑上运行后
"""
result1 = from_finally
result2 = ['some_string']
result3 = ['some_string', 'some_string']
result4 = ['some_string']
result5 = ['some_string', 'some_string', 'some_string']
""
