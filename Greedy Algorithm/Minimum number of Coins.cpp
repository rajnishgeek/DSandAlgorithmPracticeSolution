vector<int> money = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

vector<int> minPartition(int N)
{
    // code here
    vector<int> res;
    for (int i = 9; i >= 0 && N > 0;)
    {
        if (money[i] <= N)
        {
            res.push_back(money[i]);
            N -= money[i];
        }
        else
            i--;
    }
    return res;
}