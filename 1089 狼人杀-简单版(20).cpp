#include<cstdio>

struct node {
	int id;
	int tf; //0���� 1���� 
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
	//ö��i,j�������� ����������� 
	int lie[105]; //˵�ѵ��� 
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			//���������˵����� �ҵ�˵�ѵ��� 
			int tmp=0;
			for (int k=1;k<=n;k++) {
				if (a[k].tf == 0) { //k˵a[k].id������ 
					if (a[k].id != i && a[k].id != j) {
						lie[tmp++] = k;  //k˵�� 
					} 
				}
				else {  //k˵a[k].id�Ǻ��� 
					if (a[k].id == i || a[k].id == j) {
						lie[tmp++] = k;  //k˵�� 
					}
				} 
			}
			//ֻ��������˵�� ����һ�������� һ���Ǻ��˲��� 
			if (tmp == 2) {
				//lie[0]������ lie[1]�Ǻ��� 
				if ((lie[0] == i || lie[0] == j) && (lie[1] != i && lie[1] != j)) {
					printf("%d %d\n",i,j);
					return 0;
				} 
				//lie[1]������ lie[0]�Ǻ��� 
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
