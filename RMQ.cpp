for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] ;
        nn[i][0] = a[i];
        ln[i][0] = a[i];
    }
for (int j=1; (1<<j)<=n; ++j)
        for (int i=1; i+(1<<j)-1<=n; ++i)
        {
            Amin[i][j]=min(Amin[i][j-1],Amin[i+(1<<(j-1))][j-1]);
            Amax[i][j]=max(Amax[i][j-1],Amax[i+(1<<(j-1))][j-1]);
        }    int getmax(int u, int v)
    {
        int tmp = log2(v-u+1);
        return max(ln[u][tmp], ln[v - (1<<tmp)+1][tmp]);
    }
    int getmin(int u, int v)
    {
        int tmp = log2(v-u+1);
        return min(nn[u][tmp], nn[v - (1<<tmp)+1][tmp]);
    }

