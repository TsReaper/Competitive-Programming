#include <bits/stdc++.h>
using namespace std;

int n,m;
long long ans;
string w[100010],s[100010];

unordered_map<string,int> mp;
int id[100010],cnt[100010];

int main()
{
    int i,j,x;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) cin >> w[i];
    for(i=1;i<=m;i++)
    {
        cin >> s[i];
        mp[s[i]] = mp.size();
    }

    for(i=1;i<=n;i++)
    {
        if(mp.find(w[i]) == mp.end()) id[i] = 0;
        else id[i] = mp[w[i]];
    }

    x = 0;
    for(i=j=1;i<=n;i++)
    {
        for(;j<=n&&x<m;j++) if(id[j])
        {
            if(cnt[id[j]] == 0) x++;
            cnt[id[j]]++;
        }
        if(x == m) ans += n-j+2;
        if(!id[i]) continue;
        cnt[id[i]]--;
        if(cnt[id[i]] == 0) x--;
    }

    printf("%lld",ans);
    return 0;
}
