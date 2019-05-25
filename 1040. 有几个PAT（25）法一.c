#include<stdio.h>
#define LIM 1000000007

int main()
{
	//��һ 
    unsigned int P = 0, PA = 0, PAT = 0;
    char c;
    while((c = getchar()) != '\n')//O(N)
    {
        if(c == 'P')   P++;//��¼���ٸ�P 
        if(c == 'A')   PA = (PA + P) % LIM;//����A ǰ�߼���P���¹��ɶ��ٸ�PA 
        if(c == 'T')   PAT = (PAT + PA) % LIM;//����T ǰ�߼���PA���¹��ɶ�����PAT 
    }
    printf("%d", PAT);
    return 0;
}

	/*int i,j,k,cnt=0;---���� �� O(N^3) 
    for(i=0;i<strlen(a);i++){
        if(a[i]=='P'){
            for(j=i+1;j<strlen(a);j++){
                if(a[j]=='A'){
                    for(k=j+1;k<strlen(a);k++){
                        if(a[k]=='T'){
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    printf("%d",cnt%1000000007);*/
