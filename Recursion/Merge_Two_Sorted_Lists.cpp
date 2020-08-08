// Question:- (https://leetcode.com/explore/featured/card/recursion-i/253/conclusion/2382/)
                
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        //If first is null, then return entire second list
        if(!l1)
            return l2;
        
        //If second is null, then return entire first list
        if(!l2)
            return l1;

        ListNode* node = new ListNode();
        
        //add element which is smaller one 
        if(l1->val < l2->val)
        {
            node->val = l1->val;
            node->next = mergeTwoLists(l1->next,l2);
        }
        else
        {
            node->val = l2->val;
            node->next = mergeTwoLists(l1,l2->next);
        }
        return node;
    }
};
