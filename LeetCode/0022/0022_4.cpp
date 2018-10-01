
#include <vector>
#include <iostream>
#include <cstdio>
#include <set>
#include <list>

using namespace std;

static const auto fast = [](){
                             ios_base::sync_with_stdio(false);
                             cin.tie(NULL);
                             return 0;
                         }();

// 根据leetcode上的solution提示，还可以使用暴力解法完成本题

// 判断一个括号表达式是否有效
bool isValid(const string& str) {
    int balence = 0;
    for (char ch : str) {
        if (ch == '(') {
            ++balence;
        }
        else {
            --balence;
        }

        if (balence < 0) {
            return false;
        }
    }
    return balence == 0;
}

// 生成所有可能的组合
void genAllPossible(vector<string>& all, int n) {
    // leetcode给出的是递归的方法，而我想的是之前一个题目中使用的BFS算法

    // BFS需要一个链表
    list<string> bfs;
    bfs.push_back("");
    while (bfs.size() != 0) {
        string frt = bfs.front();
        bfs.pop_front();
        if (frt.size() == n*2) {
            all.push_back(frt);
            continue;
        }
        bfs.push_back(frt + '(');
        bfs.push_back(frt + ')');
    }
}

void genAllP1Helper(vector<string>& all, string s, int n) {
    if (s.size() == 2*n) {
        all.push_back(s);
        return;
    }
    genAllP1Helper(all, s + '(', n);
    genAllP1Helper(all, s + ')', n);
}

void genAllPossible1(vector<string>& all, int n) {
    // 仿照leetcode的递归解法
    genAllP1Helper(all, "", n);
}


//
vector<string> generateParenthesis(int n) {
    // 所有可能的组合
    vector<string> all;

    genAllPossible1(all, n);

    vector<string> ret;
    for (const auto& s : all) {
        if (isValid(s)) {
            ret.push_back(s);
        }
    }

    return ret;
}

int main(int argc, char* argv[])
{
    vector<string> ans = generateParenthesis(2);

    cout << ans.size() << endl;

    for (const auto& s : ans) {
        cout << s << endl;
    }

    return 0;
}
