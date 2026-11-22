class Solution {
public:
    bool solve(vector<int>& nums, int index, int target) {
        int n = nums.size();
      
        // BASE case
        if (target == 0)
            return true;

        if (index >= n || target < 0)
            return false;

      // Apna Kaam
      
        // Include
        bool includeKaAns = solve(nums, index + 1,
                                 target - nums[index]);

        // Exclude
        bool excludeKaAns = solve(nums, index + 1,
                                 target);
      
        // Merge both the include and exclude ans using OR operator
        return includeKaAns || excludeKaAns;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

      // If sum is ODD LENGTH
        if (sum % 2 != 0)
            return false;
      
          // If sum Is EVEN LENGTH
        int target = sum / 2;

        return solve(nums, 0, target);
    }
};
