#include <cstdio>
#include <vector>
using namespace std;

int n,m,S;
vector<int> ans;
bool win,draw;

int e[200010][2],p[100010];
bool vis[100010][2],instk[100010];

void adde(int sn,int fn)
{
    e[++m][0] = fn; e[m][1] = p[sn]; p[sn] = m;
}

void dfs(int sn,int c)
{
    int i,fn;
    ans.push_back(sn); instk[sn] = true;

    vis[sn][c] = true;
    if(!p[sn] && c == 1) { win = true; return; }

    for(i=p[sn];i;i=e[i][1])
    {
        fn = e[i][0];
        if(instk[fn]) draw = true;
        if(vis[fn][c^1]) continue;
        dfs(fn,c^1);
        if(win) return;
    }

    ans.pop_back(); instk[sn] = false;
}

int main()
{
    int i,j,x;

    scanf("%d%*d",&n);
    for(i=1;i<=n;i++) for(scanf("%d",&j);j;j--)
        scanf("%d",&x), adde(i,x);
    scanf("%d",&S);

    dfs(S,0);
    if(win)
    {
        printf("Win\n");
        for(i=0;i<ans.size();i++) printf("%d%c",ans[i],"\n "[i+1<ans.size()]);
    }
    else if(draw) printf("Draw\n");
    else printf("Lose\n");

    return 0;
}
