static bool compare(string first, string second)
{
	string one = first + second;
	string two = second + first;

	int i = 0;
	while (one[i] && two[i])
	{
		if (one[i] > two[i])
			return true;
		else if (one[i] < two[i])
			return false;
		i++;
	}
	return false;
}

public:
string largestNumber(vector<int>& nums)
{
	vector<string> s;
	int i;
	for (i = 0; i < nums.size(); i++)
		s.push_back(to_string(nums[i]));
	sort(s.begin(), s.end(), compare);

	if (s[0][0] == '0')
		return "0";
	string res = "";
	for (i = 0; i < s.size(); i++)
		res += s[i];
	return res;
}