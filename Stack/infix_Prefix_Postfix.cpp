#include <iostream>
#include <string>
using namespace std;
#define MAX 100
struct Stack
{
  int size;
  int top;
  char *arr;

  Stack() : size(0), top(-1), arr(nullptr) {}
  void createStack()
  {

    cout << "Enter the size of the Stack";
    cin >> size;
    if (size > MAX)
    {
      cout << "Size Exceeded ";
      size = MAX;
    }
    arr = (char *)malloc(size * sizeof(char));
  }

  void push(char c)
  {
    if (top >= MAX - 1)
    {
      cout << "Stack is Overflow ";
    }
    arr[++top] = c;
  }
  char pop()
  {
    if (top == -1)
    {
      cout << " Stack Underflow ";
    }
    return arr[top--];
  }
  char stackTop()
  {

    if (top == -1)
    {
      cout << "Stacl=k Underflow ";
    }
    return arr[top];
  }
  void displayStack()
  {
    if (top == -1)
    {
      cout << "Stack is Empty ";
    }
    for (int i = top; i >= 0; i--)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  ~Stack()
  {
    delete[] arr;
  }
};
int main()
{
  struct Stack st;
  st.createStack();
  st.push('a');
  st.push('b');
  st.push('c');
  st.displayStack();
  return 0;
}