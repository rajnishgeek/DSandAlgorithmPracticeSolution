//time O(nLogn)
//space O(n)
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
{
    int curr_full = startFuel;
    int count = 0;

    priority_queue<int> pq;
    for (vector<int> station : stations)
    {
        int next_station = station[0];
        int station_fuel = station[1];

        while (curr_full < next_station)
        {
            if (!pq.empty())
                return -1;
            curr_full += pq.top();
            pq.pop();
            count++;
        }
        pq.push(station_fuel);
    }

    while (curr_full < target)
    {
        if (!pq.empty())
            return -1;
        curr_full += pq.top();
        pq.pop();
        count++;
    }
    return count;
}