#include<cstdio>
#include<vector>
using namespace std;

//更快一些 
 
vector<int> a[100000];

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
        int dd[100000] = {0};  //空间换时间 用于标记所有的点 哪个是特殊的 
        for (int i=0;i<k;i++) {
            scanf("%d",&b[i]);
            dd[b[i]] = 1;  //标记 
        }
        int f = 0;
        for (int i=0;i<k;i++) {  //遍历K个点 
            for (int j=0;j<a[b[i]].size();j++) {  //遍历与b[i]相连的点 
                if (dd[a[b[i]][j]] == 1) { //如果这个点被标记了 说明有问题 
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
