int leastInterval(vector<char>& tasks, int n)
{
    int result = 0;
    if (tasks.size() == 0)
        return result;
    unordered_map<char, int> freq;
    for (int i = 0; i < tasks.size(); i++)
        freq[tasks[i]]++;

    priority_queue<int> pq;
    for (auto it : freq)
        pq.push(it.second);
    while (!pq.empty())
    {
        vector<int> leftTasks;
        int times = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            if (!pq.empty())
            {
                times++;
                int taskTime = pq.top() - 1;
                pq.pop();
                if (taskTime != 0)
                    leftTasks.push_back(taskTime);
            }
        }
        for (int i = 0; i < leftTasks.size(); i++)
            pq.push(leftTasks[i]);
        result += times;
    }
    return result;
}