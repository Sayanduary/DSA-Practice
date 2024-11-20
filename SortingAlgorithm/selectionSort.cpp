#include <iostream>
using namespace std;
void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

void selectionSort(int *A, int n)
{
  int indexOfMin;
  cout << "Running Selection Sort.." << endl;
  for (int i = 0; i < n - 1; i++)
  {
    indexOfMin = i;
    for (int j = i + 1; j < n; j++)
    {
      if (A[j] < A[indexOfMin])
      {
        indexOfMin = j;
      }
    }
    int temp = A[i];
    A[i] = A[indexOfMin];
    A[indexOfMin] = temp;
  }
}

int main()
{
  int A[] = {8, 0, 7, 8, 3};
  int length = sizeof(A) / sizeof(A[0]);
  printArray(A, length);
  selectionSort(A, length);
  printArray(A, length);
  return 0;
}