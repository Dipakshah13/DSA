
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        vector<int> neg;
        vector<int> pos;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] < 0)
            {
                neg.push_back(nums[i]);
            }
            else
            {
                pos.push_back(nums[i]);
            }
        }

        int p = neg.size();
        int q = pos.size();

        // Square negative elements
        for(int i = 0; i < p; i++)
        {
            neg[i] = neg[i] * neg[i];
        }

        // Reverse negative array
        reverse(neg.begin(), neg.end());

        // Square positive elements
        for(int i = 0; i < q; i++)
        {
            pos[i] = pos[i] * pos[i];
        }

        int i = 0;
        int j = 0;
        int id = 0;

        vector<int> res(p + q);

        // Merge both sorted arrays
        while(i < p && j < q)
        {
            if(neg[i] < pos[j])
            {
                res[id] = neg[i];
                id++;
                i++;
            }
            else
            {
                res[id] = pos[j];
                id++;
                j++;
            }
        }

        // Remaining negative elements
        while(i < p)
        {
            res[id] = neg[i];
            id++;
            i++;
        }

        // Remaining positive elements
        while(j < q)
        {
            res[id] = pos[j];
            id++;
            j++;
        }

        return res;
    }
};