/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int n = 0;
    Node* temp = head;
    while(temp != nullptr){
        n++;
        temp = temp->next;
    }
    n = n - K-1;
    if(n < 0){
        head = head->next;
        return head;
    }
    temp = head;
    while(n--){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}
