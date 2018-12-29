
// code from https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/

/* Extended version of power function that can work
   for float x and negative y*/
#include<stdio.h>

float power(float x, int y) {
	float temp;
	if( y == 0)
        return 1;
	temp = power(x, y/2);
	if (y%2 == 0) {
        return temp*temp;
    }
	else {
        if(y > 0)
			return x*temp*temp;
		else
			return (temp*temp)/x;
	}
}

/* Program to test function power */
int main() {
	float x = 2;
	int y = -5;
	printf("%f", power(x, y));
	return 0;
}


/*
  算法分析：
  对于指数是正数的情况来说，由于减少了乘法的运算步骤，算法的时间复杂度为 O(nlogn)。
  对于指数是负数的情况来说，先将负指数的形式转化为分数，再计算该分数的正指数。
*/
