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

void insertionSort(int A[], int n)
{
  int i, j, store;
  for (i = 1; i < n; i++)
  {
    j = i - 1;
    store = A[i];
    while (j > -1 && A[j] > store)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = store;
  }
}

int main()
{

  int A[] = {10, 19, 20, 2, 3};
  int length = sizeof(A) / sizeof(A[0]);
  insertionSort(A, length);
  printArray(A, length);
  return 0;
}