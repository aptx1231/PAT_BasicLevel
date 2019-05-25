#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num;
    long long T;
    scanf("%lld %d",&T,&num);
    int i;
    int n1,n2,b,t;
    for(i=0;i<num;i++){
        scanf("%d %d %d %d",&n1,&b,&t,&n2);
        if(T==0){
            printf("Game Over.\n");
            break;
        }
        else if(t>T){
            printf("Not enough tokens.  Total = %lld.\n",T);
        }
        else if(n1<n2){
            if(b==0){
                T-=t;
                printf("Lose %d.  Total = %lld.\n",t,T);
            }
            else{
                T+=t;
                printf("Win %d!  Total = %lld.\n",t,T);
            }
        }
        else if(n1>n2){
            if(b==1){
                T-=t;
                printf("Lose %d.  Total = %lld.\n",t,T);
            }
            else{
                T+=t;
                printf("Win %d!  Total = %lld.\n",t,T);
            }
        }
    }
    return 0;
}

