#include <stdio.h>

char s[100010];

int one,siz;
char zt[100010];

int main()
{
    int i;

    scanf("%s",s+1);
    for(i=1;s[i];i++)
    {
        if(s[i] == '1') one++;
        else zt[++siz] = s[i];
    }

    for(i=1;i<=siz;i++)
    {
        if(zt[i] == '2') break;
        else printf("0");
    }
    while(one--) printf("1");
    printf("%s",zt+i);
    return 0;
}
