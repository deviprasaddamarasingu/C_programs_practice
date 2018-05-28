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
    n=sizeof(Arr)/sizeof(Arr[0]);
    Bubble_sort(Arr,n);
    printf("_______________\nSorted array:\n_______________\n");
    for(i=0; i<ARR_SIZE; i++)
    {
        printf("%d\t",Arr[i]);
    }
    return 0;
}

void Bubble_sort(int Arr[],int num)
{
    int x,y;
    for(x=0; x< num-1; x++)
    {
        for(y=0; y < (num-x)-1; y++)
        {
            if(Arr[y] > Arr[y+1])
            {
                Swap(&Arr[y],&Arr[y+1]);
            }
        }
    }
}


void Swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q= temp;
}

