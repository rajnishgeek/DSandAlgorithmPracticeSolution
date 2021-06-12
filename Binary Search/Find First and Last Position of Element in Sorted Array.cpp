int moveLeftSideBS(vector<int> &num, int target)
{
    int index = -1, start = 0, end = num.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (num[mid] == target)
        {
            index = mid;
            end = mid - 1;
        }
        else if (target < num[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return index;
}

int moveRightSideBS(vector<int> &num, int target)
{
    int index = -1, start = 0, end = num.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (num[mid] == target)
        {
            index = mid;
            start = mid + 1;
        }
        else if (target < num[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return index;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> res(2, -1);
    if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target))
        return res;

    res[0] = moveLeftSideBS(nums, target);
    res[1] = moveRightSideBS(nums, target);

    return res;
}