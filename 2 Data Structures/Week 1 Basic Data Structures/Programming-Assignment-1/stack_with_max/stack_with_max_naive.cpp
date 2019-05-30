#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;
using namespace std;

/*
using Auxilliary stack
https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
*/

class Stack {
    vector<int> stack;
    int top;

  public:
  
    Stack() {top = -1;}
    
    bool isEmpty(){
        if (top == -1){
            return true;
        }
        return false;
    }

    void Push(int value) {
        top++;
        stack.push_back(value);
    }

    int Pop() {
        assert(stack.size());
        int tmp = stack.back();
        top--;
        stack.pop_back();
        return tmp;
    }
/*
    int Max() const {
        assert(stack.size());
        return *max_element(stack.begin(), stack.end());
    }
*/
};

class AuxilliaryStack: public Stack
{
    Stack maxstack;
    
    public:
    
    void Push(int value){
        if (isEmpty() == 0){
            Stack::Push(value);
            maxstack.Push(value);
        }
        else{
            Stack::Push(value);
            int tmpmax = maxstack.Pop();
            maxstack.Push(tmpmax);
            if (value > tmpmax){
                maxstack.Push(value);
            }
            else{
                maxstack.Push(tmpmax);
            }
        }
    }
    
    int Pop(){
        int tmp = Stack::Pop();
        maxstack.Pop();
        return tmp;
    }
    
    int getMax(){
        int result = maxstack.Pop();
        maxstack.Push(result);
        return result;
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    //StackWithMax stack;
    AuxilliaryStack stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.getMax() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}