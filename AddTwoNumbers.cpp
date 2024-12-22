
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= new ListNode(0);
        
        ListNode *p=l1, *q=l2, *cur=head;
        int carry=0;
        while(p!=nullptr||q!=nullptr){
            int m1=(p!=nullptr)?p->val:0;
            int m2=(q!=nullptr)?q->val:0;
            
            int sum=m1+m2+carry;
            carry=sum/10;
            
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            
            if(p!=nullptr)
                p=p->next;
            if(q!=nullptr)
                q=q->next;
        }
        if(carry>0){
            cur->next=new ListNode(carry);
        }
        return head->next;
        
    }
};
