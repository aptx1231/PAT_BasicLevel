#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stu_node{
	char num[20];
	char name[20];
	int score;
	struct stu_node* next;
};
typedef struct stu_node* Position;
typedef struct stu_node* List;

int main()
{
	List L=(List)malloc(sizeof(struct stu_node));
	L->score=0;
	L->next=NULL;
	
	List p=L,tmp;
	char num[20];
	int score;
	char name[20];
	int n;
	scanf("%d",&n);
	getchar();
	int i,min=101,max=-1;
	for(i=0;i<n;i++){
		scanf("%s %s %d",name,num,&score);
		getchar();
		if(score>max) 
			max=score;
		if(score<min)
			min=score;
		tmp=(List)malloc(sizeof(struct stu_node));//对于一组数据，应该重新要一块空间！！！！ 
		strcpy(tmp->name,name);
		tmp->score=score;
		strcpy(tmp->num,num);
		tmp->next=NULL;
		p->next=tmp;
		p=tmp;
	}
	
	L=L->next;
	tmp=L;
	while(tmp){
		if(tmp->score==max){
			printf("%s %s\n",tmp->name,tmp->num);
		}
		tmp=tmp->next;
	}
	tmp=L;
	while(tmp){
		if(tmp->score==min){
			printf("%s %s\n",tmp->name,tmp->num);
		}
		tmp=tmp->next;
	}
	return 0;
}
