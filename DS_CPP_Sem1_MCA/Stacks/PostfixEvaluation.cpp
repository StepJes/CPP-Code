#include <iostream> #include<conio.h> #include<stdlib.h> #include<math.h> #include<ctype.h> const int MAX=50;
using namespace std;
class postfix

{

private:
    int stack[MAX];
    int top, nn;
    char *s;

public:
    postfix();

    void setexpr(char *str);
    void push(int item);
    int pop();

    void calculate();
    void show();
};

postfix::postfix()

{

    top = -1;
}

void postfix::setexpr(char *str)

{

    s = str;
}

void postfix::push(int item)

{

    if (top == MAX - 1)

        cout << endl
             << "Stack is full";

    else

    {

        top++;

        stack[top] = item;

        cout << "\t" << item;
    }
}

int postfix::pop()

{

    if (top == -1)

    {

        cout << endl
             << "stack is empty";

        return 0;
    }

    else

    {

        int data = stack[top];

        top--;

        cout << "\n"
             << data;

        return data;
    }
}

void postfix::calculate()

{

    int n1, n2, n3;

    while (*s)

    {

        if (*s == ' ' || *s == '\t')

        {

            s++;

            continue;
        }

        if (isdigit(*s))

        {

            nn = *s - '0';

            push(nn);
        }

        else

        {

            n1 = pop();

            n2 = pop();

            switch (*s)

            {

            case '+':

                n3 = n2 + n1;

                break;

            case '-':

                n3 = n2 - n1;

                break;

            case '/':

                n3 = n2 / n1;

                break;

            case '*':

                n3 = n2 * n1;

                break;

            default:

                cout << "\n unknown operator";
            }

            push(n3);
        }

        s++;
    }
}

void postfix::show()

{

    nn = pop();

    cout << "\n result is: " << nn;
}

int main()

{

    char expr[MAX];

    cout << "\n Enter postfix expression to be evaluated \n";

    cin.getline(expr, MAX);

    postfix q;

    q.setexpr(expr);

    q.calculate();

    q.show();

    getch();
}
