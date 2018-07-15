#include <cstdio>
#include <vector>
using namespace std;

int n,ans[1000010];

int e[2000010][2],p[1000010];

int id[1000010],dom[1000010];
vector<int> vec[1000010];

void adde(int id,int sn,int fn)
{
    e[id][0] = fn; e[id][1] = p[sn]; p[sn] = id;
}

void merge(int a,int &x,int y)
{
    int i,j;
    if(vec[x].size() < vec[y].size() + 1)
    {
        dom[x] = dom[y];
        int t = x; x = y; y = t;
        vec[x].push_back(1); *(vec[y].rbegin()) = 0;
    }
    else vec[y].push_back(0);

    for(i=vec[x].size()-1,j=vec[y].size()-1;j>=0;i--,j--) vec[x][i] += vec[y][j];
    for(i=0,j=vec[x].size()-1;i<vec[y].size();i++,j--)
    {
        if(vec[x][j] > vec[x][dom[x]]) dom[x] = j;
        else if(vec[x][j] == vec[x][dom[x]] && j > dom[x]) dom[x] = j;
    }
    ans[a] = vec[x].size() - dom[x] - 1;
}

void dfs(int sn,int fa)
{
    int i,fn;
    id[sn] = sn; vec[sn].push_back(1);

    for(i=p[sn];i;i=e[i][1])
    {
        if((fn = e[i][0]) == fa) continue;
        dfs(fn,sn);
        merge(sn,id[sn],id[fn]);
    }
}

int main()
{
    int i,sn,fn;

    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&sn,&fn);
        adde(i<<1,sn,fn); adde(i<<1|1,fn,sn);
    }

    dfs(1,0);
    for(i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}
