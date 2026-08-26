class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* ptr = head;
        vector<int> array;

        while (ptr != nullptr) {
            array.push_back(ptr->val);
            ptr = ptr->next;
        }

        int maxSum = 0;

        for (int i = 0; i < array.size(); i++) {
            int result = array[i] + array[array.size() - 1 - i];

            if (result > maxSum) {
                maxSum = result;
            }
        }

        return maxSum;
    }
};