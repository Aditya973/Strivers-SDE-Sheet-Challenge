/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    if(!num2){
        return num1;
    }
    if(!num1){
        return num2;
    }
    Node *head = nullptr;
    Node *temp = head;
    int carry = 0;
    while(num1 != nullptr && num2!= nullptr){
        Node* node = new Node;
        node->data = (num1->data + num2->data + carry)%10;
        carry = (num1->data + num2 ->data + carry)/10;
        if(!head){
            head = node;
            temp = head;
        }
        else{
            temp->next = node;
            temp = node;
        }
        num1 = num1->next;
        num2 = num2->next;
    }
    while(num1 != nullptr){
        Node* node = new Node;
        node->data = (num1->data+carry)%10;
        carry = (num1->data+carry)/10;
        temp -> next = node;
        temp  = node;
        num1 = num1->next;
    }
    while(num2 != nullptr){
        Node* node = new Node;
        node->data = (num2->data+carry)%10;
        carry = (num2->data+carry)/10;
        temp -> next = node;
        temp  = node;
        num2 = num2->next;
    }
    if(carry > 0){
        Node *node = new Node;
        node->data = carry;
        temp->next = node;
    }
    return head;
}
