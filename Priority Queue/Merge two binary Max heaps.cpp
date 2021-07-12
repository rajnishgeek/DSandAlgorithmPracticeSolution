class Solution {
    void maxHeapify(vector<int> &arr, int n, int idx)
    {
        // Find largest of node and its children
        if (idx >= n)
            return;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        int max;
        if (l < n && arr[l] > arr[idx])
            max = l;
        else
            max = idx;
        if (r < n && arr[r] > arr[max])
            max = r;

        // Put maximum value at root and
        // recur for the child with the
        // maximum value
        if (max != idx) {
            swap(arr[max], arr[idx]);
            maxHeapify(arr, n, max);
        }
    }

// Builds a max heap of given arr[0..n-1]
    void buildMaxHeap(vector<int> &arr, int n)
    {
        // building the heap from first non-leaf
        // node by calling max heapify function
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(arr, n, i);
    }
public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> res(n + m);
        for (int i = 0; i < n; i++)
            res[i] = a[i];
        for (int i = 0; i < m; i++)
            res[n + i] = b[i];
        buildMaxHeap(res, n + m);
        return res;

    }
};