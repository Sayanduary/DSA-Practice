#include <stdio.h>
#include <stdlib.h>
int main()
{
  // int *p;
  // p = (int *)malloc(5 * (sizeof(int)));

  // for (int i = 0; i < 5; i++)
  // {
  //   scanf("%d", &p[i]);
  // }
  // for (int i = 0; i < 5; i++)
  // {
  //   printf("%d", p[i]);
  // }

  int *p = (int *)malloc(5 * sizeof(int));
  int *q = (int *)malloc(10 * sizeof(int));

  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &p[i]);
    q[i] = p[i];
    p = q;
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%d", q[i]);
  }

  delete[] p;
  return 0;
}