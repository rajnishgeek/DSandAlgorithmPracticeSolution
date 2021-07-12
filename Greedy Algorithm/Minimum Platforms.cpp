bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int, int>> time;
    for (int i = 0; i < n; i++)
        time.push_back(make_pair(arr[i], dep[i]));
    sort(time.begin(), time.end(), compare);
    int lastDep = time[0].second;
    int count = 1;
    for (int i = 1; i < time.size(); i++)
    {
        if (lastDep <= time[i].first)
        {
            lastDep = time[i].second;
        }
        else
            cout++;
    }
    return count;
}