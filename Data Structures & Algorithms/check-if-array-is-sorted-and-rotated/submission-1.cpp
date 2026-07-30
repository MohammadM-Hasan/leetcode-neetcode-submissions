class Solution {
public:
    bool check(vector<int>& nums) {
        unsigned short numberOfDecreases = 0;

        for(int i = 0 ; i < nums.size() - 1 ; i++)
        {
            if(nums[i] > nums[i + 1])
                numberOfDecreases++;
            
            if(numberOfDecreases > 1)
                return false;
        }

        if(nums[nums.size() - 1] > nums[0])
        {
            numberOfDecreases++;
            if(numberOfDecreases > 1)
                return false;
        }

        return true;
    }
};