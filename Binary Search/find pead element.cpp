int findPeakElement(vector<int>& nums)
{
   int left = 0, right = nums.size() - 1;
   while (left < right)
   {
      int middle1 = left + (right - left) / 2;
      int middle2 = middle1 + 1;
      if (nums[middle1] < nums[middle2])
         left = middle2;
      else
         right = middle1;
   }
   return left;
}