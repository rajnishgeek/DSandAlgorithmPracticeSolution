vector<vector<int>> res;

void solve(vector<int> &A, int index, int sum, vector<int> v)
{
    if (sum == 0)
        res.push_back(v);
    if (index >= A.size())
        return;
    if (A[index] <= sum)
    {
        v.push_back(A[index]);
        // if(sum-A[index]==0)
        //  res.push_back(v);
        solve(A, index, sum - A[index], v);
        v.pop_back();
        solve(A, index + 1, sum, v);

    }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    // Your code here
    res.clear();
    sort(A.begin(), A.end());
    int i = 0, j = 1;
    while (j < A.size())
    {
        if (A[i] == A[j])
            j++;
        else
            A[++i] = A[j++];
    }
    A.resize(i + 1);
    solve(A, 0, B, vector<int> {});
    sort(res.begin(), res.end());
    return res;
}

//***************************************************************************

void solve(vector<int> &candidates, int left, vector<vector<int>> &res, vector<int> &sub, int start)
{
    if (left < 0)
        return;
    if (left == 0)
    {
        res.push_back(sub);
        return;
    }

    for (int i = start; i < candidates.size(); i++)
    {
        sub.push_back(candidates[i]);
        solve(candidates, left - candidates[i], res, sub, i);
        sub.pop_back();
    }
}
public:
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > res;
    vector<int> sub;
    sort(candidates.begin(), candidates.end());
    solve(candidates, target, res, sub, 0);
    return res;
}