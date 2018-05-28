/*Array should be in sorted order */
#include <stdio.h>
#define ARR_SIZE 5  /*ARR_SIZE depends on input you can change the value */

int main()
{
    int arr[ARR_SIZE],i,key,pos,num;
    printf("Enter %d numbers in sorted order\n",ARR_SIZE);
    for(i=0; i< ARR_SIZE ; i++)
        scanf("%d",&arr[i]);
	num = sizeof(arr)/sizeof(arr[0]);
    printf("Enter key element : ");
    scanf("%d",&key);
    if((pos = bin_search(arr,key,0,num-1)) >= 0)
		printf("Entered Key element found at position %d \n", pos+1);
	else
		printf("Entered Key element not found in sorted list\n");
    return 0;
}

int bin_search(int arr[],int key,int low, int high)
{
    static int mid;
    if(low <= high) /*if low <= high means it exceeded the array limit so return -1*/
    {
        mid = (low + high)/2;
        if( arr[mid] == key)    /*if key is at mid index then return mid*/
        {
            return mid;
        }
        else if(key > arr[mid]) /*if key > arr[mid] then call bin_search with low=mid+1 because we know that up to mid we verified so pass mid+1 */
        {
            bin_search(arr,key,mid+1,high);
        }
        else if(key < arr[mid]) /*if key < arr[mid] then call bin_search with high=mid-1 because we know that key is present before arr[mid] */
        {
            bin_search(arr,key,low,mid-1);
        }
    }
    else return -1; /*if element not found return -1*/
}
