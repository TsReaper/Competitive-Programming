#include <cstdio>

int n,A[200010];
char s[200010];

int tree[200010],cnt[200010],sum[200010];

void add(int pos,int val)
{
    for(;pos<=n;pos+=pos&(-pos)) tree[pos] += val;
}

int query(int pos)
{
    int ret = 0;
    for(;pos;pos-=pos&(-pos)) ret += tree[pos];
    return ret;
}

int main()
{
    int i,p;

    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    scanf("%s",s+1);

    for(i=n;i;i--)
    {
        cnt[A[i]] = query(A[i]);
        add(A[i],1);
    }
    for(i=1;i<=n;i++) sum[i] = sum[i-1] + s[i] - '0';

    for(i=1;i<=n;i++)
    {
        p = i + cnt[A[i]];
        if(sum[A[i]-1] - sum[p-1] != A[i] - p) goto NO;
    }
    printf("YES"); return 0;
    NO: printf("NO"); return 0;
}
