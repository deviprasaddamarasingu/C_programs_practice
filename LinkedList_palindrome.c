/*Given List is palindrome or not */

#include<stdio.h>
#include<stdlib.h>

void create_node(void);
void begin_node(void);
void iterate_node(void);
void middle_node(void);
void check_palindrome(void);

 struct node
{
    int data;
    struct node *next;
}*first,*last,*middle;

int main()
{
    int ch,num;
    first=last=NULL;
    while(1)
    {
        printf("Choose your option : \n1. Create node\t2. Add node at Beginning\t3. Display nodes\t4. Check Palindrome\nEnter other key to terminate program :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create_node();
                     break;
            case 2 : begin_node();
                     break;
            case 3 : iterate_node();
                     break;
            case 4 : check_palindrome();
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
        middle = temp;  /*middle node address storing in pointer middle*/
        printf("Middle element is %d\n",temp->data);
    }
    else
    {
        printf("List not yet created\n");
    }
}

void reverse_list_middle(void)
{
    struct node *prev,*cur,*nxt;
    prev=middle;
    cur = middle->next;
    while((cur->next != NULL) && (cur != NULL))
    {
        nxt=cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    cur->next= prev;
    middle->next = NULL;
    last = middle;
    middle = cur;
}

void check_palindrome(void)
{
    struct node *ftemp,*mtemp;
    middle_node();	/*find middle node */
    reverse_list_middle();	/*reverse list from middle to end*/
    if(first != NULL)	
    {
        ftemp = first;
        mtemp = middle;
        while(ftemp != last)	/*last is pointing at location middle*/
        {
            if(ftemp->data != mtemp->data)
            {
                printf("# # # \nGiven list is not palindrome\n# # # \n");
                return ;
            }
            ftemp=ftemp->next;
            mtemp=mtemp->next;
        }
        printf("* * *\nGiven list is palindrome\n* * *\n");
        reverse_list_middle();	/*restoring the list to original list*/
    }

}
