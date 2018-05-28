/*Array should be in sorted order */
#include <stdio.h>
#define ARR_SIZE 5

int main()
{
    int arr[ARR_SIZE],i,key,pos,num;
    printf("Enter 5 numbers in sorted order\n");
    for(i=0; i< ARR_SIZE ; i++)
        scanf("%d",&arr[i]);
	num = sizeof(arr)/sizeof(arr[0]);
    printf("Enter key element : ");
    scanf("%d",&key);
    if(pos = bin_search(arr,key,num))
		printf("Entered Key element found at position %d \n", pos);
	else
		printf("Entered Key element not found in sorted list\n");
    return 0;
}

int bin_search(int arr[],int key,int num)
{
    static int mid;
	low=0,high=num;
    mid = (low + high)/2;
    if( arr[mid] == key)
        return mid;
    else if(key > arr[mid])
	{

        bin_search(&arr[mid],key,num);
	}
    else return -1;
}
