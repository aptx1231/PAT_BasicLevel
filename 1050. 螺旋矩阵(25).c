#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int a[10000][10000];
int b[10000];

int compare(const void *a, const void *b)
{ /* 比较两整数,降序排列 */
    return (*(int*)b - *(int*)a);
}

int move(int m,int n)
{
	/*a[0][0]=b[0];
    int tot,x,y;
	tot=x=y=0;
    while(tot<n*m-1)
    {
        while(y + 1 < n && ! a[x][y + 1])
            a[x][++y] = b[++tot];         
		while(x + 1 < m && !a[x + 1][y])
            a[++x][y] = b[++tot];
        while(y - 1 >= 0 && !a[x][y - 1])
            a[x][--y] = b[++tot];
        while(x - 1 >= 0 && !a[x - 1][y])
            a[--x][y] = b[++tot];   
    }*/
	int i,j,p=0;
	/*int l;
	for(l=0;p<m*n-1;l++){
		for(i=l,j=l;j<n-l-1;j++){
			if(a[i][j]==0)
				a[i][j]=b[p++];
		} 	
		for(;i<m-l-1;i++){
			if(a[i][j]==0)
				a[i][j]=b[p++];
		}		
		while(j>l){
			if(a[i][j]==0)
				a[i][j]=b[p++];
			j--;
		}		
		while(i>l){
			if(a[i][j]==0)
				a[i][j]=b[p++];
			i--;
		} 		
	}*/
	for(i=0;p<m*n-1;i++){
		for(j=i;j<n-i-1;j++){
			if(a[i][j]==0)
				a[i][j]=b[p++];
		}
		for(j=i;j<m-i-1;j++){
			if(a[j][n-i-1]==0)
				a[j][n-i-1]=b[p++];
		}
		for(j=n-i-1;j>i;j--){
			if(a[m-i-1][j]==0)
				a[m-i-1][j]=b[p++];
		}
		for(j=m-i-1;j>i;j--){
			if(a[j][i]==0)
				a[j][i]=b[p++];
		}
	}
	
	if(m==n&&m%2!=0){
		a[m/2][n/2]=b[p];
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d",a[i][j]);
			if(j!=n-1){
				printf(" ");
			} 
		}
		printf("\n");
	}
}

int main()
{
	int num;
	scanf("%d",&num);
	int i,j;
	for(i=0;i<num;i++){
		//scanf("%d",&b[i]);
		b[i]=i+1;
	}
	
	qsort(b,num,sizeof(int), compare);
	
	/*int min=9999;
	int m,n;
	for(i=1;i<=sqrt(num*1.0);i++){
        if(num%i==0){
            if(num/i-i<min){//求m n差 
                min=num/i-i;
                n=i;
        	}
        }        
    }
    m=num/n;*/

	double f=sqrt(num);
	int k=(int)(f);
	int m,n;
	if(f-k<1e-9){
		m=k;
		n=k;
	}
	else{
		for(i=k;i>=1;i--){
			for(j=k+1;j<=num;j++){
				if(i*j==num){
					break;
				}
			}
			if(i*j==num){
				break;
			}
		}
		m=j;
		n=i;
	}
	
	move(m,n);
	
	return 0;
}
