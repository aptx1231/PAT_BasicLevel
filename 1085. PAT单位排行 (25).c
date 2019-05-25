#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sch{
    int cnt;
    double score;
    char name[8];
    int line;
}a[100009];

int compare(const void* a,const void* b)
{
    int k;
    if(((const struct sch*)a)->score>((const struct sch*)b)->score){
        k=-1;
    }
    else if(((const struct sch*)a)->score<((const struct sch*)b)->score){
        k=1;
    }
    else{
        if(((const struct sch*)a)->cnt>((const struct sch*)b)->cnt){
            k=1;
        }
        else if(((const struct sch*)a)->cnt<((const struct sch*)b)->cnt){
            k=-1;
        }
        else{
            if(strcmp(((const struct sch*)a)->name,((const struct sch*)b)->name)>0){
                k=1;
            }
            else if(strcmp(((const struct sch*)a)->name,((const struct sch*)b)->name)<0){
                k=-1;
            }
        }
    }
    return k;
}

int compare1(const void* a,const void* b)
{
    int k;
    if(strcmp(((const struct sch*)a)->name,((const struct sch*)b)->name)>0){
        k=1;
    }
    else if(strcmp(((const struct sch*)a)->name,((const struct sch*)b)->name)<0){
        k=-1;
    }
    return k;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar(); 
    int i,j;
    int score;
    char ch[8];
    char num[8];
    for(i=0;i<n;i++){
        scanf("%s %d %s",num,&score,ch);
        if(num[0]=='A'){
            a[i].score=score*1.0;
        }
        else if(num[0]=='T'){
            a[i].score=score*1.5;
        }
        else if(num[0]=='B'){
            a[i].score=score/1.5;
        }
        for(j=0;ch[j]!='\0';j++){
            if(ch[j]>='A'&&ch[j]<='Z'){
                ch[j]+=32;
            }
        }
        strcpy(a[i].name,ch);
    }
	
	qsort(a,n,sizeof(struct sch),compare1); 

    int l=0;
    for(i=0;i<n;i++){//�� ����ͬ�����ϵ�һ�� 
    	l++;//ѭ������ ��ͬ��ѧУ�ĸ��� 
        j=i+1;
        a[i].cnt++;//�Լ�������һ�� 
        while(strcmp(a[i].name,a[j].name)==0){
        	a[i].score+=a[j].score;
        	a[i].cnt++;
        	a[j].score=-1;
        	j++;
		}//��ѭ��j�ǲ���ͬ��λ���� 
		a[i].score=(int)a[i].score;//ֱ�ӽ�ѧУ�ĳɼ�ת��int �����������Ҫǿ��ת�� 
		i=j-1;//��һλ ��ΪҪi++ 
	}
    
    qsort(a,n,sizeof(struct sch),compare);

	printf("%d\n",l);
    a[0].line=1;
    printf("%d %s %d %d\n",a[0].line,a[0].name,(int)a[0].score,a[0].cnt);
    for(i=1;i<l;i++){//ǰl������Ч�� ��߷�����-1 
        if(a[i].score==a[i-1].score){
            a[i].line=a[i-1].line;
            printf("%d %s %d %d\n",a[i].line,a[i].name,(int)a[i].score,a[i].cnt);
        }
        else{
            a[i].line=i+1;
            printf("%d %s %d %d\n",a[i].line,a[i].name,(int)a[i].score,a[i].cnt);
        }
    }

    return 0;
}
