C 编译混编 __cplusplus 的过程

编译指令：
`
gcc -E main.c -o main.i
`
将混编代码 main.c
```.c

#ifdef __cplusplus
extern "C" {
#endif


// insert code here...
void print(){
    printf("gcc compile ...");
}

#ifdef __cplusplus
}
#endif
```
编译成 main.i
```.i
# 9 "main.c" 2
# 1 "./mix_code.h" 1
# 17 "./mix_code.h"
void print(){
    printf("gcc compile ...");
}


```
