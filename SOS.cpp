Xuôi: tính tổng a[mask’] là submask của mask
for(int i = 0; i < 20; ++i)
{
    for(int mask = 0; mask < (1<<20); ++mask)
    {
        if(BIT(mask, i))
            a[mask] += a[mask ^ (1<<i)];
    }
}
Ngược: tính tổng a[mask’] với mask’ là submask của mask
for(int i = 0; i < 20; ++i)
{
    for(int mask = (1<<20)-1; mask >= 0; --mask)
    {
        if(!BIT(mask, i))
            a[mask] += a[mask ^ (1<<i)];
    }
}

