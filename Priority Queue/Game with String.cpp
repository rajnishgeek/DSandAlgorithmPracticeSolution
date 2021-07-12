int minValue(string s, int k)
{
    // code here
    int freq[26] = {0};
    for (int i = 0; i < s.size(); i++)
        freq[s[i] - 'a']++;

    priority_queue<int> pq;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
            pq.push(freq[i]);
    }


    while (!pq.empty() && k--)
    {
        int temp = pq.top();
        pq.pop();
        pq.push(temp - 1);
    }
    int sum = 0;
    while (!pq.empty())
    {
        int temp = pq.top();
        pq.pop();
        sum += temp * temp;
    }
    return sum;
}