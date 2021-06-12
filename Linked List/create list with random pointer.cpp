Node* copyRandomList(Node* head)
{
    Node* iter = head;
    Node* front = head;

    //first step:make copy of each node
    while (iter != NULL)
    {
        front = front->next;
        Node* copy = new Node(iter->val);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }

    //second step:assign random ponter for the copy nodes
    iter = head;
    while (iter != NULL)
    {
        if (iter->random != NULL)
            iter->next->random = iter->random->next;
        iter = iter->next->next;
    }

    //third round:resotre the original list and extrect the copy list;
    iter = head;
    Node* newHead = new Node(0);
    Node* copy = newHead;
    while (iter != NULL)
    {
        front = iter->next->next;
        copy->next = iter->next;
        iter->next = front;
        copy = copy->next;
        iter = front;
    }
    return newHead->next;
}