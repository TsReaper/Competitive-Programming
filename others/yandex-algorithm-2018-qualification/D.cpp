#include <cstdio>
#include <algorithm>
#define LIM 100
#define VAL first
#define POS second
using namespace std;
typedef pair<long long,int> pli;

int n,q;
long long A[300010];

int main()
{
    int i,l,r;
    pli t[LIM+10];

    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++) scanf("%lld",&A[i]);
    while(q--)
    {
        scanf("%d%d",&l,&r);
        if(r-l > LIM) r = l + LIM;

        for(i=l;i<=r;i++) t[i-l] = pli(A[i],i);
        sort(t,t+r-l+1);
        for(i=0;i+2<r-l+1;i++) if(t[i].VAL + t[i+1].VAL > t[i+2].VAL) break;
        if(i+2 < r-l+1) printf("%d %d %d\n",t[i].POS,t[i+1].POS,t[i+2].POS);
        else printf("-1\n");
    }

    return 0;
}
