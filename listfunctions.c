#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "listheader.h"

void Push(struct node **headRef, int data)
{
	struct node *newNode = NULL;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

void AppendNode(struct node **headRef, int data)
{
	struct node *current = *headRef;

	if(current == NULL)
	{
		Push(headRef, data);
	}
	else
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
		Push(&(current->next), data);
	}
}

//Alternative AppendNode function that doesn't use Push
/* void AppendNode(struct node **headRef, int data) */
/* { */
/* 	struct node *holder = NULL;//holds the position of the list head */
/* 	struct node *newNode = NULL; */

/* 	newNode = (struct node *)malloc(sizeof(struct node)); */
/* 	newNode->data = data; */
/* 	newNode->next = NULL; */

/* 	if(*headRef == NULL) */
/* 	{ */
/* 		*headRef = newNode; */
/* 		holder = *headRef; */
/* 	} */

/* 	else */
/* 	{ */
/* 		holder = *headRef; */
/* 		while((*headRef)->next != NULL) */
/* 		{ */
/* 			*headRef = (*headRef)->next; */
/* 		} */
/* 		(*headRef)->next = newNode; */
/* 	} */
/* 	*headRef = holder; */
/* } */

void Delete_List(struct node **headRef)
{
	struct node *current = *headRef;
	struct node *holder = NULL;
	int count = 0;
	/* struct node *head_holder = *headRef; */

	if(current == NULL)
	{
		return;
	}
	else
	{
		holder = current->next;
		free(current);
		printf("Freed head, list element %d.\n", count);
		current = holder;
		count++;

		while (current != NULL)
		{
			holder = current->next;
			free(current);
			printf("Freed list element %d\n", count);
			current = holder;
			count++;
		}
	}
	*headRef = NULL;
}

int PopHead(struct node **headRef)
{
	struct node *currentHead = *headRef;
	int data;

	if(currentHead == NULL)
	{
		printf("The list is empty, returning 0.");
	}
	else
	{
		data = currentHead->data;
		currentHead = currentHead->next;
		free(*headRef);
		*headRef = currentHead;
		return data;
	}
	return 0;//In the case that the list was NULL
}

void Insert_Nth(struct node **headRef, int insertNum)
{
	int rv;
	int count = 0;
	struct node *current = *headRef;

	rv = getLength(*headRef);

	if(insertNum > rv + 1 || insertNum < 1)//The rv + 1 covers the case where the desired node will be inserted at the end of the list. This would be an appendnode case.
	{
		printf("The position you specified is either NULL or out of range (the list starts at 1).\n");
		return;
	}
	if(insertNum == 1)//This is the case of a Push
	{
		int value;
		printf("Entered insertNum == 1 block.\n");
		read_int("Please enter the value to insert: ", &value);
		Push(headRef, value);//if we use current &current here, we will be passing the address of current which is different from the address of &(*headRef) or just headRef.
		return;
	}
	if(insertNum == rv + 1)
	{
		int value;
		printf("Entered insertNum == rv + 1 block.\n");
		read_int("Please enter the value to insert: ", &value);
		AppendNode(headRef, value);
		return;
	}
	while(current != NULL)//we don't want to change the pointer position of the headRef, so that is why we use current as a representative
	{
		if(count == insertNum - 2)//This will stop at the node right before the insert. Of course we assume that the user doesn't know the count really starts at 0. Therefore, we have to subtract 1 for count and subtract 1 again for the node before the insert.
		{
			int value;
			read_int("Please enter the value to insert: ", &value);
			Push(&(current->next), value);
			return;
		}
		current = current->next;
	}
}

/* void Sorted_Insert(struct node **headRef)//Sorts by changing data values. Easy to implement but could cause integrity problems if other variables depend on the values stored at a particular list node address. */
/* { */
/* 	struct node *current = *headRef; */
/* 	int swapint; */

/* 	if(current == NULL) */
/* 	{ */
/* 		printf("The list is empty."); */
/* 	} */
/* 	else */
/* 	{ */
/* 		while(current != NULL) */
/* 		{ */
/* 			if(current->next != NULL) */
/* 			{ */
/* 				if(current->data > (current->next)->data) */
/* 				{ */
/* 					swapint = (current->next)->data; */
/* 					(current->next)->data = current->data; */
/* 					current->data = swapint; */
/* 				} */
/* 			} */
/* 			current = current->next; */
/* 		} */
/* 	} */
/* } */

