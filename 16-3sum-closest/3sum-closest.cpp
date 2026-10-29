class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

       int closet_sum=nums[0] + nums[1] + nums[2];
       int min_diff= INT_MAX;

        sort(nums.begin(),nums.end());

        if(n < 3)
        {
            return 0; 
        }

        for(int i =0; i < n-2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            int left=i+1;
            int right= n-1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum-target);
                if(diff < min_diff)
                {
                    min_diff = diff;
                    closet_sum= sum;
                }

                if(sum == target)
                {
                    return target;
                }
                else if(sum < target)
                {
                    left++;
                }

                else {
                    right--;
                }
            }
        }
        return closet_sum;
        
    }
};