//Question:- (https://leetcode.com/explore/featured/card/recursion-i/250/principle-of-recursion/1681/)

class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        //If there is 0 or 1 element, swapping will not occur
        if(!head || !head->next)
            return head;
            
        ListNode* nextNode = head->next;
        //First swap rest of the pairs
        head->next = swapPairs(nextNode->next);
        //swap current pair
        nextNode->next = head;
        
        //head is swapped by nexttNode
        return nextNode;
    }
};

// second approach...
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        swap(head->val , head->next->val);
        head->next->next = swapPairs(head->next->next);
        return head;
    }
};