void Sorted_Insert(struct node **headRef)//Very complicated sort, but this algorithm sorts a list's data values by changing next pointers. This is preferred to changing data values since changing data values could affect other variables in the program that depend on the data values being stored at a particular list node. Changing next pointers ensures the integrity of the program.
{
	struct node *head_holder = *headRef;
	struct node *current = *headRef;
	struct node *holder_previous = NULL;
	struct node *holder_current = NULL;
	struct node *holder_currentnextnext = NULL;
	int count = 1;
	int changes = 0;

	if(current == NULL)
	{
		printf("The list is empty.");
	}
	else
	{
		while(current != NULL)
		{
			if(current->next != NULL)
			{
				if(count == 1)
				{
					if(current->data > (current->next)->data)//deals with head node
					{
						head_holder = current->next;
						holder_previous = current->next;
						holder_currentnextnext = (current->next)->next;
						holder_current = current;
						(current->next)->next = holder_current;
						current->next = holder_currentnextnext;
						count = 0;
						changes = 1;
					}
					else
					{
						holder_previous = current;
						count = 0;
						changes = 0;
					}
				}
				else
				{
					if(current->data > (current->next)->data)
					{
						holder_previous->next = current->next;
						holder_previous = current->next;
						holder_current = current;
						holder_currentnextnext = (current->next)->next;
						(current->next)->next = holder_current;
						current->next = holder_currentnextnext;
						changes = 1;
					}
					else
					{
						holder_previous = current;
						changes = 0;
					}
				}
						
			
				if(changes == 1)
				{
					current = current;
				}
				else
				{
					current = current->next;
				}
			}
			else
			{
				*headRef = head_holder;
				return;
			}
		}
	}
}

void Insert_Sort(struct node **headRef)
{
	int count = 0;
	int i;

	count = getLength(*headRef);//find out how many times we need to loop through
	printf("The length of Head is %d.\n", count);
	for(i = 0; i < count; i++)
	{
		Sorted_Insert(headRef);
		/* PrintListData(*headRef); */
		/* Sorted_Insert(&(*headRef)); */ 
	}
}

void Append_Node(struct node **Ahead, struct node **Bhead)//we could have passed in *Bhead to append the node, but then we would have had to set it to NULL outside of this function (i.e. back in the caller).
{
	struct node *current = *Ahead;

	if(current == NULL)
	{
		*Ahead = *Bhead;
	}
	else
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = *Bhead;
	}
	*Bhead = NULL;
}

void Front_Back_Split(struct node **Ahead, struct node **Bhead)
{
	struct node *current = *Ahead;
	int len = 0;
	int count = 1;//used to traverse the list. Set to 1 to accomodate len. Or else evaluate (len - 1)

	if(current == NULL || current->next == NULL)
	{
		printf("The list is empty");
		return;
	}
	len = getLength(current);
	/* printf("The length of Ahead is %d.\n", len); */
	if(len % 2 == 0)
	{
		while(current->next != NULL)
		{
			if(count == (len / 2))
			{
				*Bhead = current->next;
				current->next = NULL;
				return;
			}
			count++;
			current = current->next;
		}
	}
	else
	{
		while(current->next != NULL)
		{
			if(count == ((len / 2) + 1))
			{
				*Bhead = current->next;
				current->next = NULL;
				return;
			}
			count++;
			current = current->next;
		}
	}
}

/* struct node *Front_BackSplit(struct node **Ahead) *///This is an alternative solution that returns a pointer
/* { */
/* 	struct node *current = *Ahead; */
/* 	struct node *split_rear = NULL; */
/* 	int len = 0; */
/* 	int count = 1;//used to traverse the list. Set to 1 to accomodate len. Or else evaluate (len - 1) */

/* 	if(current == NULL) */
/* 	{ */
/* 		printf("The list is empty"); */
/* 		return split_rear; */
/* 	} */
/* 	len = getLength(current); */
/* 	/1* printf("The length of Ahead is %d.\n", len); *1/ */
/* 	if(len % 2 == 0) */
/* 	{ */
/* 		while(current->next != NULL) */
/* 		{ */
/* 			if(count == (len / 2)) */
/* 			{ */
/* 				split_rear = current->next; */
/* 				current->next = NULL; */
/* 				return split_rear; */
/* 			} */
/* 			count++; */
/* 			current = current->next; */
/* 		} */
/* 	} */
/* 	else */
/* 	{ */
/* 		while(current->next != NULL) */
/* 		{ */
/* 			if(count == ((len / 2) + 1)) */
/* 			{ */
/* 				split_rear= current->next; */
/* 				current->next = NULL; */
/* 				return split_rear; */
/* 			} */
/* 			count++; */
/* 			current = current->next; */
/* 		} */
/* 	} */
/* 	return split_rear; */
/* } */

