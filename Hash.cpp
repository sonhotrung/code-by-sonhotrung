mod[3]= {oo+7,oo+9,998244353};
void init()
{
    for (int i=1; i<=n; ++i)
        for (int j=0; j<3; ++j)
        {
            H1[i][j]=(H1[i-1][j]*37%mod[j]+S1[i]-'a')%mod[j];
            H2[i][j]=(H2[i-1][j]*37%mod[j]+S2[i]-'a')%mod[j];
        }
    for (int i=0; i<3; ++i)
    {
        Mu[0][i]=1;
        for (int j=1; j<=n; ++j)
            Mu[j][i]=Mu[j-1][i]*37%mod[i];
    }
}
long long getH(int i,int j,int tp)
{
    return (H[j][tp]-H[i-1][tp]*Mu[j-i+1][tp]%mod[tp]+mod[tp])%mod[tp];
}
bool ss(int vt1,int vt2,int dd)
{
    int cnt=0;
    for (int j=0;j<3;++j)
        if (getH1(vt1,vt1+dd-1,j)==getH2(vt2,vt2+dd-1,j))
            cnt++;
    return (cnt>1);
}

Bài mẫu: https://oj.vnoi.info/problem/substr
