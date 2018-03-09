#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,H,U[100010];

int tot,e[200010][2],p[100010];
int bcnt,bel[100010],siz[100010],deg[100010];

int clk,dfn[100010],low[100010];
int top,stk[100010];
bool inStk[100010];

void adde(int sn,int fn)
{
    e[++tot][0] = fn; e[tot][1] = p[sn]; p[sn] = tot;
}

void tarjan(int sn)
{
    int i,fn;
    dfn[sn] = low[sn] = ++clk;
    stk[++top] = sn; inStk[sn] = true;

    for(i=p[sn];i;i=e[i][1])
    {
        fn = e[i][0];
        if(!dfn[fn]) tarjan(fn), low[sn] = min(low[sn],low[fn]);
        else if(inStk[fn]) low[sn] = min(low[sn],dfn[fn]);
    }

    if(dfn[sn] == low[sn])
    {
        bcnt++;
        do
        {
            fn = stk[top--];
            bel[fn] = bcnt; siz[bcnt]++;
            inStk[fn] = false;
        }
        while(fn != sn);
    }
}

int main()
{
    int i,sn,fn,ans = 0;

    scanf("%d%d%d",&n,&m,&H);
    for(i=1;i<=n;i++) scanf("%d",&U[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&sn,&fn);
        if((U[sn]+1)%H == U[fn]) adde(sn,fn);
        if((U[fn]+1)%H == U[sn]) adde(fn,sn);
    }

    for(i=1;i<=n;i++) if(!dfn[i]) tarjan(i);

    for(sn=1;sn<=n;sn++) for(i=p[sn];i;i=e[i][1])
    {
        fn = e[i][0];
        if(bel[sn] != bel[fn]) deg[bel[sn]]++;
    }
    for(i=1;i<=bcnt;i++) if(!deg[i])
        if(ans == 0 || siz[i] < siz[ans]) ans = i;

    printf("%d\n",siz[ans]);
    for(i=1;i<=n;i++) if(bel[i] == ans) printf("%d ",i);

    return 0;
}
