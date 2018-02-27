#include <stdio.h>

int n,m;

int main()
{
    int i,j;

    scanf("%d%d",&m,&n);
    for(i=n;i>m;i--)
    {
        for(j=2;j*j<=i&&j<=m;j++) if(i%j == 0) break;
        if(j*j>i || j>m) goto OK;
    }
    printf("-1"); return 0;
    OK: printf("%d",i); return 0;
}
