//  LeetCode Problem No. 21: Merge Two Sorted Lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(!list1&&!list2){return NULL;}
    if(!list1){return list2;}
    if(!list2){return list1;}
    struct ListNode* dummy=malloc(sizeof(struct ListNode));
    dummy->val=0,dummy->next=NULL;
    struct ListNode* last=dummy;
    while(list1&&list2){
        if(list1->val<list2->val){last->next=list1; list1=list1->next;}
        else{last->next=list2; list2=list2->next;}
        last=last->next;
    }
    if(!list1){last->next=list2;}
    else{last->next=list1;}
    return dummy->next;
}