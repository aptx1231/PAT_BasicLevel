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
        a[i].flag=1;//����û�б���ӡ 
    }
    qsort(a,n,sizeof(struct per),compare);
    //for(i=0;i<n;i++){
    //   printf("%s %d\n",a[i].name,a[i].height);
    //}

    int ave=n/line;
    int last=ave+n%line;//���һ�� �������� 
    int mid=last/2+1;
    int max; 
    j=0;//ȷ��a������±� λ�� 
    cnt=0;
    l=1;
    b[mid]=a[j++];cnt++;//�����м� 
    while(cnt<last){
        b[mid-l]=a[j++];cnt++;if(cnt==last) break;
        b[mid+l]=a[j++];cnt++;if(cnt==last) break;
        l++;//λ�� 
    }
    cnt=0;
    if(mid-last>=0) i=mid-last;//��ֹԽ�� ��ȷ����Ӧ�ô�ӡ�ķ�Χ ģ����Χ��[mid-last,min+last] 
    else i=0;
    if(mid+last<=10001) max=mid+last;//ʵ����[0,10000]֮�� Ϊ�˷�ֹԽ�� ����һ�� 
    else max=10001;
    for(;i<=max;i++){
        if(b[i].height!=0&&b[i].flag!=0){
            cnt++;
            printf("%s",b[i].name);
            b[i].flag=0;//��¼�Ѿ���ӡ�� ֮�󲻻��ٴ�ӡ 
            if(cnt!=last){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
    }

    int count=(n-last)/ave;//ѭ������ 
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
