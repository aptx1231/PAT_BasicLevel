#include<cstdio>

char a[1005];

int isprime(int n) {
	if (n == 2) {  //±ß½ç 2ÊÇËØÊı 
		return 1;
	}
	for (int i=2;i*i<=n;i++) {
		if (n%i == 0) {
			return 0;
		}
	}	
	return 1;
}

int main() {
	int l,k;
	scanf("%d %d",&l,&k);
	scanf("%s",a);
	int f = 0;
	for (int i=0;i+k-1<l;i++) {
		int num = 0;
		for (int j=i;j<=i+k-1;j++) {
			num = num * 10 + (a[j] - '0');
		}
		if (isprime(num)) {
			for (int l=i;l<=i+k-1;l++) {
				printf("%c", a[l]);
			}
			printf("\n");
			//printf("%d\n",num);
			f = 1;
			break;
		}
	}
	if (!f) {
		printf("404\n");
	}
	return 0;
}
