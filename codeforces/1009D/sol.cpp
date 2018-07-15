#include <cstdio>
#include <algorithm>
#include <vector>
#define MAGIC 1000
#define st first
#define nd second
using namespace std;
typedef pair<int,int> pii;

int n,m;
bool flag[100010];

int main()
{
    int i,j,lim;
    for(i=2;i<=400;i++) if(!flag[i]) for(j=i<<1;j<=100000;j+=i) flag[j] = true;

    scanf("%d%d",&n,&m);
    if(m < n-1) { printf("Impossible\n"); return 0; }

    vector<pii> vec;
    for(i=2;i<=n;i++) vec.push_back(pii(1,i));
    lim = min(n,MAGIC);
    for(i=2;i<=lim;i++) for(j=i+1;j<=lim;j++) if(__gcd(i,j) == 1)
        vec.push_back(pii(i,j));

    if(vec.size() >= m)
    {
        printf("Possible\n");
        for(i=0;i<m;i++) printf("%d %d\n",vec[i].st,vec[i].nd);
    }
    else printf("Impossible\n");
    return 0;
}
