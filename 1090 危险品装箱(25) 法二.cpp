#include<cstdio>
#include<vector>
using namespace std;

//����һЩ 
 
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
        int dd[100000] = {0};  //�ռ任ʱ�� ���ڱ�����еĵ� �ĸ�������� 
        for (int i=0;i<k;i++) {
            scanf("%d",&b[i]);
            dd[b[i]] = 1;  //��� 
        }
        int f = 0;
        for (int i=0;i<k;i++) {  //����K���� 
            for (int j=0;j<a[b[i]].size();j++) {  //������b[i]�����ĵ� 
                if (dd[a[b[i]][j]] == 1) { //�������㱻����� ˵�������� 
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
