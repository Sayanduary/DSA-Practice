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

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int A[], int low, int high)
{
  int pivot = A[low];
  int i = low + 1;
  int j = high;
  while (i <= j)
  {
    while (A[i] <= pivot)
    {
      i++;
    }
    while (A[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      swap(&A[i], &A[j]);
    }
  }
  swap(&A[low], &A[j]);
  return j;
}
void quickSort(int A[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(A, low, high);
    quickSort(A, low, pi - 1);
    quickSort(A, pi + 1, high);
  }
}
int main()
{
  int A[] = {9, 8, 2, 0, 10, 11};
  int length = sizeof(A) / sizeof(A[0]);

  cout << "Before sorting: ";
  printArray(A, length);

  quickSort(A, 0, length-1);

  cout << "After sorting: ";
  printArray(A, length);

  return 0;
}
