

#include <vector>
#include <iostream>

using namespace std;

static auto fast = [](){
                       ios_base::sync_with_stdio(false);
                       cin.tie(nullptr);
                       return 0;
                   }();

// n^2 的解法，效率堪忧
void rotate(vector<vector<int>>& matrix) {
    int size = matrix[0].size();
    int layer = size / 2;
    int end = size - 1;
    int offset = size % 2;

    for (int j=0; j<layer; ++j) {
        for (int i=0; i<layer+offset; ++i) {
            int temp = matrix[i][end-j];
            matrix[i][end-j]     = matrix[j][i];
            matrix[j][i]         = matrix[end-i][j];
            matrix[end-i][j]     = matrix[end-j][end-i];
            matrix[end-j][end-i] = temp;
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& line : matrix) {
        for ( int n : line) {
            cout << n << "\t";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {

    vector<vector<int>> matrix;
#if 0
    matrix.push_back(vector<int>{1,2,3});
    matrix.push_back(vector<int>{4,5,6});
    matrix.push_back(vector<int>{7,8,9});
#else
    matrix.push_back(vector<int>{1,2,3,4});
    matrix.push_back(vector<int>{5,6,7,8});
    matrix.push_back(vector<int>{9,10,11,12});
    matrix.push_back(vector<int>{13,14,15,16});
#endif

    cout << "before:" << endl;
    printMatrix(matrix);

    rotate(matrix);

    cout << "after:" << endl;
    printMatrix(matrix);

    return 0;
}
