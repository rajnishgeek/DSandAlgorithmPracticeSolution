int i = 0;

string decodeString(string s)
{
	string res = "";
	while (i < s.size() && s[i] != ']')
	{
		if (isdigit(s[i]))
		{
			int k = 0;
			while (i < s.size() && isdigit(s[i]))
				k = k * 10 + (s[i++] - '0');
			i++;
			string r = decodeString(s);
			while (k--)
				res += r;
			i++;
		}
		else
			res.push_back(s[i++]);
	}
	return res;
}