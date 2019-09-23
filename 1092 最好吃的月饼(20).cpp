#include<cstdio>

long long a[1005];

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int t;	
	while (m--) {
		for (int i=0;i<n;i++) {
			scanf("%d",&t);
			a[i] += t;
		}
	}
	long long max = -1;
	int cnt = 1;
	for (int i=0;i<n;i++) {
		if (a[i] > max) {
			max = a[i];
			cnt = 1;  //²»ÊÇ0 
		}
		else if (a[i] == max) {
			cnt++;
		} 
	}
	printf("%lld\n",max);
	int flag = 0;
	for (int i=0;i<n;i++) {
		if (a[i] == max) {
			printf("%d",i+1);
			cnt--;
			if (cnt) {
				printf(" ");
			}
		}
	}
	return 0;
} 
