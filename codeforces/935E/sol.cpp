#include <cstdio>
#include <cstring>
#include <algorithm>
#define st first
#define nd second
#define MAXP 15
using namespace std;
typedef pair<int,int> pii;

int n,P,M;
char s[10010];

int f[10010][110],g[10010][110];
bool visf[10010][110],visg[10010][110];

pii rmq[17][10010];
int lg[10010];

void prepare()
{
    int i,j,a,b,cnt = 0;
    for(i=2,lg[1]=0;i<=n;i++) lg[i] = lg[i>>1]+1;

    for(i=1;i<=n;i++)
    {
        if(s[i] == '(') cnt++;
        else if(s[i] == ')') cnt--;
        if(s[i] == '?') rmq[0][i] = pii(cnt,i);
        else rmq[0][i] = pii(n,i);
    }

    for(i=1;i<=MAXP;i++)
    {
        a = 1<<i; b = a>>1;
        for(j=1;j+a-1<=n;j++) rmq[i][j] = min(rmq[i-1][j],rmq[i-1][j+b]);
    }
}

int query(int l,int r)
{
    int i = lg[r-l+1];
    return min(rmq[i][l],rmq[i][r-(1<<i)+1]).nd;
}

int dpMin(int l,int r,int v,int k);
int dpMax(int l,int r,int v,int k);

int dpMin(int l,int r,int v,int k)
{
    if(l == r) return v ? 1e7 : s[l] - '0';
    if(visg[l][v]) return g[l][v];
    visg[l][v] = true;

    int i,pos = query(l,r);
    g[l][v] = 1e7;
    if(k == 1)
    {
        for(i=0;i<v;i++) g[l][v] = min(g[l][v],dpMin(l+1,pos-1,i,k)+dpMin(pos+1,r-1,v-1-i,k));
        for(i=0;i<=v;i++) g[l][v] = min(g[l][v],dpMin(l+1,pos-1,i,k)-dpMax(pos+1,r-1,v-i,k));
    }
    else
    {
        for(i=0;i<v;i++) g[l][v] = min(g[l][v],dpMin(l+1,pos-1,i,k)-dpMax(pos+1,r-1,v-1-i,k));
        for(i=0;i<=v;i++) g[l][v] = min(g[l][v],dpMin(l+1,pos-1,i,k)+dpMin(pos+1,r-1,v-i,k));
    }
    return g[l][v];
}

int dpMax(int l,int r,int v,int k)
{
    if(l == r) return v ? -1e7 : s[l] - '0';
    if(visf[l][v]) return f[l][v];
    visf[l][v] = true;

    int i,pos = query(l,r);
    f[l][v] = -1e7;
    if(k == 1)
    {
        for(i=0;i<v;i++) f[l][v] = max(f[l][v],dpMax(l+1,pos-1,i,k)+dpMax(pos+1,r-1,v-1-i,k));
        for(i=0;i<=v;i++) f[l][v] = max(f[l][v],dpMax(l+1,pos-1,i,k)-dpMin(pos+1,r-1,v-i,k));
    }
    else
    {
        for(i=0;i<v;i++) f[l][v] = max(f[l][v],dpMax(l+1,pos-1,i,k)-dpMin(pos+1,r-1,v-1-i,k));
        for(i=0;i<=v;i++) f[l][v] = max(f[l][v],dpMax(l+1,pos-1,i,k)+dpMax(pos+1,r-1,v-i,k));
    }
    return f[l][v];
}

int main()
{
    scanf("%s%d%d",s+1,&P,&M); n = strlen(s+1);
    if(n == 1) { printf("%c",s[1]); return 0; }

    prepare();
    if(P<M) printf("%d",dpMax(1,n,P,1));
    else printf("%d",dpMax(1,n,M,-1));
    return 0;
}
