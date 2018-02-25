#include <stdio.h>

int n,ans;

int main()
{
    int i;

    scanf("%d",&n);
    for(i=1;i*i<=n;i++) if(n%i == 0) ans += 1 + (i != n/i);
    printf("%d",ans-1);

    return 0;
}
