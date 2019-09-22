#include<cstdio>

struct node {
	int id;
	int tf; //0狼人 1好人 
}a[105];

int main() {
	int n;
	scanf("%d",&n);
	getchar();
	char c;
	int d;
	for (int i=1;i<=n;i++) {
		c = getchar();
		scanf("%d",&d);
		getchar();
		if (c == '+') {
			a[i].tf = 1;
		}
		else {
			a[i].tf = 0;
		}
		a[i].id = d;
	}
//	for (int i=0;i<n;i++) {
//		printf("%d %d\n", a[i].id, a[i].tf); 
//	}
	//枚举i,j代表狼人 其他代表好人 
	int lie[105]; //说谎的人 
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			//遍历所有人的描述 找到说谎的人 
			int tmp=0;
			for (int k=1;k<=n;k++) {
				if (a[k].tf == 0) { //k说a[k].id是狼人 
					if (a[k].id != i && a[k].id != j) {
						lie[tmp++] = k;  //k说谎 
					} 
				}
				else {  //k说a[k].id是好人 
					if (a[k].id == i || a[k].id == j) {
						lie[tmp++] = k;  //k说谎 
					}
				} 
			}
			//只有两个人说谎 而且一个是狼人 一个是好人才行 
			if (tmp == 2) {
				//lie[0]是狼人 lie[1]是好人 
				if ((lie[0] == i || lie[0] == j) && (lie[1] != i && lie[1] != j)) {
					printf("%d %d\n",i,j);
					return 0;
				} 
				//lie[1]是狼人 lie[0]是好人 
				if ((lie[1] == i || lie[1] == j) && (lie[0] != i && lie[0] != j)) {
					printf("%d %d\n",i,j);
					return 0;
				}
			} 
		}
	}
	printf("No Solution\n"); 
	return 0;
} 
