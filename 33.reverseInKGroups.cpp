#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(!head || !head->next){
		return head;
	}
	int len = 0;
	Node* temp = head;
	Node* dummy = new Node(0);
	dummy->next = head;
	Node* prev = dummy;
	Node *curr = dummy, *nex = dummy;
	while(temp){
		len++;
		temp = temp -> next;
	}
	int i = 0;
	while(len >= 1 && i < n){
		curr = prev->next;
		nex = curr->next;
		if(b[i] == 1){
			prev = curr;
			i++;
			len--;
			continue;
		}
		else if(b[i] == 0){
			i++;
			continue;
		}
		for(int j = 1;j<min(len,b[i]);j++){
			curr->next = nex->next;
			nex->next = prev->next;
			prev->next = nex;
			nex = curr->next;
		}
		prev = curr;
		len -= b[i];
		i++;
	}
	return dummy->next;
}