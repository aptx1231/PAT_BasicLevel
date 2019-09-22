#include<iostream>
#include<algorithm> 
using namespace std;

int a[11000]; //×î´óÖµ10000/2+10000/3+10000/5=10333 

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i=1;i<=n;i++) {
		int tmp = i/2+i/3+i/5;
		//cout << tmp << endl;
		if (a[tmp] == 0) {
			a[tmp] = 1;
			cnt++;
		}
	}	
	cout << cnt << endl;
	return 0;
}
