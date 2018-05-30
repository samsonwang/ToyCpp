
#include <stdio.h>

void insertion_sort(int arr[], int len)
{
    for(int i=1; i<len; ++i)
    {
        int target = arr[i];
        int j=i;
        for(; j>0; --j)
        {
            if (arr[j-1] > target)
            {
                arr[j] = arr[j-1];
            }
            else
            {
                break;
            }
        }
        arr[j] = target;
    }
}

void insertion_sort2(int arr[], int len)
{
    for(int i=1; i<len; ++i)
    {
        int target = arr[i];
        int j=i-1;
        for (; j>=0 && arr[j]>target; --j)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = target;
    }
}

int main(int argc, char *argv[])
{
    int nums[10] = {5, 3, 2, 4, 8, 9, 11, 10, 15, 1};
    
    insertion_sort2(nums, 10);

    for (int i=0; i<10; ++i)
    {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    
    return 0;
}



