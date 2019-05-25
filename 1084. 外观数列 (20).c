#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[100000];
	char b[100000];//n==40特别多位 开大一些 
	scanf("%s",a);
	int n;
	scanf("%d",&n);
	int i,cnt=1,l=0;
	n--;//本身就是一次 
	while(n--){
		l=0;//b是全新的数组 
		for(i=0;a[i]!='\0';i++){
			cnt=1;//默认一个 就算跟别的都不一样 
			while(a[i]==a[i+1]){//找连续的重复 
				cnt++;
				i++;//找到相等的就向后走i++ 
			}
			b[l++]=a[i];
			b[l++]=cnt+'0';//cnt是整形 转化 
		}
		b[l]='\0';
		strcpy(a,b);//拷贝  
	}
	puts(a);
	return 0;
}
