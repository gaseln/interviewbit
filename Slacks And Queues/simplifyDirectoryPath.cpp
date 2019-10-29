#include <iostream>
#include <stack>
#include <string>
#include <vector>

void updateStack(std::stack<std::string>& dirs, std::string str) {
    if (str == "..") {
        if (!dirs.empty()) dirs.pop();
    } else if (str != ".") {
        dirs.push(str);
    }
}

std::string simplifyPath(std::string path) {
    int begin = 0;
    std::string str;
    std::stack<std::string> dirs;
    while (begin != path.size()) {

        if (path[begin] == '/' && !str.empty()) {
            updateStack(dirs, str);
            str = "";
        }

        if (path[begin] != '/') {
            str += path[begin];
        }

        ++begin;
    }

    if (!str.empty()) {
        updateStack(dirs, str);
    }

    std::stack<std::string> path_s;

    while (!dirs.empty()) {
        str = dirs.top();
        path_s.push(str);
        dirs.pop();
    }

    str = "/";

    while (!path_s.empty()) {
        str += path_s.top();
        path_s.pop();
        str += (!path_s.empty()) ? "/" : "";
    }

    return str;
}

int main() {
    std::string abs_path = "/a//b////c/d//././/..";
    std::cout << simplifyPath(abs_path);
    return 0;
}