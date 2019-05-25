#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct per{
    char name[10];
    int height;
    int flag;
}a[10009],b[10009];

int compare(const void* a,const void* b)
{
    int k;
    if(((const struct per*)a)->height>((const struct per*)b)->height){
        k=-1;
    }
    else if(((const struct per*)a)->height<((const struct per*)b)->height){
        k=1;
    }
    else{
        if(strcmp(((const struct per*)a)->name,((const struct per*)b)->name)>0){
            k=1;
        }
        else if(strcmp(((const struct per*)a)->name,((const struct per*)b)->name)<0){
            k=-1;
        }
    }
    return k;
}

int main()
{
    int n,line;
    scanf("%d %d",&n,&line);
    int i,cnt,l,j;
    for(i=0;i<n;i++){
        scanf("%s %d",a[i].name,&a[i].height);
        a[i].flag=1;//代表没有被打印 
    }
    qsort(a,n,sizeof(struct per),compare);
    //for(i=0;i<n;i++){
    //   printf("%s %d\n",a[i].name,a[i].height);
    //}

    int ave=n/line;
    int last=ave+n%line;//最后一行 单独处理 
    int mid=last/2+1;
    int max; 
    j=0;//确定a数组的下标 位置 
    cnt=0;
    l=1;
    b[mid]=a[j++];cnt++;//先填中间 
    while(cnt<last){
        b[mid-l]=a[j++];cnt++;if(cnt==last) break;
        b[mid+l]=a[j++];cnt++;if(cnt==last) break;
        l++;//位移 
    }
    cnt=0;
    if(mid-last>=0) i=mid-last;//防止越界 不确定是应该打印的范围 模糊范围是[mid-last,min+last] 
    else i=0;
    if(mid+last<=10001) max=mid+last;//实际上[0,10000]之间 为了防止越界 限制一下 
    else max=10001;
    for(;i<=max;i++){
        if(b[i].height!=0&&b[i].flag!=0){
            cnt++;
            printf("%s",b[i].name);
            b[i].flag=0;//记录已经打印了 之后不会再打印 
            if(cnt!=last){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
    }

    int count=(n-last)/ave;//循环次数 
    while(count--){
        last=ave;
        mid=last/2+1;
        cnt=0;
        l=1;
        b[mid]=a[j++];cnt++;
        while(cnt<last){
            b[mid-l]=a[j++];cnt++;if(cnt==last) break;
            b[mid+l]=a[j++];cnt++;if(cnt==last) break;
            l++;
        }
        cnt=0;
        if(mid-last>=0) i=mid-last;
        else i=0;
        if(mid+last<=10001) max=mid+last;
        else max=10001;
        for(;i<=max;i++){
            if(b[i].height!=0&&b[i].flag!=0){
                cnt++;
                printf("%s",b[i].name);
                b[i].flag=0;
                if(cnt!=last){
                    printf(" ");
                }
                else{
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
