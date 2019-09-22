#include<iostream>
#include<algorithm> 
#include<cmath>
using namespace std;

//丙的值可以是小数
 
void out(int m, double tmp) {
	if (m > tmp) {
		cout << " Gai";
	}
	else if (m < tmp) {
		cout << " Cong";
	}
	else {
		cout << " Ping";
	}
}

int main() {
	int m,x,y;
	cin >> m >> x >> y;
	int x1,x2;
	int flag = 0;
	for (x1=9;x1>=1;x1--) {
		for (x2=9;x2>=0;x2--) {
			if (((10*x2+x1)*1.0/y) == (abs(9*x1-9*x2)*1.0/x)) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (!flag) {
		cout << "No Solution" << endl;
	}
	else {
		cout << 10*x1+x2;
		out(m, 10*x1+x2);
		out(m, 10*x2+x1);
		out(m, (10*x2+x1)*1.0/y);
	}
	return 0;
}
