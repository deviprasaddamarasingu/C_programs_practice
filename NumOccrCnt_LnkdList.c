/*Write a function that counts the number of times a given int occurs in a Linked List*/

#include<stdio.h>
#include<stdlib.h>

void create_node(void);
void begin_node(void);
void iterate_node(void);
void count(int);

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
        printf("Choose your option : \n1. Create node\t2. Add node at Beginning\t3. Display nodes\t4. Count element\nEnter other key to terminate program :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1  :   create_node();
                        break;
            case 2  :   begin_node();
                        break;
            case 3  :   iterate_node();
                        break;
            case 4  :   printf("Enter key element to count the occurance :");
                        scanf("%d",&num);
                        count(num);
                        break;
            default :   printf("wrong input Program terminating\n");
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

void middle_node(void)
{
    struct node *temp,*temp1;
    if(first != NULL)
    {
        temp=first;
        temp1=first->next;
        while((temp1 != NULL) && (temp1->next != NULL))
        {
            temp = temp->next;
            temp1= temp1->next->next;
        }
        printf("Middle element is %d\n",temp->data);
    }
    else
    {
        printf("List not yet created\n");
    }
}

void count(int key)
{
    int cnt=0;
    struct node *temp;
    if(first != NULL)
    {
        temp=first;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                cnt++;
            }
            temp = temp->next;
        }
        printf("Occurance of given element %d is %d times\n",key,cnt);
    }
    else
    {
        printf("List not yet created\n");
    }
}
