#include <string>
#include <vector>
#include <stack>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string s) {
        std::stack<std::string> stack;
        std::stringstream ss(s);
        std::string component;
        
        while (std::getline(ss, component, '/')) {
            if (component.empty() || component == ".") {
                // Ignore '.' and empty strings
                continue;
            } else if (component == "..") {
                // Pop from stack for '..'
                if (!stack.empty()) {
                    stack.pop();
                }
            } else {
                // Push valid directory names
                stack.push(component);
            }
        }
        
        if (stack.empty()) {
            return "/";
        }
        
        std::string ans = "";
        std::vector<std::string> temp;
        while (!stack.empty()) {
            temp.push_back(stack.top());
            stack.pop();
        }
        std::reverse(temp.begin(), temp.end());
        
        for (const std::string& dir : temp) {
            ans += "/" + dir;
        }
        
        return ans;
    }
};