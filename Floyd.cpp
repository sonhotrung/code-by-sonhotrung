void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    T[i][j] = T[i][k];
                }

}

void Truyxuat(int u,int v)
{
    int dem = 0;
    while (u != v)
    {
        dem++;
        Q[dem] = u;
        u = T[u][v];
    }
    dem++;Q[dem]=v;
    cout << dem << " ";
    for (int i = 1;i <= dem;++i)
        cout << Q[i] << " ";
    cout << endl;
}
Tham khảo:
https://oj.vnoi.info/problem/floyd
https://oj.vnoi.info/problem/vdanger

