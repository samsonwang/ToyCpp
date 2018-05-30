
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
	return x < y ? x : y;
}

void merge_sort(int arr[], int len) {
	int* a = arr;
	int* b = (int*) malloc(len * sizeof(int));
	int seg;
    int start;
	for (seg = 1; seg < len; seg += seg) {
		for (start = 0; start < len; start += seg + seg) {
			int low = start;
            int mid = min(start + seg, len);
            int high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		int* temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		int i;
		for (i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	free(b);
}

int main(int argc, char *argv[])
{
    int nums[10] = {5, 3, 2, 4, 8, 9, 11, 10, 15, 1};
    
    merge_sort(nums, 10);

    for (int i=0; i<10; ++i)
    {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    
    return 0;
}


