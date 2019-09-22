#include<cstdio>
#include<vector>
using namespace std;

vector<int> a[100000];

int find(int i, int t) {
	for (int j=0;j<a[i].size();j++) {
		if (a[i][j] == t) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int t1,t2;
	for (int i=0;i<n;i++) {
		scanf("%d %d",&t1,&t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	int k;
	int b[1005];
	while (m--) {
		scanf("%d",&k);
		for (int i=0;i<k;i++) {
			scanf("%d",&b[i]);
		}
		int f = 0;
		//遍历任意两个点 
		for (int i=0;i<k;i++) {
			for (int j=i+1;j<k;j++) {
				//find也不是O(1)的 需要遍历一条链 
				if (find(b[i], b[j])) {
					f = 1;
					printf("No\n");
					break;
				}
			}
			if (f) {
				break;
			}
		}
		if (!f) {
			printf("Yes\n");
		}
	}
	return 0;
}
