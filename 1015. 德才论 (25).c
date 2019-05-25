#include<stdio.h>
#include<stdlib.h>

struct stu{
    int num;
    int de;
    int ca;
    int sum;
}a1[100009],a2[100009],a3[100009],a4[100009];

int compare(const void *a,const void *b)
{
    int k;
    if(((const struct stu*)a)->sum<((const struct stu*)b)->sum){
        k=1;
    }
    else if(((const struct stu*)a)->sum>((const struct stu*)b)->sum){
        k=-1;
    }
    else{
        if(((const struct stu*)a)->de<((const struct stu*)b)->de){
            k=1;
        }
        else if(((const struct stu*)a)->de>((const struct stu*)b)->de){
            k=-1;
        }
        else{
            if(((const struct stu*)a)->num>((const struct stu*)b)->num){
                k=1;
            }
            else if(((const struct stu*)a)->num<((const struct stu*)b)->num){
                k=-1;
            }
        }
    }
    return k;
}

void print(struct stu a[],int l)
{
    int i;
    for(i=0;i<l;i++){
        printf("%d %d %d\n",a[i].num,a[i].de,a[i].ca);
    }
}

int main()
{
    int n,min,max;
    scanf("%d %d %d",&n,&min,&max);
    int i;
    int num,de,ca;
    int cnt=0;
    int l1,l2,l3,l4;
    l1=l2=l3=l4=0;
    for(i=0;i<n;i++){
        scanf("%d %d %d",&num,&de,&ca);
        if(de>=min&&ca>=min){
            cnt++;
            if(de>=max&&ca>=max){
                a1[l1].num=num;
                a1[l1].de=de;
                a1[l1].ca=ca;
                a1[l1].sum=de+ca;
                l1++;
            }
            else if(de>=max&&ca<max){
                a2[l2].num=num;
                a2[l2].de=de;
                a2[l2].ca=ca;
                a2[l2].sum=de+ca;
                l2++;
            }
            else if(de<max&&ca<max&&de>=ca){
                a3[l3].num=num;
                a3[l3].de=de;
                a3[l3].ca=ca;
                a3[l3].sum=de+ca;
                l3++;
            }else{
                a4[l4].num=num;
                a4[l4].de=de;
                a4[l4].ca=ca;
                a4[l4].sum=de+ca;
                l4++;
            }
        }
    }
    printf("%d\n",cnt);
    qsort(a1,l1,sizeof(struct stu),compare);
    qsort(a2,l2,sizeof(struct stu),compare);
    qsort(a3,l3,sizeof(struct stu),compare);
    qsort(a4,l4,sizeof(struct stu),compare);
    print(a1,l1);
    print(a2,l2);
    print(a3,l3);
    print(a4,l4);
    return 0;
}
