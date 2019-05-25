#include<stdio.h>
#define LIM 1000000007

int main()
{
	//法一 
    unsigned int P = 0, PA = 0, PAT = 0;
    char c;
    while((c = getchar()) != '\n')//O(N)
    {
        if(c == 'P')   P++;//记录多少个P 
        if(c == 'A')   PA = (PA + P) % LIM;//遇到A 前边几个P就新构成多少个PA 
        if(c == 'T')   PAT = (PAT + PA) % LIM;//遇到T 前边几个PA就新构成多少了PAT 
    }
    printf("%d", PAT);
    return 0;
}

	/*int i,j,k,cnt=0;---暴力 慢 O(N^3) 
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
