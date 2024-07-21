class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // STRIVERS OPTIMAL SOLUTION
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i=0;i<n;i++){
            fast = fast -> next;
        }

        if(fast == NULL){
            ListNode* newHead =  head -> next;
            delete(head);
            return newHead;
        }

        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }

        ListNode* deleteNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete(deleteNode);

        return head;
    }
};