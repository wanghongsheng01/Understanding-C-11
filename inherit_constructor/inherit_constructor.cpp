struct A{
	A(int i){}
	A(double d, int i){}
	A(float a, int i, const char* c){}
};

struct B : A{
	using A::A; // 继承构造函，使用 using 声明，将基类中的构造函数继承到派生类中
	virtual voidExtraInterface(){}

};

int main(){
	B b;
	b();


	return 0;
}