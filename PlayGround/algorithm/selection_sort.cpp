
#include <stdio.h>

// 交換兩個變數
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int len) 
{
	for (int i = 0 ; i < len - 1 ; i++)
    {
		int min = i;
		for (int j = i + 1; j < len; j++) // 走訪未排序的元素
        {
            if (arr[j] < arr[min]) // 找到目前最小值
            {
                min = j; // 紀錄最小值
            }
        }
	   	swap(&arr[min], &arr[i]);    //做交換
	}
}

int main(int argc, char *argv[])
{
    int nums[10] = {5, 3, 2, 4, 8, 9, 11, 10, 15, 1};
    selection_sort(nums, 10);

    for (int i=0; i<10; ++i)
    {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    
    return 0;
}

