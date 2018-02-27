#include <stdio.h>

int n,m,ans[6010];
char s[2][2010],goal[2010];

int f[2][2010];

void shift(int x)
{
    int i,j;
    if(x < 1 || x > n) return;

    ans[++m] = n-x+1;
    for(i=n,j=1;i>=x;i--,j++) s[m&1][j] = s[m&1^1][i];
    for(i=1;i<x;i++,j++) s[m&1][j] = s[m&1^1][i];
}

int main()
{
    int i,j;
    char c;
    scanf("%d%s%s",&n,s[0]+1,goal+1);

    for(i=2,f[1][1]=1;i<=n;i++)
    {
        for(j=1;j<i;j++) f[i&1][j] = f[i&1^1][i-j];
        f[i&1][i] = i;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) if(f[n&1][j] == i) { c = goal[j]; break; }
        for(j=i;j<=n;j++) if(s[m&1][j] == c)
        {
            shift(j); shift(n-j+i+1); shift(n-i+1);
            break;
        }
        if(j > n) goto NO;
    }

    printf("%d\n",m);
    for(i=1;i<=m;i++) printf("%d%c",ans[i],"\n "[i<m]);
    return 0;
    NO: printf("-1"); return 0;
}
