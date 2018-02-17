#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,K,V,A[5010];

int f[5010][5010],g[5010][5010];
bool used[5010];

int main()
{
    int i,j,k,x = 0,y,tot = 0;
    memset(f,-60,sizeof(f));

    scanf("%d%d%d",&n,&K,&V);
    for(i=1;i<=n;i++) scanf("%d",&A[i]), tot += A[i];
    if(tot < V) { printf("NO"); return 0; }
    if(V%K == 0)
    {
        printf("YES\n");
        for(i=2;i<=n;i++) if(A[i]) printf("%d %d 1\n",(A[i]+K-1)/K,i);
        if(V) printf("%d 1 2",V/K);
        return 0;
    }

    f[0][0] = 0;
    for(i=1;i<=n;i++) for(j=0;j<K;j++)
    {
        f[i][j] = f[i-1][j]; g[i][j] = j;
        k = (j-A[i]%K+K)%K;
        if(f[i-1][k] + A[i] > f[i][j])
        {
            f[i][j] = f[i-1][k] + A[i];
            g[i][j] = k;
        }
    }

    if(f[n][V%K] < 0) { printf("NO"); return 0; }
    printf("YES\n");
    for(i=n,j=V%K;i;i--,j=k)
    {
        k = g[i][j];
        if(f[i][j] == f[i-1][k]) continue;

        if(!x) x = i, y = (x == n ? 1 : x+1);
        used[i] = true;
        if(i != x) printf("%d %d %d\n",(A[i]+K-1)/K,i,x);
    }
    if(f[n][V%K] > V) printf("%d %d %d\n",(f[n][V%K]-V)/K,x,y);
    else if(f[n][V%K] < V)
    {
        for(i=1;i<=n;i++) if(!used[i] && i != y) printf("%d %d %d\n",(A[i]+K-1)/K,i,y);
        printf("%d %d %d\n",(V-f[n][V%K])/K,y,x);
    }
    return 0;
}
