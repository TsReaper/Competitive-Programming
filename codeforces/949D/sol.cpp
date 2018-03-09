#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n,D,B,A[100010],C[100010];

bool check(int x)
{
    int i,j,k,t,y;
    for(i=1;i<=n;i++) C[i] = A[i];

    for(i=1,j=x+1,y=0;i<=n;i++) while(C[i])
    {
        if((abs(j-i)+D-1)/D > min(j,n-j+1)) goto PHASE1;
        t = min(C[i],B-y); C[i] -= t; y = (y+t)%B;
        if(!y) j++;
    }

    PHASE1:
    for(i=n,k=n-x,y=0;i;i--) while(C[i])
    {
        if((abs(i-k)+D-1)/D > min(k,n-k+1)) goto PHASE2;
        t = min(C[i],B-y); C[i] -= t; y = (y+t)%B;
        if(!y) k--;
    }

    PHASE2:
    return j > k;
}

int work()
{
    int head = 0,tail = (n+1)/2-1,mid;
    while(head < tail)
    {
        mid = (head+tail) >> 1;
        if(check(mid)) tail = mid;
        else head = mid + 1;
    }

    return head;
}

int main()
{
    int i;

    scanf("%d%d%d",&n,&D,&B);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);

    printf("%d",work());
    return 0;
}
