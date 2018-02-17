#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

int n,m;
vector<int> ans;

unordered_set<long long> e;
set<int> unvis;

long long getId(int a,int b)
{
    return 1LL*a*n+b;
}

int dfs(int sn)
{
    int fn,ret = 1;
    unvis.erase(sn);

    fn = 0;
    while(true)
    {
        auto it = unvis.upper_bound(fn);
        if(it == unvis.end()) break;
        fn = *it;
        if(e.find(getId(sn,fn)) != e.end()) continue;
        ret += dfs(fn);
    }

    return ret;
}

int main()
{
    int i,sn,fn;

    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&sn,&fn);
        e.insert(getId(sn,fn));
        e.insert(getId(fn,sn));
    }

    for(i=1;i<=n;i++) unvis.insert(i);
    while(unvis.size() > 0) ans.push_back(dfs(*(unvis.begin())));
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++) printf("%d%c",ans[i],"\n "[i<ans.size()-1]);

    return 0;
}
