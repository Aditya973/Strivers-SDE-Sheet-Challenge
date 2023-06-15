LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* dummy = nullptr;
    while(head != nullptr){
        LinkedListNode<int> *next = head->next;
        head->next = dummy;
        dummy = head;
        head = next;
    }
    return dummy;
}