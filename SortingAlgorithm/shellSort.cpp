#include <iostream>
using namespace std;

void printArray(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void shellSort(int *arr, int n)
{
  // rearrange elements at each n/2 ,n/4,n/8...intervals
  for (int interval = n / 2; interval > 0; interval /= 2)
  {
    for (int i = interval; i < n; i++)
    {
      int temp = arr[i];
      int j;
      for (j = i; j >= interval && arr[j - interval] > temp; j -= interval)
      {
        arr[j] = arr[j - interval];
      }
      arr[j] = temp;
    }
  }
}

int main()
{
  int arr[] = {9, 8, 3, 7, 5, 6, 4, 1};
  int length = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, length);
  shellSort(arr,length);
  printArray(arr,length);
  return 0;
}