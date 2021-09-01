int totalFruit(vector<int>& fruits)
{
	int maxFruit = 0, currMax = 0;
	int left = 0, right = 0, countLeft = 0, countRight = 0;
	for (int i = 0; i < fruits.size(); i++)
	{
		currMax = (left == fruits[i] || right == fruits[i]) ? currMax + 1 : countRight + 1;
		countRight = (right == fruits[i]) ? countRight + 1 : 1;
		if (right != fruits[i])
		{
			left = right;
			right = fruits[i];
		}
		maxFruit = max(maxFruit, currMax);
	}
	return maxFruit;
}