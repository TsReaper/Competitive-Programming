#include <cstdio>

long long n,m;
int q;

int main()
{
    scanf("%I64d%d",&n,&q); n = (n<<1)-1;
    while(q--)
    {
        scanf("%I64d",&m);
        while(m&1^1) m += (n-m+1)>>1;
        printf("%I64d\n",(m+1)>>1);
    }

    return 0;
}
