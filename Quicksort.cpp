void QS(int l,int r)
{
    int i,j;
    if (l>r)
        return;
    i=l;j=r;
    g=A[(l+r)/2];
    do
    {
        while (A[j]>g)
            j--;
        while (A[i]<g)
            i++;
        if (i<=j)
        {
            swap(A[i],A[j]);
            i++;j--;
        }
    }
    while (i<=j);
    QS(i,r);
    QS(l,j);
}
