#include <stdio.h>

int n,ans;
char s[100010];

int X[100010],Y[100010];

int main()
{
    int i;

    scanf("%d%s",&n,s+1);
    for(i=1;i<=n;i++)
        if(s[i] == 'U') X[i] = X[i-1], Y[i] = Y[i-1]+1;
        else X[i] = X[i-1]+1, Y[i] = Y[i-1];

    for(i=3;i<=n;i++)
    {
        if(X[i] == Y[i]) continue;
        if(X[i-2] == Y[i-2]) continue;
        ans += (X[i] < Y[i]) ^ (X[i-2] < Y[i-2]);
    }
    printf("%d",ans);

    return 0;
}
