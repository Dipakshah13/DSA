<h2>3sum Notes</h2><hr>[ Time taken: 36m 50s ]

<h2>Brute Force Solution (for comparison</h2>

// ❌ SLOW: O(n³) - Just for understanding the problem conceptually
vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    
    // Triple nested loop - check every combination
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    result.push_back(triplet);
                }
            }
        }
    }
    
     //❌ Still need to remove duplicates manually
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    return result;
}

⚡ Complexity Comparison
Approach	Time	Space	Note
Your Final	O(n²)	O(1)*	Efficient ✅
Brute Force	O(n³)	O(k)	Too slow ❌
Without Sort	O(n²) extra space	Need hash set	Complex dedup
