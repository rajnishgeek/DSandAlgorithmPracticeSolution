long long int maxSum(int arr[], int n)
{
    sort(arr, arr + n);
    vector<int> v(n);
    int i = 0, j = n - 1, p = 0;
    while (i <= j && p < n)
    {
        v[p++] = arr[i++];
        if (i <= j && p < n)
            v[p++] = arr[j--];
    }
    long long int sum = 0;
    for (int i = 1; i < n; i++)
        sum += abs(v[i] - v[i - 1]);
    sum += abs(v[n - 1] - v[0]);
    return sum;
}

//****************************************************
//time O(n), space O(1)
int maxSum(int arr[], int n)
{
    int sum = 0;

    // Sorting the array.
    sort(arr, arr + n);

    // Subtracting a1, a2, a3,....., a(n/2)-1, an/2
    // twice and adding a(n/2)+1, a(n/2)+2, a(n/2)+3,.
    // ...., an - 1, an twice.
    for (int i = 0; i < n / 2; i++)
    {
        sum -= (2 * arr[i]);
        sum += (2 * arr[n - i - 1]);
    }

    return sum;
}
