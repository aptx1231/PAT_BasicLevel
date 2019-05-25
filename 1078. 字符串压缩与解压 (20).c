#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void f1()
{
    char a[1000];
    gets(a);
    int i,cnt;
    for(i=0;i<strlen(a);i++){
        cnt=1;
        while(a[i]==a[i+1]){
            cnt++;
            i++;
        }
        if(cnt!=1){
            printf("%d%c",cnt,a[i]);
        }
        else{
            printf("%c",a[i]);
        }
    }
}

void f2()
{
    char a[1000];
    char n[1000]={'\0'};
    gets(a);
    int i,l,num,j;
    for(i=0;i<strlen(a);i++){
        l=0;
        while(a[i]>='0'&&a[i]<='9'){
            n[l++]=a[i++];
        }
        n[l]='\0';
        if(l>0) num=(int)atof(n);
        else num=1;
        //if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||a[i]==' '){
            for(j=0;j<num;j++){
                printf("%c",a[i]);
            }
        //}
        for(j=0;j<l+1;j++){
            n[l]='\0';
        }
    }
}

int main()
{
    char c=getchar();
    if(c=='C'){
        getchar();
        f1();
    }
    else if(c=='D'){
        getchar();
        f2();
    }
    return 0;
}

