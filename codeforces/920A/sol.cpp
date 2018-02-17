#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int tcase,n,K,ans,tap[210];

int main()
{
    int i,j,d;

    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d%d",&n,&K);
        for(i=1;i<=K;i++) scanf("%d",&tap[i]);
        for(i=1,ans=0;i<=n;i++)
        {
            d = n;
            for(j=1;j<=K;j++) d = min(d,abs(i-tap[j]));
            ans = max(ans,d);
        }
        printf("%d\n",ans+1);
    }

    return 0;
}
