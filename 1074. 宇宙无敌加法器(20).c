#include<stdio.h>
#include<string.h>
int main()
{
    int num[21]={0},num1[21]={0},num2[21]={0};
    int res[22]={0};
    int i,j;
    char a[21],a1[21],a2[21];
    scanf("%s",a);
    getchar();
    scanf("%s",a1);
    getchar();
    scanf("%s",a2);
    getchar();
    for(i=0;i<strlen(a);i++){
        num[strlen(a)-i-1]=a[i]-'0';
    }
    for(i=0;i<strlen(a1);i++){
        num1[strlen(a1)-i-1]=a1[i]-'0';
    }
    for(i=0;i<strlen(a2);i++){
        num2[strlen(a2)-i-1]=a2[i]-'0';
    }
    int max=strlen(a1);
    if(strlen(a2)>max){
        max=strlen(a2);
    }
    for(i=0;i<max;i++){
        res[i]+=(num1[i]+num2[i]);

        if(num[i]){
            res[i+1]+=(res[i]/num[i]);
            res[i]%=num[i];
        }
        else{
            res[i+1]=(res[i]/10);
            res[i]%=10;
        }
    }
    for(j=i;j>=0;j--){
        if(res[j]){
            break;
        }
    }
    int flag=0;
    for(i=j;i>=0;i--){
        printf("%d",res[i]);
        flag=1;
    }
    if(flag==0) printf("0");
    return 0;
}

