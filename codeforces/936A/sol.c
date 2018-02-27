#include <stdio.h>

long long K,D;
double T,ans;

int main()
{
    int i;
    long long k,t;
    double v;

    scanf("%I64d%I64d%lf",&K,&D,&T);

    k = (K+D-1)/D;
    v = K + (D*k-K)/2.0;
    t = (long long)(T/v);
    T -= v*t;
    ans = t*D*k;

    if(T <= K) ans += T;
    else ans += K + (T-K)*2;
    printf("%.12f",ans);

    return 0;
}
