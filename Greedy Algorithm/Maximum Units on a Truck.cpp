bool compare(vector<int> a, vector<int> b)
{
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
{
    int n = boxTypes.size();
    sort(boxTypes.begin(), boxTypes.end(), compare);
    int result = 0;
    for (int i = 0; i < n && truckSize > 0; i++)
    {
        if (truckSize >= boxTypes[i][0])
        {
            result += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        else
        {
            result += truckSize * boxTypes[i][1];
            truckSize = 0;
        }
    }
    return result;
}