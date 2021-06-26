#include <cstring>
using namespace std;

template <typename t, typename u> int bit_copy(t& a, u& b){
	static_assert(
		sizeof(b) == sizeof(a),
		"the two parameters of bit_copy must have the same width."
		);
}

int main(){
	int a = 0x2468;
	double b;
	bit_copy(a, b);
}