
#include <stdio.h>

void insertion_sort(int arr[], int len)
{
    
    
}

int main(int argc, char *argv[])
{
    int nums[10] = {5, 3, 2, 4, 8, 9, 11, 10, 15, 1};
    
    insertion_sort(nums, 10);

    for (int i=0; i<10; ++i)
    {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    
    return 0;
}



