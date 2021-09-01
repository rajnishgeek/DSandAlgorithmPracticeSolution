int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
{
   int mod = pow(10, 9) + 7;
   sort(horizontalCuts.begin(), horizontalCuts.end());
   sort(verticalCuts.begin(), verticalCuts.end());

   int lastElement = horizontalCuts[0];
   int n = horizontalCuts.size(), maxHeightDiff = 0;
   for (int i = 1; i < n; i++)
   {
      maxHeightDiff = max(maxHeightDiff, horizontalCuts[i] - lastElement);
      lastElement = horizontalCuts[i];
   }

   int maxWeidthDiff = 0;
   lastElement = verticalCuts[0], n = verticalCuts.size();
   for (int i = 1; i < n; i++)
   {
      maxWeidthDiff = max(maxWeidthDiff, verticalCuts[i] - lastElement);
      lastElement = verticalCuts[i];
   }

   return ((maxWeidthDiff % mod) * (maxHeightDiff % mod));
}