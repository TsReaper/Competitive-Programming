#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
long long ans,A[55],B[55];

int main()
{
    int i,j,k;
    long long t;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%I64d",&A[i]);
    for(i=1;i<=m;i++) scanf("%I64d",&B[i]);

    ans = 2e18;
    for(i=1;i<=n;i++)
    {
        t = -2e18;
        for(j=1;j<=n;j++) if(i != j) for(k=1;k<=m;k++)
            t = max(t,A[j]*B[k]);
        ans = min(ans,t);
    }
    printf("%I64d",ans);

    return 0;
}
