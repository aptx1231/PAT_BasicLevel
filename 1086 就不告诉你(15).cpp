#include<iostream>
#include<algorithm> 
using namespace std;

int main() {
	int a;
	int b;
	cin >> a >> b;
	int c = a*b;
	if (c == 0) {
		cout << 0;
		return 0;
	}
	int flag = 0;
	while (c) {
		if (c%10 || flag) {
			cout << c%10;
			flag = 1;
		}
		c /= 10;
	}
	return 0;
}
