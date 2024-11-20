#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
  for (int i = 0; i <= n - 1; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}
void bubbleSort(int *A, int n)
{
  for (int i = 0; i < n - 1; i++) // for number of passes
  {
    for (int j = 0; j < n - 1 - i; j++) // number of comparisions
    {
      if (A[j] > A[j + 1])
      {
        int temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int A[] = {12, 23, 10, 11, 60};
  int length = sizeof(A) / sizeof(A[0]);
  cout << "Before Sorting Array: ";
  printArray(A, length);
  bubbleSort(A, length);

  cout << "Sorted Arary : ";
  printArray(A, length);
  return 0;
}