#include <stdio.h>

int n,m,ans,A[1010],B[1010];

int main()
{
    int i,j;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    for(i=1;i<=m;i++) scanf("%d",&B[i]);

    for(i=j=1;i<=n;i++) if(A[i] <= B[j]) ans++, j++;

    printf("%d",ans);
    return 0;
}
