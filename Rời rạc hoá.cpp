int TKNP(int d,int c,int x)
{
    while (d<=c)
    {
        int g=(d+c)/2;
        if (RR[g]==x)
            return g;
        if (RR[g]>x)
            c=g-1;
        else
            d=g+1;
    }
}

Void roirac()
{
    for (int i=1;i<=n;i++) // n
        TG[i]=A[i];

    sort(TG+1,TG+n+1); // n log(n)
    int top=1;
    RR[1]=TG[1];
    for (int i=2;i<=n;++i) // n
        if (RR[top]!=TG[i])
        {
            top++;
            RR[top]=TG[i];
        }

    for (int i=1;i<=n;i++) // n log(n)
        B[i]=TKNP(1,top,A[i]);
    // doan tren la roi rac hoa
}
Cách 2
   vector <int> v (A+1,A+n+1);
   sort (v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
    	for (int i=1;i<=n;++i)        
A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;



Tham khảo bài: https://oj.vnoi.info/problem/bedao_m09_cntdiff

