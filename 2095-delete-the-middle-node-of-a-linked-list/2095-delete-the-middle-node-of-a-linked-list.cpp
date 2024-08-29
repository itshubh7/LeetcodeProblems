class Solution {
private:
    int getlength(ListNode* &head){
        int len = 0;
        ListNode* temp = head ;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        int size = getlength(head);  

        int n = size/2 ; 

        if(n == 0){  
            
            ListNode *temp = head;

            head = head->next;
            temp->next = NULL;

            delete temp;
        }
        else{
            ListNode *current  = head ;
            ListNode *previous = NULL ;

            int cnt  = 0;

            while(cnt < n ){
                
                previous = current;
                current = current -> next ;
                cnt++;
            }

            previous-> next = current -> next;

            current -> next = NULL;
            delete current;


        }
        return head;
    }
};