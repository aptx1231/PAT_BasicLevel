#include<cstdio>

int main() {
	int m;
	scanf("%d",&m);
	int t;
	while (m--) {
		scanf("%d",&t);
		int i;
		for (i=1;i<10;i++) {
			int ans = t*t*i;
			int flag = 1;
			int tmp = t;
			while(tmp) {
				if (tmp%10 != ans%10) {
					flag = 0;
					break;
				}
				tmp /= 10;
				ans /= 10;
			}
			if (flag) {
				printf("%d %d\n",i,t*t*i);
				break;
			}
		}
		if (i==10) {
			printf("No\n");
		}
	}
	return 0;
} 
