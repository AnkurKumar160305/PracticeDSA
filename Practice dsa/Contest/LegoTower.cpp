long long minBricks(int n, long long h, const vector<long long> &a)
{
    if (h == 0)
    {
        return 0;
    }
    if (a.empty())
    {
        return 0;
    }
    vector<long long> x = a;
    sort(x.begin(), x.end());
    long long support = 0;
    long long curr = -1;
    for (long long pos : x)
    {
        long long start = pos;
        long long end = pos + 2;
        if (support == 0 || start > curr)
        {
            support++;
            curr = end;
        }
        else
        {
            curr = max(curr, end);
        }
    }
    return support;
}