#include<stdio.h>
int max3(int a,int b,int c)
{
	int max;
	if(a>b){
		if(b>c)	max=a;
		else if(a>c) max=a;
		else max=c;	
	}else{
		if(a>c) max=b;
		else if(b>c) max=b;
		else max=c;
	}
	return max;
	//return a>b?(a>c?a:c):(b>c?b:c);
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	char a,b;
	int cnt0=0,cnt1=0,cnt2=0;
	int cnt1C=0,cnt1B=0,cnt1J=0;
	int cnt2C=0,cnt2B=0,cnt2J=0;
	int max1,max2;
	while(n--){
		scanf("%c %c",&a,&b);
		getchar();
		if(a=='C'){
			if(b=='C'){
				cnt0++;
			}else if(b=='J'){
				cnt1++;
				cnt1C++;
			}else{
				cnt2++;
				cnt2B++;
			}
		}else if(a=='J'){
			if(b=='J'){
				cnt0++;
			}else if(b=='B'){
				cnt1++;
				cnt1J++;
			}else{
				cnt2++;
				cnt2C++;
			}
		}else{
			if(b=='B'){
				cnt0++;
			}else if(b=='C'){
				cnt1++;
				cnt1B++;
			}else{
				cnt2++;
				cnt2J++;
			}
		}
	}
	printf("%d %d %d\n",cnt1,cnt0,cnt2);
	printf("%d %d %d\n",cnt2,cnt0,cnt1);
	
	max1=max3(cnt1C,cnt1B,cnt1J);
	max2=max3(cnt2C,cnt2B,cnt2J);
	if(cnt1B==max1) printf("B ");
	else if(cnt1C==max1) printf("C ");
	else printf("J ");
	if(cnt2B==max2) printf("B");
	else if(cnt2C==max2) printf("C");
	else printf("J");
	
	return 0;
}