void Remove_Duplicates(struct node **headRef)
{
	struct node *current = *headRef;
	struct node *holder = NULL;

	if(current == NULL)
	{
		printf("The list is empty");
	}
	else
	{
		while(current->next != NULL)
		{
			while(current->data == (current->next)->data)
			{
				printf("current->data = %d, and (current->next)->data = %d.\n", current->data,(current->next)->data);
				holder = (current->next)->next;
				free(current->next);
				current->next = NULL;
				current->next = holder;
				if(current->next == NULL)//if current->next is NULL and we don't break out or return, then we will get a segmentation fault at the top of the loop when trying to access (current->next)->data since this doesn't exist since current-next is NULL.
				{
					return;
				}
			}
			current = current->next;
		}
	}
}

void Move_Node(struct node **Destination, struct node **Source)
{
	struct node *holder = *Destination;
	struct node *source_holder = NULL; 

	if(*Source == NULL)
	{
		printf("The source list is empty. Cannot move anything to destination list.");
		return;
	}

	source_holder = (*Source)->next;//we can't specify this above in the case taht *Source is NULL. In that case, this would give a segmentation fault trying to access the next variable that doesn't exist.

	if(*Destination == NULL)
	{
		*Destination = *Source;
		(*Destination)->next = NULL;
		*Source = source_holder;
	}
	else
	{
		*Destination = *Source;
		(*Destination)->next = holder;
		*Source = source_holder;
	}
}

void Move_Append_Node(struct node **Destination, struct node **Source)
{
	struct node *holder = *Destination;
	struct node *source_holder = NULL; 

	if(*Source == NULL)
	{
		printf("The source list is empty. Cannot move anything to destination list.");
		return;
	}

	source_holder = (*Source)->next;//we can't specify this above in the case taht *Source is NULL. In that case, this would give a segmentation fault trying to access the next variable that doesn't exist.

	if(*Destination == NULL)
	{
		*Destination = *Source;
		(*Destination)->next = NULL;
		*Source = source_holder;
	}
	else
	{
		while(*Destination != NULL)
		{
			if((*Destination)->next == NULL)
			{
				(*Destination)->next = *Source;
				((*Destination)->next)->next = NULL;
				*Source = source_holder;
				*Destination = holder;
				return;
			}
			*Destination = (*Destination)->next;
		}
	}
}

void Alternating_Split(struct node **Destination, struct node **Source)
{
	/* int count = 1; */
	struct node *holder= *Source;
	struct node *holder2= NULL;

	if(*Source == NULL)
	{
		printf("The source list is empty. Cannot move anything to destination list.");
		return;
	}
	
	else
	{
		while(*Source != NULL)
		{
			if(*Destination == NULL)
			{
				*Destination = (*Source)->next;
				if((*Source)->next != NULL)
				{
					(*Source)->next = ((*Source)->next)->next;
					(*Destination)->next = NULL;
				}
			}
			else
			{
				holder2 = *Destination;
				if((*Source)->next != NULL)
				{
					*Destination = (*Source)->next;
					(*Source)->next = ((*Source)->next)->next;
					(*Destination)->next = holder2;
				}
			}	
			if((*Source)->next != NULL)
			{
				*Source = (*Source)->next;
			}
			else
			{
				*Source = holder;
				return;
			}
		}
	}
}

void Shuffle_Merge(struct node **Ahead, struct node **Bhead, struct node **Chead)
{
	while(*Ahead != NULL || *Bhead != NULL)
	{
		if(*Ahead != NULL)
		{
			Move_Append_Node(Chead, Ahead);
		}

		if(*Bhead != NULL)
		{
			Move_Append_Node(Chead, Bhead);
		}
	}
}

void Sorted_Merge(struct node **Ahead, struct node **Bhead, struct node **Chead)
{
	Shuffle_Merge(Ahead, Bhead, Chead);
	/* PrintListData(Chead); */
	Insert_Sort(Chead);
}

void Merge_Sort(struct node **Ahead)
{
	struct node *A = *Ahead;
	struct node *B = NULL;
	struct node *C = NULL;

	if(*Ahead == NULL || (*Ahead)->next == NULL)
	{
		return;
	}
	Alternating_Split(&B, &A);
	/* Front_Back_Split(&A, &B); */

	Merge_Sort(&A);
	Merge_Sort(&B);

	Sorted_Merge(&A, &B, &C);

	*Ahead = C;
}





