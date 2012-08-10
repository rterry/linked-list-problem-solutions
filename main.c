#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "listheader.h"

static void Count()//PROBLEM 1
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}

	boolean = 1; //reset boolean to default to prepare for next while loop

	while(boolean)
	{
		int count = 0;
		if(yesno("Do you want to search for the total number of entries for a value (Y/N)?"))
		{
			read_int("Please enter your value to search for: ", &content);
			ElementSearch(head, content, &count);
			printf("The total number of entries for %d is %d.\n", content, count);
		}
		else
		{
			boolean = 0;
		}
	}
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 1

static void GetNth()//START PROBLEM 2
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			AppendNode(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}

	boolean = 1; //reset boolean to default to prepare for next while loop

	while(boolean)
	{
		short int boolean2;
		int value = 0;
		if(yesno("Do you want to search for the value of an element (Y/N)?"))
		{
			read_int("Please enter your value to search for: ", &content);
			boolean2 = GetValue(head, content, &value);
			if(boolean2 == 0)
			{
				printf("The list is either empty or the value you entered is out of range.\n");
			}
			else
			{
				printf("The value of element %d is %d.\n", content, value);
			}
		}
		else
		{
			boolean = 0;
		}
	}
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 2

static void DeleteList()//START PROBLEM 3
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			AppendNode(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}

	//Now delete the list
	if(yesno("Would you like to delete the list (Y/N)?"))
	{
		Delete_List(&head);
	}
	if(head == NULL)
	{
		printf("The head node has been set to NULL.\n");
	}
}//END PROBLEM 3

static void Pop()//PROBLEM 4
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}

	boolean = 1; //reset boolean to default to prepare for next while loop

	while(boolean)
	{
		int rv;
		if(yesno("Would you like to pop the head node and return its value (Y/N)?"))
		{
			rv = PopHead(&head);
			printf("The return value for the popped node is %d.\n", rv);
		}
		else
		{
			boolean = 0;
		}
	}
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 4

static void InsertNth()//PROBLEM 5
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}

	boolean = 1; //reset boolean to default to prepare for next while loop

	while(boolean)
	{
		short int boolean2;
		short int boolean3 = 1;
		int value = 0;
		if(yesno("Would you like to insert a new node at an arbitrary position (Y/N)?"))
		{
			read_int("Enter the position for which you want to insert the node: ", &content);
			Insert_Nth(&head, content);
			printf("Now let's check the contents of the list.\n");
			while(boolean3)
			{
				read_int("Please enter your value to search for: ", &content);
				boolean2 = GetValue(head, content, &value);
				if(boolean2 == 0)
				{
					printf("The list is either empty or the value you entered is out of range.\n");
				}
				else
				{
					printf("The value of element %d is %d.\n", content, value);
				}
				if(!yesno("Do you want to search for another value of an element (Y/N)?"))
				{
					boolean3 = 0;
				}
			}
		}
		else
		{
			boolean = 0;
		}
	}
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 5

static void SortedInsert()//PROBLEM 6
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&head, content);
		}
		else
		{
			boolean = 0;
		}
		PrintListData(head);
		Sorted_Insert(&head);
		PrintListData(head);
	}
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 6

static void InsertSorted()//PROBLEM 7
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&head, content);
		}
		else
		{
			boolean = 0;
		}
		PrintListData(head);
	}
	Insert_Sort(&head);
	PrintListData(head);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 7

