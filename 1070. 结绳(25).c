#include<stdio.h>

void InsertSort(int a[],int n)
{
    int i,j,tmp;
    for(i=1;i<n;i++){
        tmp=a[i];
        for(j=i;j>0&&a[j-1]>tmp;j--){
            a[j]=a[j-1];
        }
        a[j]=tmp;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    InsertSort(a,n);
    double sum=a[0];
    for(i=1;i<n;i++){
        sum+=a[i];
        sum/=2.0;
    }
    printf("%d",(int)sum);
}
