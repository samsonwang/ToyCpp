
// leetcode commit fastest sample
// 很明显，这个方法更加优雅，边界条件也更加清晰

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int N = matrix.size();
    if (N == 0) return result;
    int M = matrix[0].size();
    if (M == 0) return result;

    int left = 0, right = M - 1;
    int low = 0, high = N - 1;

    while (left <= right && low <= high) {
        if (left == right) {
            for (int i = low; i <= high; i++)
                result.push_back(matrix[i][right]);
            break;
        }
        if (low == high) {
            for (int i = left; i <= right; i++)
                result.push_back(matrix[high][i]);
            break;
        }

        for (int i = left; i < right; i++)
            result.push_back(matrix[low][i]);
        for (int i = low; i < high; i++)
            result.push_back(matrix[i][right]);
        for (int i = right; i > left; i--)
            result.push_back(matrix[high][i]);
        for (int i = high; i > low; i--)
            result.push_back(matrix[i][left]);

        left++, right--;
        low++, high--;
    }
    return result;
}
