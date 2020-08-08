class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(!l1)
            return l2;

        if(!l2)
            return l1;

        ListNode* node = new ListNode();

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