struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* cur=&dummy;
    int carry=0;
    while(l1||l2||carry) {
        int val1=l1?l1->val:0;
        int val2=l2?l2->val:0;
        int sum=val1+val2+carry;
        carry=sum/10;
        struct ListNode* node=malloc(sizeof(struct ListNode));
        node->val=sum%10;
        node->next=NULL;
        cur->next=node;
        cur=cur->next;
        if(l1){l1=l1->next;}
        if(l2){l2=l2->next;}
    }
    return dummy.next;
}