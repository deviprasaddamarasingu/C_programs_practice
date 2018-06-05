#include<stdio.h>
#include<stdlib.h>

void create_node(void);
void begin_node(void);
void iterate_node(void);
void iterate_key(int);

 struct node
{
    int data;
    struct node *next;
}*first,*last;



int main()
{
    int ch,n;
    first=last=NULL;
    while(1)
    {
        printf("Choose your option : \n1. Create node\t2. Add node at Beginning\t3. Display nodes\t \
               4. Iterate by key\tEnter other key to terminate program :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create_node();
                     break;
            case 2 : begin_node();
                     break;
            case 3 : iterate_node();
                     break;
            case 4 : printf("Enter node number : ");
                     scanf("%d",&n);
                     iterate_key(n);
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
    }
    else printf("No node created yet\n");
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

void iterate_key(int n)
{
    struct node *temp=first,*KeyNode;
    while(n--)
    {
        temp = temp->next;
    }
    KeyNode = temp;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = first;
    while(temp->next != KeyNode )
    {
        temp = temp->next;
    }
    temp->next = NULL;
    first = KeyNode;
}
