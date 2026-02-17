///code by sonhotrung
///2 dòng này sẽ mất:)))
#include <bits/stdc++.h>
#define pb push_back
const int maxn=1e6+5;
const long long oo=1e18;
using namespace std;
int t,mod;
long long gt[maxn];
long long lt(int a,int b)
{
    if (b==0)
        return 1;
    long long tg=lt(a,b/2);
    tg=tg*tg%mod;
    if (b%2)
        tg=tg*a%mod;
    return tg;
}
long long C2(int n,int k)
{
    long long res=gt[n];
    res=res*lt(gt[k]*gt[n-k]%mod,mod-2)%mod;
    return res;
}
void sub2()
{
    while (t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        long long ans=C2(n-1,k);
        ans=ans*m%mod;
        ans=ans*lt(m-1,k)%mod;
        cout << ans << '\n';
    }
}
long long C3(int n,int k)
{
    long long res=1;
    for (int i=n; i>=n-k+1; --i)
        res=res*i%mod;
    res=res*lt(gt[k],mod-2)%mod;
    return res;
}
void sub3()
{
    while (t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        long long ans=C3(n-1,k);
        ans=ans*m%mod;
        ans=ans*lt(m-1,k)%mod;
        cout << ans << '\n';
    }
}
int KT[maxn];
vector <int> NT;
int getE(int n,int p)
{
    int res=0;
    long long pw=p;
    while (pw<=n)
    {
        res=(res+n/pw)%mod;
        pw=pw*p;
    }
    return res;
}
long long C4(int n,int k)
{
    if (k>n)
        return 0;
    long long res=1;
    for (int p:NT)
    {
        int exp=(getE(n,p)-getE(k,p)-getE(n-k,p)+mod)%mod;
        res=res*lt(p,exp)%mod;
    }
    return res;
}
void sub4()
{
    for (int i=2; i<=maxn-5; ++i)
        if (!KT[i])
        {
             NT.pb(i);
             for (int j=2*i; j<=maxn-5; j+=i)
                KT[j]=1;
        }
    while (t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        long long ans=C4(n-1,k);
        ans=ans*m%mod;
        ans=ans*lt(m-1,k)%mod;
        cout << ans << '\n';
    }
}
int main()
{
    freopen("flowers.inp","r",stdin);
    freopen("flowers.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> mod;
    gt[0]=1;
    for (int i=1; i<=1e6; ++i)
        gt[i]=(gt[i-1]*i)%mod;
    if (mod==998244353)
    {
        if (t>50)
            sub2();
        else
            sub3();
    }
    else
        sub4();
    return 0;
}
