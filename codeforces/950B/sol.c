#include <stdio.h>

int n,m,ans,A[100010],B[100010];

int main()
{
    int i,j,x,y;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    for(i=1;i<=m;i++) scanf("%d",&B[i]);

    for(i=j=x=y=0;i<n||j<m;)
    {
        if(x <= y) x += A[++i];
        else y += B[++j];
        if(x == y) ans++;
    }

    printf("%d",ans);
    return 0;
}
