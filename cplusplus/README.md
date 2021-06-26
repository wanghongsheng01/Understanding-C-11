## ifndef 和 endif
头文件中的 #ifndef XXX_H -> #define XXX_H -> #endif 防止该头文件被重复引用
```.h
#ifndef GRAPHICS_H // 防止graphics.h被重复引用，ifndef A_H意思是"if not define a.h"  如果不存在a.h

#define GRAPHICS_H // #define A_H  就引入a.h

#include <math.h> // 引用标准库的头文件

…

#include “header.h” // 引用非标准库的头文件

…

void Function1(…); // 全局函数声明

…

class Box // 类结构声明

{

…

};

#endif


```

## 被重复引用
是指一个头文件在同一个cpp文件中被include了多次，这种错误常常是由于include嵌套造成的。

比如：存在a.h文件#include "c.h"而此时b.cpp文件导入了#include "a.h" 和#include "c.h"

此时就会造成c.h重复引用。

## 头文件被重复引用的后果

有些头文件重复引用只是增加了编译工作的工作量，不会引起太大的问题

仅仅是编译效率低一些，但是对于大工程而言编译效率低下那将是一件多么痛苦的事情。

有些头文件重复包含，会引起错误，比如在头文件中定义了全局变量(虽然这种方式不被推荐，但确实是C规范允许的)这种会引起重复定义。
