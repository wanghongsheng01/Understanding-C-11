struct A{
	A(int){}
};

struct B: A{
	using A:A;
};

int main(){
	B b; // B 没有默认构造函数，由于 B 使用了继承构造函数
	return 0;
}
