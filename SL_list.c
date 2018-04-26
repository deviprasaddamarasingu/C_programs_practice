#include<stdio.h>
 struct node
{
    int data;
    struct node *next;
}*first,*last;

int main()
{
    first=last=NULL:
    create_node();

}

void create_node()
{
    int val=0;
    struct node *mid;
    mid = (struct node *)malloc(sizeof(struct node ));
    printf("size of mid : %d",sizeof(*mid));
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
