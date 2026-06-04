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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==nullptr) return head ;
        ListNode* first = head ;
        ListNode* second = head->next ;
        while(second!=nullptr){
            int gcd = 0 ; 
            int a = first->val , b = second->val; 
            while(a!=0 && b!=0){
                int temp = a%b ;
                a = b ;
                b = temp ;
            }
            if(a==0) gcd = b ;
            else gcd = a ;

            ListNode* node = new ListNode(gcd) ; 
            node->next = second ; 
            first->next = node ;
            first = second ;
            second = second->next ;
        }

        return head ;
    }
};