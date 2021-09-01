int findPosition(int N)
{
    // code here
    int position = -1;
    for (int i = 1; N; i++)
    {
        if (N & 1)
        {
            if (position != -1)
                return -1;
            position = i;
        }
        N >>= 1;
    }
    return position;
}