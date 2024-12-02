#include <iostream>
using namespace std;
void swap(int *A, int *B)
{
  int temp;
  temp = *A;
  *A = *B;
  *B = temp;
}
void bubbleSort(int A[], int n)
{
  int isSorted;
  for (int i = 0; i < n - 1; i++)
  {
    isSorted = 0;
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (A[j] > A[j + 1])
      {
        swap(&A[j], &A[j + 1]);
        isSorted = 1;
      }
    }
    if (isSorted == 0)
    {
      break;
    }
  }
}
void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << " " << A[i];
  }
}
int main()
{
  int A[] = {2, 5, 7, 11, 10};
  int size = sizeof(A) / sizeof(A[0]);
  bubbleSort(A, size);
  printArray(A, size);
  return 0;
}