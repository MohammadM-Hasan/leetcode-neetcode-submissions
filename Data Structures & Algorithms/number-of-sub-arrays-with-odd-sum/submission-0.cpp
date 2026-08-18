class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int even = 1;
        int odd = 0;

        const int MOD = 1000000007;

        long long answer = 0;
        int prefixSum = 0;

        for (int num : arr)
        {
            prefixSum += num;

            if (prefixSum % 2 == 0)
            {
                answer += odd;
                even++;
            }
            else
            {
                answer += even;
                odd++;
            }
        }

        return answer % MOD;
    }
};