class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> remainderIndex;
        remainderIndex[0] = -1;
        
        int sum = 0;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum += nums[i];
            int remainder = sum % k;
           
           if(remainderIndex.find(remainder) != remainderIndex.end())
           {
                // We saw this remainder before
                int previousIndex = remainderIndex[remainder];

                if(i - previousIndex >= 2)
                    return true;
           }
           
           else
           {
                // First time seeing this remainder
                remainderIndex[remainder] = i;
           } 
        }

        return false;
    }
};