
#include <vector>
#include <list>
#include <iostream>

#include "../../shared/stream.h"

// 如何生成 n^n 复杂度的排列
void generate(int n, std::vector<std::vector<int>>& ans) {
    std::list<std::vector<int>> bfs;
    bfs.emplace_back();

    while (!bfs.empty()) {
        std::vector<int> v = bfs.front();
        bfs.pop_front();
        if (int(v.size()) >= n) {
            ans.push_back(v);
            continue;
        }

        for (int i=1; i<=n; ++i) {
            v.push_back(i);
            bfs.push_back(v);
            v.pop_back();
        }
    }
}

int main(int argc, char* argv[]) {

    std::vector<std::vector<int>> ans;

    generate(4, ans);

    for (const auto& vec : ans) {
        std::cout << vec << std::endl;
    }

    std::cout << "ans size:" << ans.size() << std::endl;

    return 0;
}
