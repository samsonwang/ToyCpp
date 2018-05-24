
#include <iostream>
#include <cmath>
using namespace std;

void printSpiralMatrixOutsideToInsideI(int n) {  
    if (n <= 0)
        return;
    
    int **a; // 动态分配二维数组的内存，声明一个指向数组的指针   
    a = new int*[n];  
    for (int i = 0; i < n; ++i) {  
        a[i] = new int[n];  
    }  
    int beginX = 0;  
    int endX = n-1;  
    int beginY = 0;  
    int endY = n-1;  
    int val = 1;  
    while (true) {  
        for (int i = beginX; i <= endX; ++i) {  
            a[beginY][i] = val++;  
        }  
        if (++beginY > endY) {  
            break;  
        }  
        for (int i = beginY; i <= endY; ++i) {  
            a[i][endX] = val++;  
        }  
        if (--endX < beginX) {  
            break;  
        }  
        for (int i = endX; i >= beginX; i--) {
            a[endY][i] = val++;  
        }  
        if (--endY < beginY) {  
            break;  
        }  
        for (int i = endY; i >= beginY; i--) {  
            a[i][beginX] = val++;  
        }  
        if (++beginX > endX) {  
            break;  
        }  
    }  
    // 打印出二维数组  
    for (int i = 0; i < n; ++i) {  
        for (int j = 0; j < n; ++j) {  
            cout << a[i][j] << "\t";  
        }  
        cout << endl;  
    }  
    // 释放二维数组的内存  
    for(int i = 0; i < n; ++i)   
        delete[] a[i];   
    delete[] a;  
}   
  
int main(int argc, char* argv[]) {
    int n;
    cout << "请输入一个数字n：" << endl;
    cin >> n;
          
    cout << "从外向内，顺时针打印螺旋矩阵（边界控制法，O(n*n)的空间复杂度内）" << endl;
    printSpiralMatrixOutsideToInsideI(n);
    cout << endl;

    return 0;
}


