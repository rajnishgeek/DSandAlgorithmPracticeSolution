vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
{
    vector<vector<int>> result;
    vector<int> temp(2);
    int indexA = 0, indexB = 0, n1 = firstList.size(), n2 = secondList.size();
    while (indexA < n1  && indexB < n2)
    {
        if (firstList[indexA][1] >= secondList[indexB][0] && firstList[indexA][0] <= secondList[indexB][1])
        {
            temp[0] = max(firstList[indexA][0], secondList[indexB][0]);
            temp[1] = min(firstList[indexA][1], secondList[indexB][1]);
            result.push_back(temp);
        }
        //incrementing index
        if (firstList[indexA][1] > secondList[indexB][1])
            indexB++;
        else
            indexA++;
    }
    return result;

}