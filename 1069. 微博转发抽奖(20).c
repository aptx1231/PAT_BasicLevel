#include<stdio.h>
#include<string.h>
int main()
{
    int m,n,s;
    scanf("%d %d %d",&m,&n,&s);
    if(m<s){
        printf("Keep going...");
        return 0;
    }
    int i;
    char a[1001][21];
    char c[1001][21];
    for(i=0;i<m;i++){
        scanf("%s",a[i]);
    }
    int j=0,k;
    for(i=s-1;i<m;){
        int flag=1;
        for(k=0;k<j;k++){
            if(strcmp(c[k],a[i])==0){
                flag=0;
            }
        }
        if(flag){
            printf("%s\n",a[i]);
            strcpy(c[j++],a[i]);
            i+=n;
        }
        else{
            i++;
        }
    }
    return 0;
}

