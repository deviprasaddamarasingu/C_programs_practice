#include<stdio.h>
#include<stdlib.h>

void create_node(void);
void begin_node(void);
void iterate_node(void);
void reverse_list(void);
void delete_node(int);

static int count;
 struct node
{
    int data;
    struct node *next;
}*first,*last;
// below pointers are for recursive reverse list function
//struct node *prev=NULL,*cur=NULL,*nxt=NULL;

int main()
{
    int ch,key;
    first=last=NULL;
    while(1)
    {
        printf("Choose your option : \n1. Create node\t2. Add node at Beginning\t3. Display nodes\t4. Reverse list\n5. Delete node\t6. Length of LList\nEnter other key to terminate program :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create_node();
                     break;
            case 2 : begin_node();
                     break;
            case 3 : iterate_node();
                     break;
            case 4 : reverse_list();
                     break;
            case 5 : printf("Enter key element to delete : ");
                     scanf("%d",&key);
                     delete_node(key);
                     break;
            case 6 : printf("Length of Linked list is %d\n",count);
                     break;
            default : printf("wrong input Program terminating\n");
                      exit(0);
        }
    }
}

void create_node(void)
{
    int val=0;
    struct node *mid;
    mid = (struct node *)malloc(sizeof(struct node ));
    printf("Enter data ");
    scanf("%d",&val);
    if(last == NULL)
    {
        mid->data = val;
        mid->next = NULL;
        first=last=mid;
    }
    else if(first != NULL)
    {
        mid->data = val;
        mid->next = NULL;
        last->next= mid;
        last=mid;
    }
    count++;    /*Length of the linked list*/
}

void begin_node(void)
{
    int val=0;
    struct node *mid;
    mid = (struct node *)malloc(sizeof(struct node ));
    if(first)
    {
        printf("Enter data ");
        scanf("%d",&val);
        mid->data = val;
        mid->next = first;
        first = mid;
        count++;    /*Length of the linked list*/
    }
    else
    {
        printf("No node created yet\n");
        free(mid);
    }
}

void iterate_node(void)
{
    struct node *temp = first;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

}

void reverse_list(void)
{
    struct node *prev,*cur,*nxt;
    prev=first;
    cur = first->next;
    while(cur->next != NULL)
    {
        nxt=cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    cur->next= prev;
    first->next = NULL;
    last = first;
    first= cur;
}

/* //Reverse of single linked list using recursion
//Note : remove comments of struct node *prev,*cur,*nxt;
void reverse_list(void)
{
	if(prev == NULL)
	{
		prev = first;
		cur = first->next;
	}
	if(cur->next != NULL)
	{
		nxt = cur->next;
		cur->next = prev;
        prev = cur;
        cur = nxt;
		reverse_list();
	}
	else
	{
		cur->next= prev;
		first->next = NULL;
		last = first;
		first= cur;
	}
}
*/

void delete_node(int key)
{
    struct node *temp=first,*temp1=NULL;
    while((temp->data != key)&&(temp->next != NULL))
    {
        temp1= temp;
        temp = temp->next;
    }
    if(temp1 == NULL)
    {
        first=temp->next;
        free(temp);
        count--;    /*calculating length of the linked list*/
    }
    else if(temp->next != NULL)
    {
        temp1->next = temp->next;
        free(temp);
        count--;    /*calculating length of the linked list*/
    }
    else if(temp->data == key)
    {
        temp1->next = NULL;
        last = temp1;
        free(temp);
        count--;    /*calculating length of the linked list*/
    }
    else
    {
        printf("***\nEntered key element not available in list\n***\n");
    }
}
