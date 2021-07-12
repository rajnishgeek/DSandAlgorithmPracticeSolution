class Solution {
   Node* sortTwoLL(struct Node* a, struct Node* b)
   {
      if (a == NULL)
         return b;
      if (b == NULL)
         return a;
      struct Node* dummy = new Node(0);
      struct Node* last = dummy;
      while (a != NULL && b != NULL)
      {
         if (a->data <= b->data)
         {
            last->next = a;
            last = a;
            a = a->next;
         }
         else
         {
            last->next = b;
            last = b;
            b = b->next;
         }
      }
      if (a != NULL)
         last->next = a;
      if (b != NULL)
         last->next = b;
      return dummy->next;

   }
public:
   //Function to merge K sorted linked list.
   Node * mergeKLists(Node *arr[], int K)
   {
      // Your code here
      K = K - 1;
      while (K > 0)
      {
         int i = 0, j = K;
         while (i < j)
         {
            arr[i] = sortTwoLL(arr[i], arr[j]);
            i++;
            j--;
            if (i >= j)
               K = j;
         }
      }
      return arr[0];
   }
};