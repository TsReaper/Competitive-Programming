#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,m,ans[200010];
char s[200010];

queue<int> q[2];
bool vis[200010];

int main()
{
    int i,j,x;

    scanf("%s",s+1); n = strlen(s+1);
    for(i=1;i<=n;i++) m += (s[i] == '0' ? 1 : -1);
    if(m <= 0) goto FAILED;

    for(i=1;i<=n;i++)
    {
        if(s[i] == '0')
        {
            if(!q[1].empty()) ans[q[1].front()] = i, q[1].pop();
            q[0].push(i);
        }
        else
        {
            if(!q[0].empty())
            {
                ans[q[0].front()] = i;
                q[0].pop(); q[1].push(i);
            }
            else goto FAILED;
        }
    }
    if(!q[1].empty()) goto FAILED;

    printf("%d\n",m);
    for(i=1;i<=n;i++) if(!vis[i])
    {
        for(j=i,x=1;ans[j];j=ans[j],x++) vis[j] = true;
        vis[j] = true;

        printf("%d ",x);
        for(j=i;ans[j];j=ans[j]) printf("%d ",j);
        printf("%d\n",j);
    }
    return 0;

    FAILED: printf("-1"); return 0;
}
