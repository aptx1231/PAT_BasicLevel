#include<stdio.h>
#include<string.h>

int main()
{
	char a1[80],a2[80];
	char b1[80],b2[80];
	int la1,la2,lb1,lb2;
	gets(a1); la1=strlen(a1);
	gets(a2); la2=strlen(a2);
	gets(b1); lb1=strlen(b1);
	gets(b2); lb2=strlen(b2);
	
	int i,k;
	char fir,sec;
	for(i=0;i<la1&&i<la2;i++){
		if(a1[i]>='A'&&a1[i]<='G'){
			if(a2[i]==a1[i]){
				fir=a1[i];
				break;
			}
		}
	}
	switch(fir){
		case 'A':printf("MON ");break;
		case 'B':printf("TUE ");break;
		case 'C':printf("WED ");break;
		case 'D':printf("THU ");break;
		case 'E':printf("FRI ");break;
		case 'F':printf("SAT ");break;
		case 'G':printf("SUN ");break;
	}
	
	for(k=i+1;k<la1&&k<la2;k++){
		if((a1[k]>='A'&&a1[k]<='N')||(a1[k]>='0'&&a1[k]<='9')){
			if(a2[k]==a1[k]){
				sec=a1[k];
				break;
			}
		}
	}
	switch(sec){
		case '0':printf("00:");break;
		case '1':printf("01:");break;
		case '2':printf("02:");break;
		case '3':printf("03:");break;
		case '4':printf("04:");break;
		case '5':printf("05:");break;
		case '6':printf("06:");break;
		case '7':printf("07:");break;
		case '8':printf("08:");break;
		case '9':printf("09:");break;
		case 'A':printf("10:");break;
		case 'B':printf("11:");break;
		case 'C':printf("12:");break;
		case 'D':printf("13:");break;
		case 'E':printf("14:");break;
		case 'F':printf("15:");break;
		case 'G':printf("16:");break;
		case 'H':printf("17:");break;
		case 'I':printf("18:");break;
		case 'J':printf("19:");break;
		case 'K':printf("20:");break;
		case 'L':printf("21:");break;
		case 'M':printf("22:");break;
		case 'N':printf("23:");break;
	}
	
	for(i=0;i<lb1&&i<lb2;i++){
		if((b1[i]>='a'&&b1[i]<='z')||(b1[i]>='A'&&b1[i]<='Z')){
			if(b2[i]==b1[i]){
				if(i<10){
					printf("0%d",i);
				}
				else{
					printf("%d",i);
				}
			}
		}
	}

	return 0;
}
