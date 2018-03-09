#include <stdio.h>

int L,R,A;

int main()
{
    scanf("%d%d%d",&L,&R,&A);
    if(L+A <= R) printf("%d",(L+A)*2);
    else if(R+A <= L) printf("%d",(R+A)*2);
    else printf("%d",(L+R+A)/2*2);

    return 0;
}
