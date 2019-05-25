#include<stdio.h>
#include<stdlib.h>
int ap[2<<24] = {0}; 

int main()
{
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	int a[n][m];
	int c[5];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			ap[a[i][j]]++;
		}
	}
	int num=0;
	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int flag=1;
            if(ap[a[i][j]]!=1) flag=0;//不是独一无二的，有重复的点 
            if(i+1<n) if(abs(a[i][j]-a[i+1][j])<=k) flag=0;
            if(i+1<n&&j+1<m) if(abs(a[i][j]-a[i+1][j+1])<=k) flag=0;
            if(i+1<n&&j>=1) if(abs(a[i][j]-a[i+1][j-1])<=k) flag=0;
            if(i>=1)  if(abs(a[i][j]-a[i-1][j])<=k) flag=0;
            if(i>=1&&j+1<m) if(abs(a[i][j]-a[i-1][j+1])<=k) flag=0;
            if(i>=1&&j>=1) if(abs(a[i][j]-a[i-1][j-1])<=k) flag=0;
            if(j+1<m) if(abs(a[i][j]-a[i][j+1])<=k) flag=0;
            if(j>=1)  if(abs(a[i][j]-a[i][j-1])<=k) flag=0;
            if(flag==1){
                if(num==0)
                    c[0]=j;c[1]=i;c[2]=a[i][j];
                num++;
            }
        }
	}
	if(num==0){
        printf("Not Exist");
	}
	else if(num==1){
        printf("(%d, %d): %d",c[0]+1,c[1]+1,c[2]);
	}
	else{
        printf("Not Unique");
	}
	return 0;
}