static void Append_Node_Problem()//PROBLEM 8, THE APPEND NODE 
{
	int boolean = 1;
	int content;
	struct node *Ahead = NULL;
	struct node *Bhead = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value for Ahead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Ahead, content);
		}
		else
		{
			boolean = 0;
		}
	}

	boolean = 1;
	while(boolean)
	{
		if(yesno("Would you like to enter a value for Bhead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Bhead, content);
		}
		else
		{
			boolean = 0;
		}
	}
	PrintListData(Ahead);
	PrintListData(Bhead);
	Append_Node(&Ahead, &Bhead);
	PrintListData(Ahead);
	PrintListData(Bhead);
	freeElements(&Ahead);//free up the allocated memory
	if(Ahead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 8
	
static void FrontBackSplit()//PROBLEM 9
{
	int boolean = 1;
	int content;
	struct node *Ahead = NULL;
	struct node *Bhead = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value for Ahead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Ahead, content);
		}
		else
		{
			boolean = 0;
		}
	}

	PrintListData(Ahead);
	Front_Back_Split(&Ahead, &Bhead);
	/* Bhead = Front_BackSplit(&Ahead); */
	PrintListData(Ahead);
	PrintListData(Bhead);
	freeElements(&Ahead);//free up the allocated memory
	if(Ahead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	freeElements(&Bhead);//free up the allocated memory
	if(Bhead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 9

static void RemoveDuplicates()//PROBLEM 10
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}
	PrintListData(head);
	Insert_Sort(&head);
	PrintListData(head);
	Remove_Duplicates(&head);
	PrintListData(head);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 10

static void MoveNode()//PROBLEM 11
{
	int boolean = 1;
	int content;
	struct node *Ahead = NULL;
	struct node *Bhead = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value for Ahead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Ahead, content);
		}
		else
		{
			boolean = 0;
		}
	}

	boolean = 1;
	while(boolean)
	{
		if(yesno("Would you like to enter a value for Bhead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Bhead, content);
		}
		else
		{
			boolean = 0;
		}
	}
	PrintListData(Ahead);
	PrintListData(Bhead);
	Move_Node(&Ahead, &Bhead);
	PrintListData(Ahead);
	PrintListData(Bhead);
	freeElements(&Ahead);//free up the allocated memory
	if(Ahead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	freeElements(&Bhead);//free up the allocated memory
	if(Bhead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 11

static void AlternatingSplit()//PROBLEM 12
{
	int boolean = 1;
	int content;
	struct node *Ahead = NULL;
	struct node *Bhead = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value for Ahead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Ahead, content);
		}
		else
		{
			boolean = 0;
		}
	}

	PrintListData(Ahead);
	PrintListData(Bhead);
	Alternating_Split(&Bhead, &Ahead);//notice the reverse order here compared with Move_Node
	PrintListData(Ahead);
	PrintListData(Bhead);
	freeElements(&Ahead);//free up the allocated memory
	if(Ahead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	freeElements(&Bhead);//free up the allocated memory
	if(Bhead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 12

static void ShuffleMerge()//PROBLEM 13
{
	int boolean = 1;
	int content;
	struct node *Ahead = NULL;
	struct node *Bhead = NULL;
	struct node *Chead = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value for Ahead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Ahead, content);
		}
		else
		{
			boolean = 0;
		}
	}

	boolean = 1;
	while(boolean)
	{
		if(yesno("Would you like to enter a value for Bhead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Bhead, content);
		}
		else
		{
			boolean = 0;
		}
	}
	PrintListData(Ahead);
	PrintListData(Bhead);
	PrintListData(Chead);
	Shuffle_Merge(&Ahead, &Bhead, &Chead);
	PrintListData(Ahead);
	PrintListData(Bhead);
	PrintListData(Chead);
	freeElements(&Ahead);//free up the allocated memory
	if(Ahead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	freeElements(&Bhead);//free up the allocated memory
	if(Bhead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	freeElements(&Chead);//free up the allocated memory
	if(Chead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 13

static void SortedMerge()//PROBLEM 14
{
	int boolean = 1;
	int content;
	struct node *Ahead = NULL;
	struct node *Bhead = NULL;
	struct node *Chead = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value for Ahead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Ahead, content);
		}
		else
		{
			boolean = 0;
		}
		Insert_Sort(&Ahead);
	}

	boolean = 1;
	while(boolean)
	{
		if(yesno("Would you like to enter a value for Bhead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Bhead, content);
		}
		else
		{
			boolean = 0;
		}
		Insert_Sort(&Bhead);
	}
	PrintListData(Ahead);
	PrintListData(Bhead);
	PrintListData(Chead);
	Sorted_Merge(&Ahead, &Bhead, &Chead);
	PrintListData(Ahead);
	PrintListData(Bhead);
	PrintListData(Chead);
	freeElements(&Ahead);//free up the allocated memory
	if(Ahead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	freeElements(&Bhead);//free up the allocated memory
	if(Bhead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	freeElements(&Chead);//free up the allocated memory
	if(Chead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 14

static void MergeSort()//PROBLEM 15
{
	int boolean = 1;
	int content;
	struct node *Ahead = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value for Ahead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Ahead, content);
		}
		else
		{
			boolean = 0;
		}
	}

	PrintListData(Ahead);
	Merge_Sort(&Ahead);
	PrintListData(Ahead);
	freeElements(&Ahead);//free up the allocated memory
	if(Ahead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 14

static void SortedIntersection()//PROBLEM 16
{
	int boolean = 1;
	int content;
	struct node *Ahead = NULL;
	struct node *Bhead = NULL;
	struct node *Chead = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value for Ahead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Ahead, content);
		}
		else
		{
			boolean = 0;
		}
		Insert_Sort(&Ahead);
	}

	boolean = 1;
	while(boolean)
	{
		if(yesno("Would you like to enter a value for Bhead (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&Bhead, content);
		}
		else
		{
			boolean = 0;
		}
		Insert_Sort(&Bhead);
	}
	PrintListData(Ahead);
	PrintListData(Bhead);
	PrintListData(Chead);
	Sorted_Intersection(&Ahead, &Bhead, &Chead);
	PrintListData(Ahead);
	PrintListData(Bhead);
	PrintListData(Chead);
	freeElements(&Ahead);//free up the allocated memory
	if(Ahead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	freeElements(&Bhead);//free up the allocated memory
	if(Bhead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	freeElements(&Chead);//free up the allocated memory
	if(Chead == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 16

static void Reverse()//PROBLEM 17
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}
	PrintListData(head);
	Reverse_List(&head);
	PrintListData(head);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 17

static void RecursionReverse()//PROBLEM 18
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Push(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}
	PrintListData(head);
	Recursion_Reverse(&head);
	PrintListData(head);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 18

static void quit()
{
	exit(0);
}

static struct
{
	char *string; //declaring this as a string is helpful when we use Nelts later
	//in other words, since it is a pointer it will have a standard size
	//as opposed to an array which will have a size dependent on the 
	//the size of the string in the array
	void (*func)(void);
}
menu_opts[] =
{
	{"Count", Count},
	{"GetNth", GetNth},
	{"DeleteList", DeleteList},
	{"Pop", Pop},
	{"InsertNth", InsertNth},
	{"Sorted Insert", SortedInsert},
	{"Insert Sorted", InsertSorted},
	{"Append Node", Append_Node_Problem},
	{"Front Back Split", FrontBackSplit},
	{"Remove Duplicates", RemoveDuplicates},
	{"Move Node", MoveNode},
	{"Alternating Split", AlternatingSplit},
	{"Shuffle Merge", ShuffleMerge},
	{"Sorted Merge", SortedMerge},
	{"Merge Sort", MergeSort},
	{"Sorted Intersection", SortedIntersection},
	{"Reverse", Reverse},
	{"Recursive Reverse", RecursionReverse},
	{"Exit Program", quit}
};

/*
 *  display_menu()
 *
 *  Display the full menu screen ONCE, then prompt for a choice and call
 *  the appropriate function
 */
static void display_menu()
{
	int     choice;
	int     i;


	/*
	 *  display the menu
	 */
	puts("Please choose an option:");
	for (i = 0; i < Nelts(menu_opts); i++)
		printf("%2d.  %s\n", i+1, menu_opts[i].string);

	/*
	 *  loop until they enter a valid choice
	 */
	for (;;)
	{
		read_int("Please enter your choice: ", &choice);
		if (choice > 0 && choice <= Nelts(menu_opts))
			break;
		puts("Invalid Selection");
	}

	/*
	 *  call the function (via the function pointer
	 */
	menu_opts[choice-1].func();
	enter("\nPress ENTER to continue: ");
}

/*
 *  goodbye()
 *
 *  Exit the program gracefully (used with atexit())
 */

static void goodbye()
{
	enter("\nPress ENTER to exit the program: ");
}


int main(void)
{

	atexit(goodbye);        /* ensure we say goodbye nicely */

	puts("Welcome to the solutions for Nick Parlante's Linked List Problems.");

	/*
	 *  just keep displaying the menu - the QUIT option will break the loop
	 */
	for (;;)
		display_menu();

}
