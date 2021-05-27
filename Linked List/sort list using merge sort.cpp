ListNode* sortedMerge(ListNode* a, ListNode* b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    ListNode *result;
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void frontBackSplit(ListNode *head, ListNode** frontRef, ListNode** backRef)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    frontRef = head;
    backRef = slow->next;
    slow->next = NULL;
}

void mergeSort(ListNode** headRef)
{
    ListNode* head = *headRef;
    //base case
    if (head == NULL || head->next == NULL)
        return;

    ListNode* a, *b;
    //split the list from the middle into two parts
    frontBackSplit(head, &a, &b);

    //recusive call
    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

ListNode* sortList(ListNode* head)
{
    mergeSort(&head);
    return head;
}