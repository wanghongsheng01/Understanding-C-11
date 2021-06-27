#include "test.h"
#include<iostream>
using namespace std;

template void fun<int>(int);

void test1(){
	fun(3);
}

