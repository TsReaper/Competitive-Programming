#include <stdio.h>
#include <math.h>

int R,xa,ya,xb,yb;

int main()
{
    long long d2;
    double d;

    scanf("%d%d%d%d%d",&R,&xa,&ya,&xb,&yb);
    d2 = 1LL*(xa-xb)*(xa-xb) + 1LL*(ya-yb)*(ya-yb);
    d = sqrt(d2);

    if(d2 > 1LL*R*R)
        printf("%d %d %d",xa,ya,R);
    else if(d2 > 0)
        printf("%.12f %.12f %.12f",xa-(xb-xa)/d*(R-d)/2.0,ya-(yb-ya)/d*(R-d)/2.0,(R+d)/2.0);
    else
        printf("%d %.12f %.12f",xa,ya+R/2.0,R/2.0);

    return 0;
}
