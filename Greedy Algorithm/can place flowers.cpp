bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    if (n == 0)
        return true;
    for (int i = 0; i < flowerbed.size();)
    {
        if (flowerbed[i] == 1)
            i += 2;
        else if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
        {
            if (--n == 0)
                return true;
            i += 2;
        }
        else
            i++;
    }
    return false;
}