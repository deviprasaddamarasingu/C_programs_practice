/*Nth node from the end of a Linked List*/
#include<stdio.h>
#include<stdlib.h>

void create_node(void);
void begin_node(void);
void iterate_node(void);
void Nth_node_last(int);


 struct node
{
    int data;
    struct node *next;
}*first,*last;

int main()
{
    int ch,num;
    first=last=NULL;
    while(1)
    {
        printf("Choose your option : \n1. Create node\t2. Add node at Beginning\t3. Display nodes\t4. Nth node from end of a list\nEnter other key to terminate program :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create_node();
                     break;
            case 2 : begin_node();
                     break;
            case 3 : iterate_node();
                     break;
            case 4 : printf("Enter Nth position : ");
                     scanf("%d",&num);
                     Nth_node_last(num);
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

void Nth_node_last(int num)
{
    int i=num;
    struct node *temp = first,*pos=first;
    while(temp != NULL)
    {
        i--;
        if(i >= 0)
        {
            temp=temp->next;
        }
        else
        {
            pos = pos->next;
            temp = temp->next;
        }
    }
    if(i > 0)   //if i>0 after while loop means user entered Nvalue greater than list count
    {
        printf("***\nEntered N value greater than List length\n***\n");
    }
    else if (temp == NULL)  // confirming whether temp reached end of the list or not
    {
        printf("***\nElement at %d position from end is %d\n***\n",num,pos->data);
    }
}
