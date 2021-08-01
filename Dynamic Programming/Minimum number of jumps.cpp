int minJumps(int arr[], int n) {
    // Your code here
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    int jumps = 1, curr_end = arr[0], maxRange = arr[0];
    for (int i = 1; i < n ; i++)
    {
        if (i == n - 1)
            return jumps;

        maxRange = max(maxRange, i + arr[i]);
        curr_end--;
        if (curr_end == 0)
        {
            jumps++;
            if (i >= maxRange)
                return -1;
            curr_end = maxRange - i;
        }
    }
    return -1;
}