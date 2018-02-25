#include <stdio.h>
#define MOD 1000000007

int n,m,A[100010],B[100010];
long long ans;

long long power(long long a,long long b)
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
    int i;
    long long t = 1;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    for(i=1;i<=n;i++) scanf("%d",&B[i]);

    for(i=1;i<=n;i++)
    {
        if(A[i] && B[i])
        {
            if(A[i] > B[i]) { ans = (ans + power(t,MOD-2)) % MOD; break; }
            else if(A[i] < B[i]) break;
        }
        else if(A[i] && !B[i])
        {
            t = t*m%MOD;
            ans = (ans + (A[i]-1) * power(t,MOD-2)) % MOD;
        }
        else if(!A[i] && B[i])
        {
            t = t*m%MOD;
            ans = (ans + (m-B[i]) * power(t,MOD-2)) % MOD;
        }
        else
        {
            t = t*m%MOD;
            ans = (ans + (m-1) * power(t*2,MOD-2)) % MOD;
        }
    }

    printf("%I64d",ans);
    return 0;
}
