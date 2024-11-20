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
  int pivot = A[high]; // Use last element as pivot
  int i = low - 1;     // Initialize i to track smaller elements

  for (int j = low; j < high; j++)
  {
    if (A[j] <= pivot) // If current element is less than or equal to pivot
    {
      i++;
      swap(&A[i], &A[j]); // Swap elements at i and j
    }
  }
  swap(&A[i + 1], &A[high]); // Place pivot in the correct position
  return i + 1;              // Return pivot index
}

void quickSort(int *A, int low, int high)
{
  if (low < high)
  {
    int pi = partition(A, low, high);

    quickSort(A, low, pi - 1);  // Sort elements before partition
    quickSort(A, pi + 1, high); // Sort elements after partition
  }
}

int main()
{
  int A[] = {9,8,2,0,10,11};
  int length = sizeof(A) / sizeof(A[0]);

  cout << "Before sorting: ";
  printArray(A, length);

  quickSort(A, 0, length - 1);

  cout << "After sorting: ";
  printArray(A, length);

  return 0;
}
