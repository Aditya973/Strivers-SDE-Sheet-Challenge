#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* reverseList(LinkedListNode<int> *head){
    LinkedListNode<int> *pre = NULL;
    LinkedListNode<int> *nxt = NULL;
    while(head != NULL){
        nxt = head->next;
        head->next = pre;
        pre = head;
        head = nxt;
    }
    return pre;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(!head)
        return true;
    if(!head->next){
        return true;
    }
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
    
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    slow->next = reverseList(slow->next);
    slow = slow->next;
    while(slow){
        if(slow->data != head->data){
            return false;
        }
        slow = slow->next;
        head = head->next;
    }
    return true;
}