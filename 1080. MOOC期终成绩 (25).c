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
    else{ // 如果all相等
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
        if(score>=200&&score<=900){//直接忽略小于200分的 
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
    
    qsort(a,l,sizeof(struct stu),compare1);//把同名的放到一起了 

    for(i=0;i<l;i++){//快 把相同的整合到一起 O(N)
        j=i+1;
        while(strcmp(a[i].name,a[j].name)==0){
        	if(a[j].online!=-1) a[i].online=a[j].online;
        	if(a[j].mid!=-1) a[i].mid=a[j].mid;
        	if(a[j].last!=-1) a[i].last=a[j].last;
        	j++;
		}//出循环j是不相同的位置了  
		i=j-1;//回一位 因为要i++ 
	}
	
    for(i=0;i<l;i++){
    	if(a[i].online>=200){//虽然读入限制了 但是出现了反复读入导致的-1 同名的后边的都是-1 
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
    
    qsort(a,l,sizeof(struct stu),compare);//按照all的值排序 

    for(i=0;i<l;i++){
        if(a[i].all>=60){//限制all的值 后边的all值都是-1 
            printf("%s %d %d %d %d\n",a[i].name,a[i].online,a[i].mid,a[i].last,a[i].all);
        }
        else{
        	break;//只要遇到-1就跳出来就行了 
		} 
    }
    return 0;
}
