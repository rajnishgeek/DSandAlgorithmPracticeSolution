vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    vector<int> res;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
            i++;
        else if (nums1[i] > nums2[j])
            j++;
    }
    return res;
}

// efficirent approach
// I see the majority of those posts use hashset to record values.
// Actually, we can simply adapt the Floyd Cycle detection algorithm.
// I believe that many people have seen this in the Linked List Cycle detection problem.
// The following is my code:

int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while (slow != fast);
    if (slow == 1) return 1;
    else return 0;
}
