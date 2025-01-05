#include <iostream>
using namespace std;
void printArray(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}
void merge(int *arr, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = (right - mid);
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = arr[mid + 1 + j];
  }
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  for (; i < n1; i++)
  {
    arr[k] = L[i];

    k++;
  }
  for (; j < n2; j++)
  {
    arr[k] = R[j];

    k++;
  }
}

void mergeSort(int *arr, int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}
int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int length = sizeof(arr) / sizeof(arr[0]);

  cout << "Given array: ";
  printArray(arr, length);
  cout << endl;

  mergeSort(arr, 0, length - 1);

  cout << "Sorted array: ";
  printArray(arr, length);
  cout << endl;

  return 0;
}