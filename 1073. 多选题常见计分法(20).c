#include<stdio.h>
#include<string.h>

struct ques{
    int score;
    int tru;
    char ans[6];
    int mark[6];
}a[120];

int end[120][6]={0};//����ѡ�� 
 
double sum[1200]={0};//����  N<=1000  �������� 

int str(char a[],char c)
{
	int i;
	for(i=0;a[i]!='\0';i++){
		if(a[i]==c) return i;
	}
	return -1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j,k,l,p,q;
    int score,num,tru,cnt,max=-1,iswrong=0;
    char ch;

    for(i=0;i<m;i++){
        scanf("%d %d %d",&score,&num,&tru);
        getchar();
        a[i].score=score;
        a[i].tru=tru;
        for(j=0;j<tru;j++){
            scanf("%c",&ch);
            a[i].ans[j]=ch;
            a[i].mark[j]=1;
            getchar();
        }
        a[i].ans[j]='\0';
    }
    char in[6];
    int mm[6];//��� 

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        	//�����������ѡ��ѡ�� 
            getchar();
            scanf("%d",&cnt);
            getchar();
            for(k=0;k<cnt;k++){
                scanf("%c",&ch);
                in[k]=ch;
                mm[k]=1;
                getchar();
            }
            in[k]='\0';
            getchar();
            for(l=0;l<6;l++){
            	a[j].mark[l]=1;
			}
			//�ж��Ƿ���ȷ 
            if(strcmp(in,a[j].ans)==0){
            	sum[i]+=a[j].score;
			}
			else{
				iswrong=1;
				char cc;
				for(cc='a';cc<='e';cc++){//������ȷѡ�����ѡѡ��Ĺ��в��� 
					if((p=str(a[j].ans,cc))!=-1&&(q=str(in,cc))!=-1){
						a[j].mark[p]=0;
						mm[q]=0;
					}
				}
				int is=0;
				for(p=0;p<a[j].tru;p++){//����ѡ���ҵ��Ǹ��ǹ���ѡ�� 
					if(a[j].mark[p]==1){
						end[j][a[j].ans[p]-'a']++;//���ַ�a[j].ans[p]�浽����ѡ���� 
					}
				}
				for(q=0;q<k;q++){
					if(mm[q]==1){
						end[j][in[q]-'a']++;
						is=1;//�ж�ѡ�� 
					}
				}
				if(is==1){
					sum[i]+=0.0;
				}
				else{
					sum[i]+=a[j].score*0.5;
				}
			}
        }
    }
    for(i=0;i<n;i++){
        printf("%0.1f\n",sum[i]);
    }
    if(iswrong==0){
    	printf("Too simple\n");
    	return 0;
	} 
	
    max=0;
    for(i=0;i<m;i++){//�������д���ѡ�������ֵ 
    	for(j='a';j<='e';j++){
    		if(end[i][j-'a']>max) 
				max=end[i][j-'a'];
		}
	}

	for(i=0;i<m;i++){
    	for(j='a';j<='e';j++){
    		if(max==end[i][j-'a']){//ɨ��������ѡ�� 
    			printf("%d %d-%c\n",max,i+1,j);	
			}
		}
	}
	
    return 0;
}
