#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);
    int result_position = -1;

    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket *tmp = new Bracket(next, position+1);
            opening_brackets_stack.push(*tmp);
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.size() == 0){
                result_position = position + 1;
                break;
            }
            else if (opening_brackets_stack.top().Matchc(next)){
                opening_brackets_stack.pop();
            }
            else{
                result_position = position + 1;
                break;
            }
        }
    }

    if (opening_brackets_stack.size() == 0 && result_position == -1) {
        cout << "Success" << endl;
    } else {
        if (opening_brackets_stack.size() && result_position == -1) {
            result_position = opening_brackets_stack.top().position;
        }
        cout << result_position << endl;
    }

    return 0;
}
