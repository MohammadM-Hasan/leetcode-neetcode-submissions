class Solution {
public:
    int calculateSummation(const vector<int>& weights)
    {
        int summation = 0;

        for(int weight : weights)
        {
            summation += weight;
        }

        return summation;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin() , weights.end());
        int right = calculateSummation(weights);


        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            int daysNeeded = 1;
            int currentWeight = 0;

            // go through packages 
            for(int weight : weights)
            {   
                if(currentWeight + weight <= mid)
                {
                    currentWeight += weight;
                }
                else
                {
                    daysNeeded++;
                    currentWeight = weight;
                }
            }
            if(daysNeeded > days)
            {
                // here it means I take more days that means that the capacity (mid) is small
                // so go right 
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};