class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *fastPtr = head->next->next, *slowPtr = head;
        while (fastPtr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        ListNode *prevPtr = nullptr, *curPtr = slowPtr->next, *nxtPtr = slowPtr->next->next;
        while (nxtPtr) {
            curPtr->next = prevPtr;
            prevPtr =  curPtr;
            curPtr = nxtPtr;
            nxtPtr = nxtPtr->next;
        }
        curPtr->next = prevPtr;
        slowPtr->next = curPtr;
        
        int maxSum = 0;
        while (slowPtr->next) {
            maxSum = max(maxSum, head->val + slowPtr->next->val);
            head = head->next;
            slowPtr = slowPtr->next;
        }

        return maxSum;
    }
};