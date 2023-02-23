#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	if(head == NULL)
	{
		smaller = larger = NULL;
		return;
	}

	
	if(head->next == NULL)
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
	}
	Node* nsm;
	Node* nlg;
	if(head->val > pivot)
	{
			larger = head;
			head = NULL;
			llpivot(larger->next, nsm, nlg, pivot);
			larger->next = nlg;
			smaller = nsm;
	}
	else
	{
		smaller = head;
		head = NULL;
		llpivot(smaller->next, nsm, nlg, pivot);
		smaller->next = nsm;
		larger = nlg;
	}
}


