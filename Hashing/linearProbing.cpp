#include <iostream>
#define Size 10

int hashFN(int key)
{
  return key % Size;
}

int probe(int H[], int key)
{
  int index = hashFN(key);
  int i = 0;
  while (H[(index + i) % Size] != 0)
  {
    i++;
  }
  return (index + i) % Size;
}

void insert(int H[], int key)
{
  int index = hashFN(key);
  if (H[index] != 0) // If collision occurs
  {
    index = probe(H, key);
  }
  H[index] = key; // Insert the key
}

void display(int H[])
{
  for (int i = 0; i < Size; i++)
  {
    std::cout << i << " --> " << H[i] << std::endl;
  }
}

int main()
{
  int HT[Size] = {0}; // Initialize hash table with zeros
  insert(HT, 12);
  insert(HT, 25);
  insert(HT, 35);
  insert(HT, 26);

  display(HT); // Display the hash table

  return 0;
}
