vector<string> allPath;
void findAllPath(vector<vector<int>> m, int n, int i, int j, string s)
{
    if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] == 0)
        return;
    if (i == n - 1 && j == n - 1)
    {
        allPath.push_back(s);
        return;
    }
    m[i][j] = 0;
    findAllPath(m, n, i - 1, j, s + "U");
    findAllPath(m, n, i + 1, j, s + "D");
    findAllPath(m, n, i, j - 1, s + "L");
    findAllPath(m, n, i, j + 1, s + "R");

    m[i][j] = 1;
}
public:
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    allPath.clear();
    findAllPath(m, n, 0, 0, "");
    sort(allPath.begin(), allPath.end());
    return allPath;
}