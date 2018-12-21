

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

static auto fast = [](){
                       ios_base::sync_with_stdio(false);
                       cin.tie(nullptr);
                       return 0;
                   }();

// leetcode fastest 4ms sample
void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = i + 1; j < matrix[i].size(); j++)
            swap(matrix[i][j], matrix[j][i]);
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
