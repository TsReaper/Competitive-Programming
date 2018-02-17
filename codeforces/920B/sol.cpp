#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXT 5000
#define ARRIVE first.first
#define ID first.second
#define LEAVE second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;

int tcase,n,ans[1010];
piii stu[1010];

int head,tail,q[1010];

int main()
{
    int i,j;

    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d",&n);
        memset(ans,0,sizeof(int)*(n+3));
        for(i=1;i<=n;i++) scanf("%d%d",&stu[i].ARRIVE,&stu[i].LEAVE), stu[i].ID = i;
        sort(stu+1,stu+n+1);

        head = tail = 1;
        for(i=1;i<=MAXT;i++)
        {
            for(j=1;j<=n;j++) if(stu[j].ARRIVE == i) q[tail++] = j;
            while(head < tail && stu[q[head]].LEAVE < i) head++;
            if(head < tail) ans[q[head]] = i, head++;
        }

        for(i=1;i<=n;i++) printf("%d%c",ans[i],"\n "[i<n]);
    }

    return 0;
}