void Sorted_Intersection(struct node **Ahead, struct node **Bhead, struct node **Chead)
{
	struct node *Aholder = *Ahead;
	struct node *Bholder = *Bhead;

	if(*Ahead == NULL || *Bhead == NULL)
	{
		return;
	}
	else
	{
		while(*Ahead != NULL)
		{
			while(*Bhead != NULL)
			{
				if((*Ahead)->data == (*Bhead)->data)
				{
					AppendNode(Chead, (*Ahead)->data);
				}
				*Bhead = (*Bhead)->next;
			}
			*Bhead = Bholder;
			*Ahead = (*Ahead)->next;
		}
		Remove_Duplicates(Chead);
		*Ahead = Aholder;
	}
}

void Reverse_List(struct node **headRef)
{
	struct node *current = *headRef;
	struct node *holder = NULL;
	struct node *holder2 = NULL;
	int count = 1;

	if(current == NULL || current->next == NULL)
	{
		printf("The list is empty or it only contains one element.\n");
		return;
	}
	else
	{
		while(current != NULL)
		{
			if(count == 1)//This deals with the head node case
			{
				holder2 = current->next;
				current->next = NULL;
				holder = current;
				count = 0;
			}
			else
			{
				holder2 = current->next;
				current->next = holder;
				holder = current;
			}
			current = holder2;
		}
		*headRef = holder;
	}
}
				
void Recursion_Reverse(struct node **headRef)
{
	struct node *first = NULL;
	struct node *rest = NULL;

	if(*headRef == NULL || (*headRef)->next == NULL)
	{
		return;
	}

	first = *headRef;
	rest = first->next;

	Recursion_Reverse(&rest);

	(first->next)->next = first;
	first->next = NULL;

	*headRef = rest;

}
				
			
			

				

/* void Sorted_Intersection(struct node **Ahead, struct node **Bhead, struct node **Chead)//Not using Remove_Duplicates */
/* { */
/* 	struct node *Aholder = *Ahead; */
/* 	struct node *Bholder = *Bhead; */

/* 	if(*Ahead == NULL || *Bhead == NULL) */
/* 	{ */
/* 		return; */
/* 	} */
/* 	else */
/* 	{ */
/* 		while(*Ahead != NULL) */
/* 		{ */
/* 			while(*Bhead != NULL) */
/* 			{ */
/* 				if((*Ahead)->data == (*Bhead)->data) */
/* 				{ */
/* 					AppendNode(Chead, (*Ahead)->data); */
/* 					break; */
/* 				} */
/* 				*Bhead = (*Bhead)->next; */
/* 			} */
/* 			*Bhead = Bholder; */
/* 			if((*Ahead)->next == NULL) */
/* 			{ */
/* 				break; */
/* 			} */
/* 			while((*Ahead)->data == ((*Ahead)->next)->data) */
/* 			{ */
/* 				*Ahead = (*Ahead)->next; */
/* 				if((*Ahead)->next == NULL) */
/* 				{ */
/* 					break; */
/* 				} */
/* 			} */
/* 			*Ahead = (*Ahead)->next; */
/* 		} */
/* 		*Ahead = Aholder; */
/* 	} */
/* } */
	

int getLength(struct node *headRef)
{
	int count = 0;
	while(headRef != NULL)
	{
		headRef = headRef->next;
		count++;
	}
	return count;
}

void ElementSearch(struct node *head, int content, int *count)
{
	struct node *current = head;

	if(current == NULL)
	{
		return;
	}
	while(current != NULL)
	{
		if(current->data == content)
		{
			(*count)++;
		}
		current = current->next;
	}
}

short int GetValue(struct node *head, int content, int *value)
{
	struct node *current = head;
	int count = 0;

	if(current == NULL)
	{
		return 0;
	}
	else
	{
		while(current != NULL)
		{
			if(count == (content - 1))
			{
				*value = current->data;
				return 1;
			}
			current = current->next;
			count++;
		}
		return 0;//This includes the case where the desired element number is out of range (i.e. not in the list)
	}
}

void PrintListData(struct node *head)
{
	int count = 1;
	if(head == NULL)
	{
		printf("The list is empty.");
	}
	else
	{
		while(head != NULL)
		{
			printf("List element %d = %d\n", count, head->data);	
			count++;
			head = head->next;
		}
	}
	printf("\n\n");
}



void freeElements(struct node **head)
{
	struct node *current = *head;
	struct node *holder = *head;

	if(current == NULL)
	{
		return;
	}
	while(current != NULL)
	{
		holder = current;
		current = current->next;
		free(holder);
	}
	*head = NULL;
}

