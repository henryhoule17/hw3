#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{

	Node* temp = head;
	head = NULL;
	if(temp == NULL)
	{
		smaller = larger = NULL;
		return;
	}

	if(temp->val > pivot)
	{
			larger = temp;
			llpivot(temp->next, smaller, larger->next, pivot);
			//head = NULL;
			//larger->next = nlg;
			//smaller = nsm;
	}
	else
	{
		smaller = temp;
		llpivot(temp->next, smaller->next, larger, pivot);
		//head = NULL;
		//smaller->next = nsm;
		//larger = nlg;
	}
}

	/*if(head->next == NULL)
	{
		if(head->val > pivot)
		{
			larger = head;
			head = NULL;
			smaller = NULL;
			return;
		}
		else
		{
			smaller = head;
			head = NULL;
			larger = NULL;
			return;
		}
	}*/
	//Node* nsm;
	//Node* nlg;

