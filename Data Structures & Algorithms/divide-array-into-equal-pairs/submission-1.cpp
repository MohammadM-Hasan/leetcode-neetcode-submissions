class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int arr[501] = {0};

        for(int num : nums)
        {
            arr[num]++;
        }

        for(int num : arr)
        {
            if(num %2 != 0)
            {
                return false;
            }
        }

        return true;
    }
};