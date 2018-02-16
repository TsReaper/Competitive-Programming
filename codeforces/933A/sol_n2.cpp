#include <cstdio>
#include <algorithm>
using namespace std;

int n,ans,A[2010];

int suml[2010][2],sumr[2010][2];
int fl[2010][2010],fr[2010][2010];

int main()
{
    int i,j,k,t;

    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&A[i]), A[i]--;
    for(i=1;i<=n;i++) for(j=0;j<2;j++) suml[i][j] = suml[i-1][j] + (A[i] == j);
    for(i=n;i;i--) for(j=0;j<2;j++) sumr[i][j] = sumr[i+1][j] + (A[i] == j);

    for(i=1;i<=n;i++)
    {
        fl[i][i] = suml[i][0] - suml[i][1];
        fr[i][i] = sumr[i][0] - sumr[i][1];
    }
    for(k=2;k<=n;k++) for(i=1;(j=i+k-1)<=n;i++)
    {
        fl[i][j] = max(fl[i+1][j],fl[i][j-1]);
        fr[i][j] = max(fr[i+1][j],fr[i][j-1]);
    }

    for(i=1;i<=n;i++) for(j=i;j<=n;j++)
    {
        t = max(fl[1][i-1],fl[j+1][n]);
        t = max(t,fr[i][j] - fr[j+1][j+1] + fl[i-1][i-1]);
        ans = max(ans,t);
    }
    for(i=1;i<=n;i++) ans += A[i];
    printf("%d",ans);

    return 0;
}
