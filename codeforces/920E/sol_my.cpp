#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#define st first
#define nd second
using namespace std;

int n,m;
vector<int> ans;
unordered_set<long long> e;

int root[200010],siz[200010];
vector<int> vec;
unordered_map<int,vector<int>> mp;

long long getId(int sn,int fn)
{
    return 1LL*sn*n + fn;
}

int findroot(int nod)
{
    if(root[nod] != nod) root[nod] = findroot(root[nod]);
    return root[nod];
}

void merge(int x,int y)
{
    x = findroot(x); y = findroot(y);
    if(x == y) return;
    siz[y] += siz[x];
    root[x] = y;
}

int main()
{
    int i,j,x,sn,fn;
    bool flag;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) root[i] = i, siz[i] = 1;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&sn,&fn);
        e.insert(getId(sn,fn));
        e.insert(getId(fn,sn));
    }

    vec.push_back(1);
    for(i=2;i<=n;i++)
    {
        flag = true;
        for(j=0;j<vec.size();j++) if(e.find(getId(i,vec[j])) == e.end())
        {
            flag = false;
            merge(vec[j],i);
        }
        if(flag) vec.push_back(i);
    }

    for(i=1;i<=n;i++)
    {
        x = findroot(i);
        if(mp.find(x) == mp.end()) mp[x] = vector<int>();
        mp[x].push_back(i);
    }
    for(auto it=mp.begin();it!=mp.end();it++)
        for(auto u=it->nd.begin();u!=it->nd.end();u++)
            for(auto it2=next(it);it2!=mp.end();it2++)
                for(auto v=it2->nd.begin();v!=it2->nd.end();v++)
                    if(e.find(getId(*u,*v)) == e.end())
                    {
                        merge(*u,*v);
                        break;
                    }

    for(i=1;i<=n;i++) if(findroot(i) == i) ans.push_back(siz[i]);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++) printf("%d%c",ans[i],"\n "[i<ans.size()-1]);
    return 0;
}
