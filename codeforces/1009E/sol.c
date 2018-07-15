#include <stdio.h>
#define MOD 998244353

int n,A[1000010];
long long ans;

long long S[1000010],P[1000010];

int main()
{
    int i;

    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    for(i=1,P[0]=1;i<=n;i++) P[i] = (P[i-1]<<1) % MOD;
    for(i=n-1;i;i--) S[i] = P[n-i-1] * A[i] % MOD;
    for(i=1;i<n;i++) S[i] = (S[i-1] + S[i]) % MOD;

    for(i=1;i<=n;i++) ans = (ans + S[i-1] + P[n-i]*A[i]) % MOD;
    printf("%I64d\n",ans);
    return 0;
}
