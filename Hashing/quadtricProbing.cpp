#include <iostream>
using namespace std;
#define SIZE 10
int hashFunction(int key)
{
  return key % 10;
}
int quadricProbe(int H[], int key)
{
  int index = hashFunction(key);
  int i = 0;
  while (H[(index + i * i) % SIZE] != 0)
  {
    i++;
  }
  return (index + i * i) % SIZE;
}

void insert(int H[], int key)
{
  int index = hashFunction(key);
  if (H[index] != 0)
  {
    index = quadricProbe(H, key);
  }
  H[index] = key;
}
void display(int H[])
{
  for (int i = 0; i < SIZE; i++)
  {
    std::cout << i << " --> " << H[i] << std::endl;
  }
}
int main()
{
  int HT[SIZE] = {0};
  insert(HT, 23);
  insert(HT, 43);
  insert(HT, 13);
  insert(HT, 27);
  display(HT);
  return 0;
}