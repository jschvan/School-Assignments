#include <string>
#include <stack>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length)
{
    if(length == 0){
        return 0;
    }
    int count = 0;
    stack<int> mathStack;
    for(int i = 0; i < length; i++){
        int a, b;
        if(isdigit(expression[i][0])){
            mathStack.push(stoi(expression[i]));
            count ++;
        }
        else if(mathStack.size() >= 2){
                switch(expression[i][0]){
                    case '+':
                        a = mathStack.top();
                        mathStack.pop();
                        b = mathStack.top();
                        mathStack.pop();
                        mathStack.push(b+a);
                        //cout << "adding " << a << " and " << b << endl;
                        break;
                    case '-':
                    a = mathStack.top();
                    mathStack.pop();
                    b = mathStack.top();
                    mathStack.pop();
                    mathStack.push(b-a);
                    //cout << "subtracting " << a << " and " << b << endl;
                    break;
                case '*':
                    a = mathStack.top();
                    mathStack.pop();
                    b = mathStack.top();
                    mathStack.pop();
                    mathStack.push(b*a);
                    //cout << "multiplying " << a << " and " << b << endl;
                    break;
                case '/':
                    a = mathStack.top();
                    mathStack.pop();
                    b = mathStack.top();
                    mathStack.pop();
                    mathStack.push(b/a);
                    //cout << "dividing " << a << " and " << b << endl;
                    break;
                case '%':
                    a = mathStack.top();
                    mathStack.pop();
                    b = mathStack.top();
                    mathStack.pop();
                    mathStack.push(b%a);
                    //cout << "remaindering " << a << " and " << b << endl;
                    break;
                }
        }
        
        else{
            return 0;
        }
        
    }
    if(mathStack.size() == 1){
        return mathStack.top();
    }
    else{
        return 0;
    }
}