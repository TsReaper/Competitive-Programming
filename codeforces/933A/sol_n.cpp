#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int main()
{
    int x;
    int a = 0,ab = 0,aba = 0,abab = 0;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        if(x == 1) a++, aba++;
        else ab++, abab++;
        ab = max(ab,a);
        aba = max(aba,ab);
        abab = max(abab,aba);
    }
    printf("%d",abab);

    return 0;
}
