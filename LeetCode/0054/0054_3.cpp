
// exercise for 0054_2.cpp

#include <vector>
#include <iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int N = matrix.size();
    if (N == 0) {
        return ans;
    }
    int M = matrix[0].size();
    if (M == 0) {
        return ans;
    }

    int left = 0;
    int right = M - 1;
    int up = 0;
    int down = N - 1;

    while (left <= right && up <= down) {
        if (left == right) {
            for (int i=up; i<=down; ++i) {
                ans.push_back(matrix[i][right]);
            }
            break;
        }

        if (up == down) {
            for (int i=left; i<=right; ++i) {
                ans.push_back(matrix[up][i]);
            }
            break;
        }

        for (int i=left; i<right; ++i) {
            ans.push_back(matrix[up][i]);
        }
        for (int i=up; i<down; ++i) {
            ans.push_back(matrix[i][right]);
        }
        for (int i=right; i>left; --i) {
            ans.push_back(matrix[down][i]);
        }
        for (int i=down; i>up; --i) {
            ans.push_back(matrix[i][left]);
        }

        ++left;
        ++up;
        --right;
        --down;
    };

    return ans;
}

void print(const vector<vector<int>>& matr) {
    for (const auto& vec : matr) {
        for (int n : vec) {
            cout << n << "\t";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> matrix;
    matrix.push_back(vector<int>({1,2,3}));
    matrix.push_back(vector<int>({4,5,6}));
    //    matrix.push_back(vector<int>({7,8,9}));

    print(matrix);
    vector<int> ans = spiralOrder(matrix);
    cout << "ans: ";
    for (int n : ans) {
        cout << n << " ";
    }
    cout << endl;

    vector<vector<int>> matrix2;
    matrix2.push_back({1,2,3,4});
    matrix2.push_back({5,6,7,8});
    matrix2.push_back({9,10,11,12});
    //    matrix2.push_back({13,14,15,16});

    print(matrix2);

    vector<int> ans2 = spiralOrder(matrix2);
    cout << "ans2: ";
    for (int n : ans2) {
        cout << n << " ";
    }
    cout << endl;

    vector<vector<int>> matrix3;
    matrix3.push_back({1,2});
    matrix3.push_back({3,4});

    print(matrix3);

    vector<int> ans3 = spiralOrder(matrix3);

    cout << "ans3: ";
    for (int n : ans3) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
