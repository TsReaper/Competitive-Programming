#include <stdio.h>

int n;

int main()
{
    scanf("%d",&n);
    if(n > 36) printf("-1");
    else
    {
        for(;n>1;n-=2) printf("8");
        if(n) printf("9");
    }
    return 0;
}
