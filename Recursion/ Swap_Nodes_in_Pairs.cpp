class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
            
        ListNode* nextNode = head->next;
        head->next = swapPairs(nextNode->next);
        nextNode->next = head;
        
        return nextNode;
    }
};