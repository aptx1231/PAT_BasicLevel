#include<cstdio>
#include<cstring>
 
char a[1000005];
char b[1000005];
int f[150];

int main() {
	fgets(a,1000005,stdin);
	fgets(b,1000005,stdin);
	for (int i=0;a[i]!='\0';i++) {
		if (a[i] == '\n') {
			continue;
		}
		if (f[a[i]] == 0) {
			printf("%c",a[i]);
			f[a[i]] = 1;
		}
	}
	for (int i=0;b[i]!='\0';i++) {
		if (b[i] == '\n') {
			continue;
		}
		if (f[b[i]] == 0) {
			printf("%c",b[i]);
			f[b[i]] = 1;
		}
	}
	return 0;
} 
