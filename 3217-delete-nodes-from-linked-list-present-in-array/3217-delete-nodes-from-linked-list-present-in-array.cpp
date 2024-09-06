class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        while (curr) {
            if (numSet.count(curr->val)) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        
        return dummy.next;
    }
};