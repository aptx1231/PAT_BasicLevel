#include<stdio.h>

int main()
{
    int n,m;
    int i,j,k,l;
    scanf("%d %d",&n,&m);
    int num[m];
    for(i=0;i<m;i++){
        scanf("%d",&num[i]);
    }
    char name[20];
    int cnt_name=0,cnt_ob=0,flag=0,tmp;
    for(i=0;i<n;i++){
        scanf("%s",name);
        scanf("%d",&k);
        flag=0;
        for(j=0;j<k;j++){
            scanf("%d",&tmp);
            for(l=0;l<m;l++){
                if(tmp==num[l]){
                    if(flag==0){
                        printf("%s:",name);
                        cnt_name++;
                    }
                    printf(" %04d",tmp);//占4位 补0占位
                    cnt_ob++;
                    flag=1;
                }
            }
        }
        if(flag==1){
            printf("\n");
        }
    }
    printf("%d %d",cnt_name,cnt_ob);
    return 0;
}

