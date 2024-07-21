class Solution {
public:
    void reorderList(ListNode* head) {
        //Middle of the linked list
        ListNode *slow = head,*fast = head;
        while(fast != NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Reversing 2nd part
        ListNode *p = NULL, *q = slow , *r = slow->next;
        while( q != NULL ){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        //Forming Links
        ListNode *head1 = head, *head2 = p;
        while(head2->next != NULL){
            ListNode *temp = head1->next;
            head1->next = head2;
            head1 = temp;

            temp = head2->next;
            head2->next = head1;
            head2 = temp;
        }
    }
};