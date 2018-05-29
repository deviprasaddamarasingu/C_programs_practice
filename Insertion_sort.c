/*Insertion sort*/
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
    insertion_sort(Arr,n);
    printf("_______________\nSorted array:\n_______________\n");
    for(i = 0; i < ARR_SIZE; i++)
    {
        printf("%d\t",Arr[i]);
    }
    return 0;
}


void insertion_sort(int Arr[],int num)
{
	int pos,i,j;
	for(i=1; i < num; i++)
	{
		pos =i;
		for(j=i-1; (Arr[j] > Arr[pos])&&(j>=0); j--)
		{
			Swap(&Arr[j],&Arr[pos]);
			pos=j;
		}
	}
}

void Swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q= temp;
}
