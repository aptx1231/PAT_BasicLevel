#include<stdio.h>

struct node{
    int data;
    int next;
}a[100010],b[100010];

void Read(int num)
{
    int i;
    int poi,next,data;
    for(i=0;i<num;i++){
        scanf("%d %d %d",&poi,&data,&next);
        a[poi].data=data;
        a[poi].next=next;
    }
}

void printb(int begin)
{
    int poi=begin;
    while(poi!=-1){
        if(b[poi].next!=-1)
            printf("%05d %d %05d\n",poi,b[poi].data,b[poi].next);
        else
            printf("%05d %d -1\n",poi,b[poi].data);
        poi=b[poi].next;
    }
}

void Move(int begin,int k,int new_begin)
{
    int poi;
    int flag=0;
    int last_poi=-1;
    poi=begin;
    while(poi!=-1){
        if(a[poi].data<0){
            if(flag==0) new_begin=poi;
            else b[last_poi].next=poi;
            b[poi].data=a[poi].data;
            last_poi=poi;
            flag=1;
        }
        poi=a[poi].next;
    }
    poi=begin;
    while(poi!=-1){
        if(a[poi].data>=0&&a[poi].data<=k){
            if(flag==0) new_begin=poi;
            else b[last_poi].next=poi;
            b[poi].data=a[poi].data;
            last_poi=poi;
            flag=1;
        }
        poi=a[poi].next;
    }
    poi=begin;
    while(poi!=-1){
        if(a[poi].data>k){
            if(flag==0) new_begin=poi;
            else b[last_poi].next=poi;
            b[poi].data=a[poi].data;
            last_poi=poi;
            flag=1;
        }
        poi=a[poi].next;
    }
    b[last_poi].next=poi;
    printb(new_begin);
}

int main()
{
    int begin,num,k;
    scanf("%d %d %d",&begin,&num,&k);
    Read(num);
    int new_begin=-1;
    Move(begin,k,new_begin);
    return 0;
}
