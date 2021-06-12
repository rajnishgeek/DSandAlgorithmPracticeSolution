class MyCalendar {
    vector<pair<int, int>> events;
public:
    MyCalendar() {
    }

    bool book(int start, int end)
    {
        for (pair<int, int> p : events)
        {
            if (max(start, p.first) < min(end, p.second))
                return false;
        }
        events.push_back({start, end});
        return true;

    }
};