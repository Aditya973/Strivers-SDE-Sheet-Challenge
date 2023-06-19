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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead == NULL || secondHead == NULL){
        return NULL;
    }
    
    Node* l1 = firstHead;
    Node* l2 = secondHead;
    while(l1 != l2){
        if(!l1){
            l1 = secondHead;
        }
        else{
            l1 = l1->next;
        }
        if(!l2){
            l2 = firstHead;
        }
        else{
            l2 = l2 -> next;
        }
    }
    return l1;
}