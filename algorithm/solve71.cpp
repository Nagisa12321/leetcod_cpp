#include "leetcode.h"

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> paths;
        string path_name;
        for (char c : path) {
            if (c == '/') {
                if (path_name == "..") {
                    if (!paths.empty())
                        paths.pop_back();
                } else if (!path_name.empty() && path_name != ".") {
                    paths.push_back(path_name);
                }
                path_name.clear();
            } else {
                path_name.push_back(c);
            }
        }
        if (!path_name.empty() && path_name != ".")
            paths.push_back(path_name);
        string res;
        if (paths.empty()) return "/";
        for (const string &p : paths) 
            res += "/" + p;
        return res;
    }
};

int main() {
    Solution solve;
    string res = solve.simplifyPath("/home/");
    cout << res << endl;
}
