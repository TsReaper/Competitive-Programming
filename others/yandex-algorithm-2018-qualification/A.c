#include <stdio.h>

int n;
short flag[40];

int main()
{
    int i,x,y;

    for(i=1;i<=10;i++) scanf("%d",&x), flag[x] = 1;
    scanf("%d",&n);
    while(n--)
    {
        y = 0;
        for(i=1;i<=6;i++) scanf("%d",&x), y += flag[x];
        if(y >= 3) printf("Lucky\n");
        else printf("Unlucky\n");
    }

    return 0;
}
