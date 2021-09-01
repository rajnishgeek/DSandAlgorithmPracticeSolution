vector<int> singleNumber(vector<int> nums)
{
    int n = nums.size();
    int x_xor_y = 0;
    for (int i = 0; i < n; i++)
        x_xor_y ^= nums[i];

    int right_most_bit = x_xor_y & ~(x_xor_y - 1);

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if ((nums[i]&right_most_bit) == 0) //bit is not set
            x ^= nums[i];
        else
            y ^= nums[i];
    }

    return x <= y ? vector<int> {x, y}: vector<int> {y, x};
}