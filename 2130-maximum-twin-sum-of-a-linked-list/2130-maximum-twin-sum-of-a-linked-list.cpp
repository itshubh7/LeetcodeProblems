/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode* head){
        if(head==nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* mid = head;
        ListNode* second = head->next;
        while(second){
            mid->next = pre;
            pre= mid;
            mid = second;
            second = second->next;
        }
        mid->next = pre;
        return mid;
    }

    ListNode* getMid(ListNode* head){
        ListNode* pre=nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return pre;
    }


    int pairSum(ListNode* head) {
        if(head==nullptr) return 0;
        ListNode* mid = getMid(head);
        ListNode* second = mid->next;
        mid->next = nullptr;
        ListNode* reverseHead = reverse(head);
        int ans=0;
        while(reverseHead && second){
            ans = max(ans,reverseHead->val+second->val);
            second = second->next;
            reverseHead = reverseHead->next;
        }
        return ans;
    }
};