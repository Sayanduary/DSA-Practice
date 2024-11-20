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
void insertionSort(int *A, int n)
{
  int j;
  // Loop for Passes
  for (int i = 1; i <= n - 1; i++)
  {

    int key = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > key)
    { 
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
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