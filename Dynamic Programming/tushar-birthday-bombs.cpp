vector<int> birthdayBombs(int A, vector<int> &B)
{
	auto it = min_element(B.begin(), B.end());
	int minStrength = *it;
	int minIdx = it - B.begin();
	int maxHits = A / minStrength;
	int remStrength = A % minStrength;
	vector<int>res(maxHits, minIdx);
	int j = 0;
	int i = 0;
	while (remStrength > 0 && i < minIdx && j < maxHits) {
		int diff = B[i] - minStrength;
		if (remStrength - diff >= 0) {
			remStrength = remStrength - diff;
			res[j] = i;
			j++;
		} else {
			i++;
		}
	}
	return res;
}