bool isPalindrome(struct ListNode* head) 
{
    if(!head || !head->next) return true;

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    while(fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast == NULL) {

        struct ListNode* curr = slow;
        struct ListNode* next = NULL;

        while(curr != NULL) 
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        curr = head;

        struct ListNode* secondHalf = prev;

        while(secondHalf)
            {
                if(curr->val != secondHalf->val) 
                {
                    return false;
                }

                curr = curr->next;
                secondHalf = secondHalf->next;
            }
        return true;
    }

    struct ListNode* curr = slow->next;
    struct ListNode* next = NULL;

    while(curr != NULL) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    curr = head;

    struct ListNode* secondHalf = prev;
    while(secondHalf) 
    {
        if(curr->val != secondHalf->val) 
        {
            return false;
        }
        curr = curr->next;
        secondHalf = secondHalf->next;
    }
    return true;
}