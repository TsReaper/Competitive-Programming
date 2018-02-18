#include <stdio.h>

int n,P[210][110],ans[110][110];
int cnt[10010];

int main()
{
    int i,j,k,t;

    scanf("%d",&n);
    for(i=1;i<=n*2;i++)
    {
        for(j=1;j<=n;j++) scanf("%d",&P[i][j]);
        cnt[P[i][1]]++;
        if(cnt[P[i][1]] == 2) t = i;
    }

    for(i=1;i<=n;i++) ans[1][i] = P[t][i];
    for(i=1;i<=n*2;i++) if(i != t)
    {
        for(j=1;j<=n;j++) if(P[i][1] == ans[1][j]) break;
        if(j <= n) for(k=1;k<=n;k++) ans[k][j] = P[i][k];
    }

    for(i=1;i<=n;i++) for(j=1;j<=n;j++) printf("%d%c",ans[i][j],"\n "[i<n||j<n]);
    return 0;
}
