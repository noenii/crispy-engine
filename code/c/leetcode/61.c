//  LeetCode Problem No. 61: Rotate List
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head||head->next==NULL||k==0){return head;}
    struct ListNode* cur=head;
    int n=1;
    while(cur->next){cur=cur->next; n++;}
    k=k%n;
    if(k==0){return head;}
    cur->next=head;
    for(int i=0;i<n-k-1;i++){
        head=head->next;
    }
    struct ListNode* new=head->next;
    head->next=NULL;
    return new;
}