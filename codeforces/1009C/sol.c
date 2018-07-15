#include <stdio.h>
#include <stdlib.h>

int n,m;
long long ans;

int main()
{
    int i,x,d;
    long long k1,k2;

    scanf("%d%d",&n,&m);
    for(i=1,k1=k2=0;i<=n;i++)
    {
        k1 += i-1;
        k2 += abs(i-(n+1)/2);
    }

    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&d);
        ans += x * n + (d > 0 ? k1 : k2) * d;
    }

    printf("%.9f",1.0*ans/n);
    return 0;
}
