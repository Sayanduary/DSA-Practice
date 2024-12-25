#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
  for (int i = 0; i < n; i++)
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

int partition(int *A, int low, int high)
{
  int pivot = A[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++)
  {
    if (A[j] < pivot)
    {
      i++;
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  int temp = A[i+1];
  A[i+1] = A[high];
  A[high] = temp;
  return i+1;
}

void quickSort(int *A, int low, int high)
{
  if (low < high)
  {
    int pivotIndex = partition(A, low, high);
    quickSort(A, low, pivotIndex - 1);
    quickSort(A, pivotIndex + 1, high);
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
