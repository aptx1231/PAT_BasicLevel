#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char c=getchar();
    if(c=='-') printf("%c",c);
    char a[10000];
    scanf("%s",a);
    int i,j=0;
    char str[10000];
    for(i=0;;i++){
        //if(a[i]=='.') continue;
        if(a[i]=='E') break;
        str[j++]=a[i];
    }
    str[j]='\0';
    //printf("%d\n",strlen(str));
    int n=(int)atof(a+2+strlen(str));
    //printf("n=%d",n);
    //printf("%s",str);
    if(a[i+1]=='+'){
        printf("%c",str[0]);
        if(n+2<strlen(str)){
            for(j=2;j<n+2;j++){
                printf("%c",a[j]);
            }
            printf(".");
            for(j=n+2;j<strlen(str);j++){
                printf("%c",str[j]);
            }
        }
        else{
            for(j=2;j<strlen(str);j++){
                printf("%c",str[j]);
            }
            for(j=strlen(str);j<n+2;j++){
                printf("0");
            }
        }
    }
    else if(a[i+1]=='-'){
        printf("0.");
        for(j=0;j<n-1;j++){
            printf("0");
        }
        for(j=0;j<strlen(str);j++){
            if(str[j]!='.'){
                printf("%c",str[j]);
            }
        }
    }
    return 0;
}

