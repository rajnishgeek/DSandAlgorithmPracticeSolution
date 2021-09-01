bool isValid(int a[], int n, int k, int max)
{
    int student = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > max)
        {
            student++;
            sum = a[i];
        }
        if (student > k)
            return false;
    }
    return true;
}


int findPages(int arr[], int n, int m)
{
    //code here
    if (m > n)
        return -1;
    int start = INT_MIN, end = 0;

    for (int i = 0; i < n; i++)
    {
        end += arr[i];
        if (start < arr[i])
            start = arr[i];
    }

    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, m, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return res;
}