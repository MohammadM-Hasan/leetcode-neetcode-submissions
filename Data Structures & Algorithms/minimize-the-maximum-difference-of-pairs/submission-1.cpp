class Solution {
public:

    bool canMakePairs(vector<int> & nums , int p , int maxDifference)
    {
        int pairCount = 0;

        for(int i = 0 ; i < nums.size() - 1 ;)
        {
            if(nums[i + 1] - nums[i] <= maxDifference)
            {
                pairCount++;
                i += 2;
            }
            else
            {
                i++;
            }
        }

        return pairCount >= p;
    }

    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin() , nums.end());

        int left = 0;
        int right = nums.back() - nums.front();

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(canMakePairs(nums , p , mid))
            {
                right = mid;
            }
            else 
            {
                left = mid + 1;
            }
        }

        return left;
    }
};