class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        // 🎯 START: Sorting makes duplicate checking easier
        // ❌ DON'T skip sort - O(n log n) helps both deduplication AND 2-pointer
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        // 🔁 Main loop: Fix first element, find two others using pointers
        // ❌ DON'T iterate past n-3 - need at least 2 elements after i
        for (int i = 0; i < n - 2; i++) {
            
            // ⚠️ Common mistake: Forgetting to skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // Skip same value to avoid duplicate triplets
            }

            // Two-pointer setup: search range starts after i
            int left = i + 1;      // ❌ DON'T set left <= i or left = 0
            int right = n - 1;     // ❌ DON'T set right >= n

            while (left < right) {  // Must use < not <=
                int sum = nums[i] + nums[left] + nums[right];  // Calculate triplet sum

                if (sum == 0) {  // ✅ Found valid triplet!
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    left++;
                    right--;

                    // 🔄 Skip duplicates AFTER moving - BEFORE next iteration!
                    // ❌ DON'T skip before comparing (would miss valid matches)
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // ❌ Common bug: nums[right] == nums[right-1] WRONG direction
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < 0) {
                    left++;   // Need larger sum → move forward
                } else {
                    right--;  // Need smaller sum → move backward
                }
            }
        }
        return result;
    }
};