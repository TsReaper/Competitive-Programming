#include <cstdio>
#include <algorithm>
#define INF 2e18
using namespace std;

int n,q,A[100010];

int tl,tr,tv;
long long base,mino[400010],maxo[400010];

void update(int id)
{
    int nxt = id<<1;
    mino[id] = min(mino[nxt],mino[nxt|1]);
    maxo[id] = max(maxo[nxt],maxo[nxt|1]);
}

void build(int id,int l,int r)
{
    int nxt = id<<1,mid = (l+r)>>1;
    if(l == r) mino[id] = maxo[id] = A[l];
    else
    {
        build(nxt,l,mid); build(nxt|1,mid+1,r);
        update(id);
    }
}

void add(int id,int l,int r)
{
    int nxt = id<<1,mid = (l+r)>>1;
    if(l == r) mino[id] += tv, maxo[id] += tv;
    else
    {
        if(tl <= mid) add(nxt,l,mid);
        else add(nxt|1,mid+1,r);
        update(id);
    }
}

long long value(int id,int l,int r)
{
    int nxt = id<<1,mid = (l+r)>>1;
    if(l == r) return mino[id];
    return tl <= mid ? value(nxt,l,mid) : value(nxt|1,mid+1,r);
}

long long minVal(int id,int l,int r)
{
    int nxt = id<<1,mid = (l+r)>>1;
    if(tl <= l && r <= tr) return mino[id];
    return min(tl <= mid ? minVal(nxt,l,mid) : INF, tr > mid ? minVal(nxt|1,mid+1,r) : INF);
}

long long maxVal(int id,int l,int r)
{
    int nxt = id<<1,mid = (l+r)>>1;
    if(tl <= l && r <= tr) return maxo[id];
    return max(tl <= mid ? maxVal(nxt,l,mid) : -INF, tr > mid ? maxVal(nxt|1,mid+1,r) : -INF);
}

int find(int id,int l,int r)
{
    int nxt = id<<1,mid = (l+r)>>1;
    if(l == r) return maxo[id] >= 0 ? l : -1;
    if(tl <= l && r <= tr)
    {
        if(maxo[id] < 0) return -1;
        return maxo[nxt] >= 0 ? find(nxt,l,mid) : find(nxt|1,mid+1,r);
    }
    int t = -1;
    if(tl <= mid) t = find(nxt,l,mid);
    if(t < 0 && tr > mid) t = find(nxt|1,mid+1,r);
    return t;
}

long long query(int l,int r,int x)
{
    long long v,ret = 0;

    if(l == 1)
    {
        tl = tr = 2;
        v = value(1,1,n+1);
        ret = max(ret,base-abs(v)+abs(v-x));
        l = 2;
    }
    if(r == n)
    {
        tl = tr = n;
        v = value(1,1,n+1);
        ret = max(ret,base-abs(v)+abs(v+x));
        r = n-1;
    }
    if(l > r) return ret;

    if(tl = l, tr = r+1, minVal(1,1,n+1) >= 0)
    {
        tl = l+1; tr = r+1; v = minVal(1,1,n+1);
        ret = max(ret,base+2*max(0LL,x-v));
    }
    else if(tl = l, tr = r+1, maxVal(1,1,n+1) <= 0)
    {
        tl = l; tr = r; v = maxVal(1,1,n+1);
        ret = max(ret,base+2*max(0LL,x+v));
    }
    else
    {
        int t;
        tl = l; tr = r+1; t = find(1,1,n+1);
        tl = t; tr = r+1; v = minVal(1,1,n+1);
        if(v < 0) ret = max(ret,base+2*x);
        else
        {
            if(t+1 <= r+1)
            {
                tl = t+1; tr = r+1; v = minVal(1,1,n+1);
                ret = max(ret,base+2*max(0LL,x-v));
            }
            if(l <= t-2)
            {
                tl = l; tr = t-2; v = maxVal(1,1,n+1);
                ret = max(ret,base+2*max(0LL,x+v));
            }
            tl = tr = t-1;
            long long v1 = value(1,1,n+1);
            tl = tr = t;
            long long v2 = value(1,1,n+1);
            ret = max(ret,base-abs(v1)-abs(v2)+abs(v1+x)+abs(v2-x));
        }
    }

    return ret;
}

int main()
{
    int i,l,r,x,op;

    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    for(i=n,A[n+1]=-A[i];i>1;i--) A[i] -= A[i-1], base += abs(A[i]);
    build(1,1,n+1);

    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d%d",&op,&l,&r,&x);
        if(op == 1) printf("%I64d\n",query(l,r,x));
        else
        {
            if(l > 1) tl = tr = l, base -= abs(value(1,1,n+1));
            if(r < n) tl = tr = r+1, base -= abs(value(1,1,n+1));
            tl = tr = l; tv = x; add(1,1,n+1);
            tl = tr = r+1; tv = -x; add(1,1,n+1);
            if(l > 1) tl = tr = l, base += abs(value(1,1,n+1));
            if(r < n) tl = tr = r+1, base += abs(value(1,1,n+1));
        }
    }

    return 0;
}
