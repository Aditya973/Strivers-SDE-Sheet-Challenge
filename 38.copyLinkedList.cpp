#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(!head){
        return nullptr;
    }
    
    map<LinkedListNode<int>*,LinkedListNode<int>*> mp;
    LinkedListNode<int>* temp = head;
    while(temp){
        LinkedListNode<int>* node = new LinkedListNode<int>(temp->data);
        mp[temp] = node;
        temp = temp->next;
    }
    temp = head;
    while(temp){
        LinkedListNode<int>* node1 = mp[temp];
        node1->next = mp[temp->next];
        node1->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}
