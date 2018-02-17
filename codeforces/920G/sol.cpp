#include <cstdio>
#include <vector>
#define MAXA 1000000
#define LIM 1000
using namespace std;

int tcase,X,P,K;

vector<int> prime,fac[MAXA+10];
bool flag[MAXA+10];

void prepare()
{
    int i,j,x;

    for(i=2;i<=LIM;i++) for(j=i<<1;j<=LIM;j+=i) flag[j] = true;
    for(i=2;i<=LIM;i++) if(!flag[i]) prime.push_back(i);

    for(i=2;i<=MAXA;i++)
    {
        x = i;
        for(int y : prime)
        {
            if(x < y) break;
            if(x%y == 0)
            {
                fac[i].push_back(y);
                while(x%y == 0) x /= y;
            }
        }
        if(x > 1) fac[i].push_back(x);
    }
}

long long dfs(long long lim,int p,int now,long long prod,int k)
{
    int i;
    long long ret = lim/prod*k;
    for(i=now+1;i<fac[p].size();i++) ret += dfs(lim,p,i,prod*fac[p][i],k*-1);
    return ret;
}

long long work()
{
    long long cnt = dfs(X,P,-1,1,1);
    long long head = X+1,tail = 2e9,mid;
    while(head < tail)
    {
        mid = (head+tail)>>1;
        if(dfs(mid,P,-1,1,1) - cnt >= K) tail = mid;
        else head = mid + 1;
    }
    return head;
}

int main()
{
    prepare();

    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d%d%d",&X,&P,&K);
        if(P == 1) printf("%d\n",X+K);
        else printf("%I64d\n",work());
    }

    return 0;
}
