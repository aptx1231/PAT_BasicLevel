#include<stdio.h>
#include<string.h>

int judge(int a[],int len)
{
    int i,j;
    for(i=0,j=len-1;i<j;i++,j--){
        if(a[i]!=a[j])
            return 0;
    }
    return 1;
}

int main()
{
    char a[1009];
    int b[1009];//ԭ˳��
    int c[1009];//����
    int ans[1009]={0};//������1000λ ���ǼӺͿ��Գ���1000λ������
    gets(a);
    int i,j;
    for(i=0;a[i]!='\0';i++){
        ans[i]=a[strlen(a)-i-1]-'0';
    }
    i--;//���ֱ�Ӿ��ǻ����� ��ӡi--Ϊ�˺ͺ�ߵĴ�ӡ����һ�� i��ans���λ
    int len=strlen(a),cnt=0;
    while(1){
        if(judge(ans,len)==1||cnt>=10) break;//���ж� ֱ�Ӿ��ǻ�����������͵���
        for(i=0;i<len;i++){
            b[i]=ans[len-i-1];
        }
        for(i=0;i<len;i++){
            c[i]=ans[i];
        }
        for(i=0;i<=len;i++){
            ans[i]=0;
        }
        for(i=len-1;i>=0;i--){
            printf("%d",c[i]);
        }
        printf(" + ");
        for(i=len-1;i>=0;i--){
            printf("%d",b[i]);
        }
        printf(" = ");
        for(j=0;j<len;j++){
            ans[j]+=(b[j]+c[j]);
            if(ans[j]>=10){
                ans[j+1]+=ans[j]/10;
                ans[j]%=10;
            }
        }
        //��ӡans
        for(i=j;i>=0;i--){
            if(ans[i]) break;//i��ans���λ
        }
        if(i<0){
            len=1;
            printf("0");
        }
        else {
            for(j=i;j>=0;j--){
                printf("%d",ans[j]);
            }
            len=i+1;
        }
        cnt++;
        printf("\n");
    }
    if(cnt<10){
        if(i<0){
            printf("0");
        }
        else {
            for(j=i;j>=0;j--){
                printf("%d",ans[j]);
            }
        }
        printf(" is a palindromic number.\n");
    }
    else{
        printf("Not found in 10 iterations.\n");
    }
    return 0;
}
