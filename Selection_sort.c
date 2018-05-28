/*Selection sort*/
#include <stdio.h>
#define ARR_SIZE 5


int main()
{
    int Arr[ARR_SIZE],i,n;
    printf("Enter %d elements : \n",ARR_SIZE);
    for(i=0; i<ARR_SIZE; i++)
    {
        scanf("%d",&Arr[i]);
    }
    n = sizeof(Arr)/sizeof(Arr[0]);
    selection_sort(Arr,n);
    printf("_______________\nSorted array:\n_______________\n");
    for(i = 0; i < ARR_SIZE; i++)
    {
        printf("%d\t",Arr[i]);
    }
    return 0;
}


void selection_sort(int Arr[],int num)
{
    int pos,i,j;
    for(i = 0; i < num -1; i++)
    {
        pos=i;  /*storing the first index of unsorted array */
        for(j=i+1; j < num; j++)
        {
            if(Arr[pos] > Arr[j]) /*first index is greater than j index so need to overwrite the pos with lesser element index*/
            {
                pos = j;
            }
        }
        if(pos != i)    /*if pos != i means unsorted array first index needs to swap with pos(ie; pos contains the index of lesser element) index*/
        {
            Swap(&Arr[i],&Arr[pos]);
        }
    }
}

void Swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q= temp;
}
