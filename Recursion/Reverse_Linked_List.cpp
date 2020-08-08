//Question:- (https://leetcode.com/explore/featured/card/recursion-i/251/scenario-i-recurrence-relation/2378/)
/*
    Input: 1->2->3->4->5->NULL
    Output: 5->4->3->2->1->NULL
*/

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(!head || !head->next)
            return head;
            
        ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return temp;
    }
};
