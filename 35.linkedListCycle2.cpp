#include<bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* fast = head;
    Node* slow = head;
    Node* start = head;

    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            while(start != slow){
                slow = slow->next;
                start = start->next;
            }
            return start;
        }
    }
    return nullptr;
    
}