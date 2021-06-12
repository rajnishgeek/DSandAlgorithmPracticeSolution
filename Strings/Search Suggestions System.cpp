vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
{
    sort(products.begin(), products.end());
    vector<vector<string>> result(searchWord.size());
    for (int i = 1; i <= searchWord.size(); i++)
    {
        string w = searchWord.substr(0, i);
        auto it = lower_bound(products.begin(), products.end(), w);
        for (; it != products.end() && it->substr(0, i) == w && result[i - 1].size() < 3; it++)
            result[i - 1].push_back(*it);
    }
    return result;
}