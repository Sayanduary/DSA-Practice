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
  int isSorted = 0;
  for (int i = 0; i < n - 1; i++) // for number of passes
  {
    cout << "Working on pass number " << i << endl;
    isSorted = 1;
    for (int j = 0; j < n - 1 - i; j++) // number of comparisions
    {
      if (A[j] > A[j + 1])
      {
        int temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
        isSorted = 0;
      }
    }
    if (isSorted)
    {
      return;
    }
  }
}

int main()
{

  int A[] = {12, 23, 10, 11, 60};
  int B[] = {10, 12, 13, 14, 15, 16};
  int length = sizeof(A) / sizeof(A[0]);
  cout << "Before Sorting Array: ";
  printArray(B, length);
  bubbleSort(B, length);

  cout << "Sorted Arary : ";
  printArray(B, length);
  return 0;
}