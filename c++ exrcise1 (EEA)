/*
*Author: Dursun Oylum Seriner
*Id Number: 2022697
*IAM511 HW3-Extended Euclidean Algorithm
*My operating system:Win10
*I used the online compiler.
*https://www.onlinegdb.com/online_c++_compiler
*Also, this code work on Ubuntu.
*Ubuntu 20.04
*/



#include <iostream>
#include <vector>

using namespace std;

void gcd(long int a, long int b) {
	long int real_b = b;
	cout << "For the inputs (" << a << ", " << b << ")" << endl;
	a = a % b;
	vector<long int> vec;
    long int t;
    while (b != 0) {
		vec.push_back(a / b);
		t = a;
		a = b;
		b = t % b;
	}
	cout << "GCD is: " << a << endl;
	if(a != 1) {
		cout << "There is no inverse since gcd is not equal to 1." << endl;
		cout << "**************************" << endl;
		return;
	}
	int i = vec.size() - 2;
	long int u = 1, v = -1 * vec[i];
	i--;
	while(i >= 0) {
		t = u;
		u = v;
		v = t - vec[i] * v;
		i--;
	}
	cout << "u: " << u << endl;
	cout << "v: " << v << endl;
	while(u < 0) {
		u += real_b;
	}
	u = u % real_b;
	cout << "Inverse exists." << endl;
	cout << "Inverse is: " << u << endl;
	cout << "**************************" << endl;
}

int main() {
    long int a;
    long int b;
	cin >> a >> b;
	if(a == 0 || b == 0) {
		cout << "Erroneous inputs: " << a << ", " << b << endl;
	}
	gcd(a, b);
	return 0;
}
