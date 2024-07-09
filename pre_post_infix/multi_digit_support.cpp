#include <bits/stdc++.h>
using namespace std;

int priority(char eq)
{
    if (eq == '+' || eq == '-')
    {
        return 1;
    }
    else if (eq == '*' || eq == '/')
    {
        return 3;
    }
    else if (eq == '^')
    {
        return 5;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(const string& infix)
{
    string postfix = "";

    stack<char> s;

    int n = infix.size();

    for (int i = 0; i < n; ++i)
    {
        char symbol = infix[i];

        // multi digit number
        if (isdigit(symbol))
        {
            while (i < n && isdigit(infix[i]))
            {
                postfix += infix[i++];
            }
            postfix += ' ';
            i--;
        }
        else if (isalpha(symbol))
        {
            postfix += symbol;
        }
        else if (symbol == '(')
        {
            s.push(symbol);
        }
        else if (symbol == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            while (!s.empty() && priority(s.top()) >= priority(symbol))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(symbol);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix)
{
    stack<int> s;
    int n = postfix.size();

    for (int i = 0; i < n; ++i)
    {
        char symbol = postfix[i];

        if (isdigit(symbol))
        {
            int num = 0;
            while (i < n && isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i++] - '0');
            }
            s.push(num);
            i--; // Decrement to offset the upcoming increment in the for loop
        }
        else if (symbol == ' ')
        {
            continue;
        }
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            switch (symbol)
            {
            case '+':
                s.push(b + a);
                break;
            case '-':
                s.push(b - a);
                break;
            case '*':
                s.push(b * a);
                break;
            case '/':
                s.push(b / a);
                break;
            case '^':
                s.push(pow(b, a));
                break;
            }
        }
    }

    return s.top();
}

int main()
{
    string infix;
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
