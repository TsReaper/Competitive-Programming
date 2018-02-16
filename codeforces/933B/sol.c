#include <stdio.h>

long long P;
int K,ans[110];

int main()
{
    int i,j;

    scanf("%I64d%d",&P,&K);
    for(i=0;P;i++)
    {
        ans[i] = P % -K;
        P /= -K;
        if(ans[i] < 0) ans[i] += K, P++;
    }

    printf("%d\n",i);
    for(j=0;j<i;j++) printf("%d%c",ans[j],"\n "[j<i-1]);

    return 0;
}
