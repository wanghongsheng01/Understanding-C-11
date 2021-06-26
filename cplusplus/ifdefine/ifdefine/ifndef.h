//
//  ifndef.h
//  ifdefine
//
//  Created by hswang on 2021/6/26.
//

#ifndef ifndef_h
#define ifndef_h
class ifndef;
/**
 C/C++中关于 #ifndef 和 #endif 的详解:
 
 “头文件中的 #ifndef/#define/#endif 防止该头文件被重复引用”
 
 其实“被重复引用”是指一个头文件在同一个cpp文件中被include了多次，这种错误常常是由于include嵌套造成的。

 比如：存在a.h文件#include "c.h"而此时b.cpp文件导入了#include "a.h" 和#include "c.h"

 此时就会造成c.h重复引用。
 
 是不是所有的头文件中都要加入#ifndef/#define/#endif 这些代码？

     答案：不是一定要加，但是不管怎样，用 #ifnde xxx  #define xxx #endif 或者其他方式避免头文件重复包含，只有好处没有坏处。个人觉得培养一个好的编程习惯是学习编程的一个重要分支。
 
 下面给一个#ifndef/#define/#endif的格式：

 #ifndef A_H意思是"if not define a.h"  如果不存在a.h

 接着的语句应该#define A_H  就引入a.h

 最后一句应该写#endif   否则不需要引入
 
 #ifndef GRAPHICS_H // 防止graphics.h被重复引用

 #define GRAPHICS_H

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
 */

#endif /* ifndef_h */
