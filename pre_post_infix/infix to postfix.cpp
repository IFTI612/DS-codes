#include<bits/stdc++.h>
using namespace std;


int priority(char eq)
{
    if(eq=='+'||eq=='-')
    {

        return +1;
    }
    else if(eq=='*'||eq=='/')
    {

        return +3;
    }
    else if(eq=='^')
    {

        return +5;
    }
    else
    {

        return -1;
    }

}


int main()
{
    string infix,postfix ;
    stack<char>s;
    cin>>infix;

    int t=0;
    while(infix[t]!=NULL)
    {
        char symbol = infix[t];
        if((symbol>='A'&&symbol<='Z')||(symbol>='a'&&symbol<='z')||(symbol>='0'&&symbol<='9'))
            postfix = postfix + symbol;

        else if (symbol=='(')
            s.push(symbol);
        else if(symbol==')')
        {
            while(!s.empty()&&s.top()!='(')
            {
                postfix = postfix +s.top();
                s.pop();
            }
            if(!s.empty())
                s.pop();

        }
        else
        {
            while(!s.empty()&&(priority(s.top())>=priority(symbol)))
            {
                postfix = postfix +s.top();
                s.pop();
            }
            s.push(symbol);

        }


        t++;
    }
    while(!s.empty())
    {
        postfix = postfix +s.top();
        s.pop();
    }
cout<<postfix<<endl;
    stack<int>s2;

    for(int i = 0 ; i<postfix.size();i++)
    {
        char symbol = postfix[i];
        if(symbol>='0'&&symbol<='9')
        {
            s2.push(symbol-'0');
        }
        else if(symbol=='+')
        {
            int a = s2.top();
            s2.pop();
            int b = s2.top();
            s2.pop();
            s2.push(b+a);

        }
        else if(symbol=='-')
        {
            int a = s2.top();
            s2.pop();
            int b = s2.top();
            s2.pop();
            s2.push(b-a);

        }
        else if(symbol=='*')
        {
            int a = s2.top();
            s2.pop();
            int b = s2.top();
            s2.pop();
            s2.push(b*a);

        }
        else if(symbol=='/')
        {
            int a = s2.top();
            s2.pop();
            int b = s2.top();
            s2.pop();
            s2.push(b/a);

        }
    }
cout<<s2.top()<<endl;



    return 0;

}
