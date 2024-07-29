class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        stack.reserve(tokens.size());
        int result = 0;

        for (auto &token: tokens) {
            try {
                if (isdigit((int)*(token.end() - 1))) {
                    int to_push = std::stoi(token);
                    stack.push_back(to_push);
                    result = to_push;
                } else {
                    int y = *(stack.end() - 1);
                    int x = *(stack.end() - 2);

                    if (token[0] == '*')
                        result = x * y;
                    else if (token[0] == '/')
                        result = x / y;
                    else if (token[0] == '+')
                        result = x + y;
                    else if (token[0] == '-')
                        result = x - y;

                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back(result);
                }
            } catch (...) {}
        }
        return result;
    }
};