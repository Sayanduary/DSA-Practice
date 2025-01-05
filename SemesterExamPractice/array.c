#include <stdio.h>
#include <stdlib.h>
struct Array
{
  int size;
  int *A;
  int length;
} *arr;

void createArray(struct Array *arr)
{
  printf("Enter the Size of An Arary: ");
  scanf("%d", &arr->size);

  arr->A = (int *)malloc(arr->size * sizeof(int));
  arr->length = 0;

  if (arr->A == NULL)
  {
    printf("Memory Allocation Failed\n");
    exit(1);
  }
}

void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void add(struct Array *arr, int val)
{
  if (arr->length < arr->size)
  {
    arr->A[arr->length++] = val;
  }
  else
  {
    printf("Array is Full");
  }
}
void insert(struct Array *arr, int index, int value)
{
  if (index < 0 || index > arr->length)
  {
    printf("Invalid Index! ");
    return;
  }
  if (arr->length == arr->size)
  {
    printf("Array is Full!");
  }

  for (int i = arr->length; i > index; i--)
  {
    arr->A[i] = arr->A[i - 1];
  }
  arr->A[index] = value;
  arr->length++;
}
void deleteArary(struct Array *arr, int index)
{
  if (index < 0 || index >= arr->length)
  {
    printf("invalid index");
    return;
  }
  for (int i = index; i < arr->length - 1; i++)
  {
    arr->A[i] = arr->A[i + 1];
  }
  arr->length--;
}
void display(struct Array arr)
{
  printf("Array elements: ");
  for (int i = 0; i < arr.length; i++)
  {
    printf("%d ", arr.A[i]);
  }
  printf("\n");
}
int linearSearch(struct Array *arr, int key)
{
  for (int i = 0; i < arr->length; i++)
  {
    if (arr->A[i] == key)
    {
      swap(&arr->A[i], &arr->A[i - 1]); // Transposition Exchange
                                        /*........any One of this for efficent search next time for findinf same key */
      swap(&arr->A[i], &arr->A[0]);     // Move to Front Method
      return i;
    }
  }
  return -1;
}

int binarySearchAlgorithm(struct Array *arr, int key)
{
  int low = 0;
  int high = arr->length - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr->A[mid] == key)
    {
      return mid;
    }
    else if (arr->A[mid] < key)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int max(struct Array *arr)
{
  int max = arr->A[0];
  for (int i = 1; i < arr->length; i++)
  {
    if (arr->A[i] > max)
    {
      max = arr->A[i];
    }
  }
  return max;
}

/*Reverse Array Method 1 ->  take an extra array */

void reverseArray(struct Array *arr)
{
  int *aux = (int *)malloc(arr->size * (sizeof(int)));
  if (aux == NULL)
  {
    printf("MEmory Allocation Failed");
    return;
  }
  for (int i = arr->length - 1, j = 0; i >= 0, j < arr->length; i--, j++)
  {
    aux[j] = arr->A[i];
  }
  for (int i = 0; i < arr->length; i++)
  {
    arr->A[i] = aux[i];
  }
}
void reverseExchangeMethod(struct Array *arr)
{
  int temp;
  int start = 0;
  int end = arr->length - 1;
  while (start < arr->length)
  {
    temp = arr->A[start];

    // Swap elements at start and end
    arr->A[start] = arr->A[end];
    arr->A[end] = temp;
    start++;
    end--;
  }
}
int main()
{
  struct Array arr;
  createArray(&arr);
  add(&arr, 10);
  add(&arr, 20);
  add(&arr, 30);
  display(arr);
  insert(&arr, 1, 12);
  add(&arr, 40);

  display(arr);
  printf("%d", arr.length);
  // deleteArary(&arr, 4);
  display(arr);
  int key = 10;
  int index = binarySearchAlgorithm(&arr, key);
  if (index != -1)
  {
    printf("Element %d found at A[%d] \n ", key, index);
  }
  else
  {
    printf("Element not found\n");
  }
  printf("Max Element: %d", max(&arr));
  reverseExchangeMethod(&arr);
  display(arr);
  free(arr.A);
  return 0;
}