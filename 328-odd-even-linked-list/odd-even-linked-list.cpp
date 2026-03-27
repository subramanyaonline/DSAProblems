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
    ListNode* oddEvenList(ListNode* head1) {
        if(head1==nullptr || head1->next == nullptr|| head1->next->next==nullptr) return head1 ;
        ListNode* node = head1, *head2 = nullptr, *tail2 = nullptr ; 
        while(node!=nullptr && node->next!=nullptr && node->next->next != nullptr){
            ListNode* temp = node->next ;
            node->next = node->next->next ; 
            node=node->next ;

            temp->next = nullptr ;
            if(head2==nullptr){
                head2=temp ;
                tail2=temp ;
                continue ;
            }
            tail2->next = temp ;
            tail2=temp ; 
        }
        ListNode*  temp = node->next ;
        node->next = head2 ;
        tail2->next = temp ;
        return head1 ;
    }
};