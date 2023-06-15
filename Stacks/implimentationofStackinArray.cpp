#include <iostream>
using namespace std;

class stack
{
public:
  // properties;
  int top;
  int size;
  int *arr;

  // methods;
  stack(int s)
  {
    this->size = s;
    top = -1;
    arr = new int[s];
  }

  void push(int x)
  {
    if (size - top > 1)
    {
      top++;
      arr[top] = x;
    }
    else
    {
      cout << "Stack Overflow" << endl;
    }
  }

  void pop()
  {
    if (top >= 0)
    {
      top--;
    }
    else
    {
      cout << "stack is empty" << endl;
    }
  }

  int peek()
  {
    if (top >= 0)
    {
      return arr[top];
    }
    else
    {
      cout << "stack is empty" << endl;
      return -1;
    }
  }

  bool isEmpty()
  {
    if (top == -1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.pop();

  cout <<"the top of stack is: "<<endl;
  cout << s.peek() << endl;
  return 0;
}
