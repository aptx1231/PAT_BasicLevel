#include <stdio.h>
#include <string.h>

int main()
{
    int N, count = 0;
    /* store name and birthday in one string: "YYYY/MM/DD\0NAMES\0" */
    char cur[17], eldest[17] = {'9'}, youngest[17] = {'0'};
    
    scanf("%d", &N);
    int i; 
    for(i = 0; i < N; i++)
    {
        scanf("%s%s", cur+11, cur);
        //cur[10]='a';
        if(strcmp(cur, "1814/09/06") >= 0 && strcmp(cur, "2014/09/06") <= 0) 
        {
            if(strcmp(cur, eldest) <= 0) //cur<eldest �����ַ���ԽС˵�����Խ�� 
                memcpy(eldest, cur, 17);
                //strcpy(eldest,cur);
            if(strcmp(cur, youngest) >= 0)
                memcpy(youngest, cur, 17);
                //strcpy(youngest,cur);
            count++;
        }
    }
    
    if(count)
        printf("%d %s %s", count, eldest+11 , youngest+11 );
    else 
        printf("0");
    
    return 0;
}
