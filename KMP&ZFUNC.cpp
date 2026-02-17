ZFUN
///code by sonhotrung
///2 dòng này sẽ mất:)))
#include <bits/stdc++.h>
const int maxn=1e6+5;
const long long oo=1e18;
using namespace std;
string S,T;
int n,m;
int Z[2*maxn];
void Z_FuncTion(string s)
{
    int l=0,r=0;
    for (int i=1; i<n; ++i)
    {
        if (i<=r)
            Z[i]=min(Z[i-l],r-i+1);
        while (i+Z[i]<n&&s[Z[i]]==s[i+Z[i]])
            Z[i]++;
        if (i+Z[i]-1>r)
        {
            l=i;
            r=i+Z[i]-1;
        }
    }
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    cin >> S >> T;
    S=T+S;
    n = S.size();
    Z_FuncTion(S);
    m = T.size();
    for (int i=m; i<n; ++i)
        if (Z[i]>=m)
            cout << i-m+1 << ' ';
    return 0;
}

KMP
///code by sonhotrung
///2 dòng này sẽ mất:)))
#include <bits/stdc++.h>
const int maxn=1e6+5;
const long long oo=1e18;
using namespace std;
string S,T;
int kmp[maxn],nxt[maxn][26];
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> T;
    int n=S.size(),m=T.size();
    S=' '+S;
    T=' '+T;
    for (int i=0;i<=m;++i)
    {
        if (i>0)
            kmp[i]=min(i-1,nxt[kmp[i-1]][T[i]-'a']);
        for (char c='a';c<='z';++c)
        {
            if (i+1<=m&&T[i+1]==c)
                nxt[i][c-'a']=i+1;
            else
                nxt[i][c-'a']=nxt[kmp[i]][c-'a'];
        }
    }
    int j=0;
    for (int i=1;i<=n;++i)
    {
        j=nxt[j][S[i]-'a'];
        if (j==m)
            cout << i - m + 1 << " ";
    }
    return 0;
}
