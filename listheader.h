#define Nelts(a)            (sizeof(a) / sizeof((a)[0]))

struct node 
{
	int data;
	struct node *next;
};

int getLength(struct node *headRef);
void PrintListData(struct node *head);
void ElementSearch(struct node *head, int content, int *count);
short int GetValue(struct node *head, int content, int *value);
void Push(struct node **headRef, int data);
void AppendNode(struct node **headRef, int data);
void Delete_List(struct node **headRef);
int PopHead(struct node **headRef);
void Insert_Nth(struct node **headRef, int insertNum);
void Sorted_Insert(struct node **headRef);
void Insert_Sort(struct node **headRef);
void Append_Node(struct node **Ahead, struct node **Bhead);
void Front_Back_Split(struct node **Ahead, struct node **Bhead);
/* struct node *Front_BackSplit(struct node **Ahead); */
void Remove_Duplicates(struct node **headRef);
void Move_Node(struct node **Destination, struct node **Source);
void Move_Append_Node(struct node **Destination, struct node **Source);
void Alternating_Split(struct node **Destination, struct node **Source);
void Shuffle_Merge(struct node **Ahead, struct node **Bhead, struct node **Chead);
void Sorted_Merge(struct node **Ahead, struct node **Bhead, struct node **Chead);
void Merge_Sort(struct node **Ahead);
void Sorted_Intersection(struct node **Ahead, struct node **Bhead, struct node **Chead);
void Reverse_List(struct node **headRef);
void Recursion_Reverse(struct node **headRef);
void freeElements(struct node **head);
int yesno(char *prompt);
void read_int(char *prompt, int *choice);
void enter(char *prompt);
