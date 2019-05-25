#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stu{
    char name[25];
    int mid;
    int last;
    int online;
    int all;
}a[30009];

int compare(const void *a, const void *b)
{
    int k;
    if(((const struct stu*)a)->all<((const struct stu*)b)->all)
        k = 1;
    else if(((const struct stu*)a)->all>((const struct stu*)b)->all)
        k = -1;
    else{ // ���all���
        if (strcmp(((const struct stu*)a)->name,((const struct stu*)b)->name)<0)
            k = -1;
        else
            k = 1;
    }
    return k;
}

int compare1(const void *a, const void *b)
{
    int k;
    if (strcmp(((const struct stu*)a)->name,((const struct stu*)b)->name)<0)
        k = -1;
    else
        k = 1;
    return k;
}

int main()
{
    int m,n,p;
    scanf("%d %d %d",&m,&n,&p);
    getchar();
    int i,l=0,j;
    int score,flag;
    char name[25];
    
    for(i=0;i<m;i++){
        scanf("%s %d",name,&score);
        getchar();
        if(score>=200&&score<=900){//ֱ�Ӻ���С��200�ֵ� 
            strcpy(a[l].name,name);
            a[l].mid=-1;
            a[l].last=-1;
            a[l].online=score;
            l++;
        }
    }
    for(i=0;i<n;i++){
        scanf("%s %d",name,&score);
        getchar();
        if(score>=0&&score<=100){
            strcpy(a[l].name,name);
            a[l].mid=score;
            a[l].last=-1;
            a[l].online=-1;
            l++;
        }
    }
    for(i=0;i<p;i++){
        scanf("%s %d",name,&score);
        getchar();
        if(score>=0&&score<=100){
            strcpy(a[l].name,name);
            a[l].mid=-1;
            a[l].last=score;
            a[l].online=-1;
            l++;
        }
    }
    
    qsort(a,l,sizeof(struct stu),compare1);//��ͬ���ķŵ�һ���� 

    for(i=0;i<l;i++){//�� ����ͬ�����ϵ�һ�� O(N)
        j=i+1;
        while(strcmp(a[i].name,a[j].name)==0){
        	if(a[j].online!=-1) a[i].online=a[j].online;
        	if(a[j].mid!=-1) a[i].mid=a[j].mid;
        	if(a[j].last!=-1) a[i].last=a[j].last;
        	j++;
		}//��ѭ��j�ǲ���ͬ��λ����  
		i=j-1;//��һλ ��ΪҪi++ 
	}
	
    for(i=0;i<l;i++){
    	if(a[i].online>=200){//��Ȼ���������� ���ǳ����˷������뵼�µ�-1 ͬ���ĺ�ߵĶ���-1 
	    	if(a[i].mid<=a[i].last){
	            a[i].all=a[i].last;
	        }
	        else{
	            double f=a[i].mid*0.4+a[i].last*0.6;
	            //int k=(int)f;
	            //if(f-k>=0.5) a[i].all=k+1;
	            //else a[i].all=k;
	            a[i].all=(int)(f+0.5);
	        }
		}
        else{
        	a[i].all=-1;
		}
    }
    
    qsort(a,l,sizeof(struct stu),compare);//����all��ֵ���� 

    for(i=0;i<l;i++){
        if(a[i].all>=60){//����all��ֵ ��ߵ�allֵ����-1 
            printf("%s %d %d %d %d\n",a[i].name,a[i].online,a[i].mid,a[i].last,a[i].all);
        }
        else{
        	break;//ֻҪ����-1�������������� 
		} 
    }
    return 0;
}
