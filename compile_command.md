C/C++ 编译过程<br>
* GNU 是 C/C++ 的编译器，编译 C 的调用指令是 gcc，编译 C++ 的调用指令是 g++

编译过程分为 4 步：<br>
1. 预处理<br>
  展开所有的以#开始的预编译指令,过滤注释,加入行号,引入头文件,生成 xx.i文件<br>
  * C++ 预处理指令<br>
  `g++ -E main.cpp -o main.i`
  * 示例<br>
  main.cpp
  ```.cpp
  //
//  main.cpp
//  MixedCoding
//
//  Created by hswang on 2021/6/26.
//

#include <iostream>
#include "__cplusplus.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    print();
    std::cout << "Hello, World!\n";
    return 0;
}
  ```
  
  __cplusplus.h
  ```.h
  //
//  __cplusplus.h
//  MixedCoding
//
//  Created by hswang on 2021/6/26.
//

#ifndef __cplusplus_h
#define __cplusplus_h


#ifdef __cplusplus
extern "C" {
#endif


// insert code here...
void print(){
    std::cout<<"print ..."<<std::endl;
}


#ifdef __cplusplus
}
#endif


#endif /* __cplusplus_h */

  ```
  main.i 
  ```.i
  ...
# 9 "main.cpp" 2
# 1 "./__cplusplus.h" 1
# 13 "./__cplusplus.h"
extern "C" {




void print(){
    std::cout<<"print ..."<<std::endl;
}



}
# 10 "main.cpp" 2

int main(int argc, const char * argv[]) {

    print();
    std::cout << "Hello, World!\n";
    return 0;
}

  ```
2. 编译<br>
  进行 词法/语法/语义 分析，优化生成汇编文件 .s<br>
  * C++ 编译指令<br>
  `g++ -S main.i -o main.s`
  * 示例<br>
  main.s
  ```.s
  	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	32(%rax), %ecx
	orl	-12(%rbp), %ecx
	movq	%rax, %rdi
	movl	%ecx, %esi
	callq	__ZNSt3__18ios_base5clearEj
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"print ..."

L_.str.1:                               ## @.str.1
	.asciz	"Hello, World!\n"

.subsections_via_symbols
  ```
3. 汇编<br>
  将编译文件 *.s 通过 AS 汇编成目标文件 *.o<br>
  * C++ 汇编指令<br>
  `g++ -fPIC -o main.o -c main.cpp`
  * 示例<br>
  main.o
  ```.o
  ...
6534 3500 5f5f 5f67 7878 5f70 6572 736f
6e61 6c69 7479 5f76 3000 4743 435f 6578
6365 7074 5f74 6162 6c65 3430 0000 0000
  ```
7. 链接<br>
  把一些指令对其它符号地址的引用加以修正,包括地址和空间分配、符号决议、重定位等过程,将`目标文件和库`一起链接形成最终可执行文件.<br>
  * C++ 链接指令<br>
  ` g++ main.o -o main`
  * 示例<br>
  main
  ```
4c39 7573 655f 6661 6365 7449 4e53 5f35
6374 7970 6549 6345 4545 4552 4b54 5f52
4b4e 535f 366c 6f63 616c 6545 005f 5f5a
4e4b 5374 335f 5f31 3563 7479 7065 4963
4535 7769 6465 6e45 6300 5f5f 5a4e 5374
335f 5f31 3869 6f73 5f62 6173 6538 7365
7473 7461 7465 456a 0047 4343 5f65 7863
6570 745f 7461 626c 6535 0047 4343 5f65
7863 6570 745f 7461 626c 6538 0047 4343
5f65 7863 6570 745f 7461 626c 6534 3000
4743 435f 6578 6365 7074 5f74 6162 6c65
3435 005f 5f64 796c 645f 7072 6976 6174
6500 0000 0000 0000 
  ```
 8. 运行可执行文件 main
 `./main`
 输出
 `print ...<br>
  Hello, World!`
  
  ## 总结
  * 一步到位编译生成可执行文件<br>
  `g++ main.cpp -std=c++11 -Wall -o main`<br>
  
  * 分步编译<br>
  预处理 -> `g++ -E main.cpp -o main.i`<br>
  编译 -> `g++ -S main.i -o main.s`<br>
  汇编 -> `g++ -fPIC -o main.o -c main.cpp`<br>
  链接 ->  ` g++ main.o -o main`<br>
  
  
  
  
  [参考资料](https://blog.csdn.net/guochangfei/article/details/81562144)
  [C++：C/C++源文件从文本变成可执行文件的过程](https://blog.csdn.net/qq_42441693/article/details/104180660)
