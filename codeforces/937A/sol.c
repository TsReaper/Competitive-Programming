#include <stdio.h>

int n,ans;
short vis[1010];

int main()
{
    int i,x;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x && !vis[x]) ans++;
        vis[x] = 1;
    }
    printf("%d",ans);

    return 0;
}
