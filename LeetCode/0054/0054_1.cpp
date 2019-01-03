
#include <vector>
#include <iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.empty()) {
        return ans;
    }

    const int sx = matrix[0].size();
    const int sx_2 = sx / 2;

    const int sy = matrix.size();
    const int sy_2 = sy / 2;

    const int total = sx * sy;

    int n = 0;
    int e = 0;
    int w = 0;
    int s = 0;

    int i = 0;
    int j = -1;

    char direct = 'n';
    bool finish = false;
    do {
        switch (direct) {
        case 'n':
            for (++j; j<sx-e; ++j) {
                ans.push_back(matrix[i][j]);
            }
            --j;
            ++n;
            direct = 'e';
            break;
        case 'e':
            for (++i; i<sy-s; ++i) {
                ans.push_back(matrix[i][j]);
            }
            --i;
            ++e;
            direct = 's';
            break;
        case 's':
            for (--j; j>=w; --j) {
                ans.push_back(matrix[i][j]);
            }
            ++j;
            ++s;
            direct = 'w';
            break;
        case 'w':
            for (--i; i>=n; --i) {
                ans.push_back(matrix[i][j]);
            }
            ++i;
            ++w;
            direct = 'n';
            break;
        default:
            break;
        }

        // 终止条件
        if (n > sy_2
            || e > sx_2
            || s > sy_2
            || w > sx_2
            || (int)ans.size() == total) {
            finish = true;
        }

    } while (!finish);

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
