#include <stdio.h>
#define MOD 1000000007

int n;

long long power(long long a,int b)
{
    long long y = 1;
    for(;b;b>>=1)
    {
        if(b&1) y = y*a%MOD;
        a = a*a%MOD;
    }
    return y;
}

int main()
{
    scanf("%d",&n);
    printf("%lld",power(n,(n-1)*(n-1)));
    return 0;
}
