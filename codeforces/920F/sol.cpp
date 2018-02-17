#include <cstdio>
#define MAXA 1000000

int n,q,A[300010];
int D[1000010];

int tl,tr;
long long sumo[1200010];
bool fixo[1200010];

void update(int id,int l)
{
    sumo[id] = A[l];
    fixo[id] = (A[l] <= 2);
}

void update(int id)
{
    int nxt = id<<1;
    sumo[id] = sumo[nxt] + sumo[nxt|1];
    fixo[id] = fixo[nxt] && fixo[nxt|1];
}

void build(int id,int l,int r)
{
    int nxt = id<<1,mid = (l+r)>>1;
    if(l == r) update(id,l);
    else
    {
        build(nxt,l,mid); build(nxt|1,mid+1,r);
        update(id);
    }
}

void modify(int id,int l,int r)
{
    int nxt = id<<1,mid = (l+r)>>1;
    if(fixo[id]) return;
    if(l == r) A[l] = D[A[l]], update(id,l);
    else
    {
        if(tl <= mid) modify(nxt,l,mid);
        if(tr > mid) modify(nxt|1,mid+1,r);
        update(id);
    }
}

long long query(int id,int l,int r)
{
    int nxt = id<<1,mid = (l+r)>>1;
    if(tl <= l && r <= tr) return sumo[id];
    return (tl <= mid ? query(nxt,l,mid) : 0) + (tr > mid ? query(nxt|1,mid+1,r) : 0);
}

int main()
{
    int i,j,op;
    for(i=1;i<=MAXA;i++) for(j=i;j<=MAXA;j+=i) D[j]++;

    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    build(1,1,n);
    while(q--)
    {
        scanf("%d%d%d",&op,&tl,&tr);
        if(op == 1) modify(1,1,n);
        else printf("%I64d\n",query(1,1,n));
    }

    return 0;
}
