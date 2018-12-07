
#include <stdio.h>

// 小在前大在后
void bubble_sort(int nums[], int size)
{
    for (int i=0; i<size-1; ++i)
    {
        for (int j=0; j<size-i-1; ++j)
        {
            if (nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int nums[10] = {5, 3, 2, 4, 8, 9, 11, 10, 15, 1};
    bubble_sort(nums, 10);

    for (int i=0; i<10; ++i)
    {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    
    return 0;
}




