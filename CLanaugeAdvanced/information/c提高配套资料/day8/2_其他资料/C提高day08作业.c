1. 通过宏定义实现2个数比较大小

2. 通过宏定义实现3个数比较大小

#define MAX2(a,b)    (a) > (b) ? (a) : (b)

#define MAX3(a, b, c)  (a) >  ( MAX2(b,c) )  ? (a) :  ( MAX2(b,c) )