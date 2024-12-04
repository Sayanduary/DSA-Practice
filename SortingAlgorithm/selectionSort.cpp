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
void swap(int *A, int *B)
{
  int temp;
  temp = *A;
  *A = *B;
  *B = temp;
}
void selectionSort(int *A, int n)
{
  int i, j, k;
  for (int i = 0; i < n - 1; i++)
  {
    for (j = k = i; j < n ; j++)
    {
      if (A[j] < A[k])
      {
        k = j;
      }
      swap(&A[i], &A[k]);
    }
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