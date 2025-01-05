#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
} *head;

void create(int A[], int n)
{
  int i;
  struct Node *t, *last;
  head = (struct Node *)malloc(sizeof(struct Node));
  head->data = A[0];
  head->next = head;
  last = head;

  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = last->next;
    last->next = t;
    last = t;
  }
}
void display(struct Node *h)
{
  do
  {
    printf("%d->", h->data);
    h = h->next;
  } while (h != head);
  printf("(head)");
}

void insertAnyPosition(struct Node **head, int position, int val)
{
  struct Node *t, *p = *head;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = val;
  if (position == 0)
  {
    if (*head == NULL)
    {
      t->next = *head;
      *head = t;
    }
    else
    {
      while (p->next != *head)
      {
        p = p->next;
      }
      t->next = *head;
      p->next = t;
      *head = t;
    }
  }
  else
  {
    for (int i = 0; i < position - 1 && p->next != *head; i++)
    {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

int main()
{
  int A[] = {2, 3, 5, 6};
  create(A, 4);
  printf("Original List:\n");
  display(head);

  printf("Inserting 10 at position 0:\n");
  insertAnyPosition(&head, 0, 10);
  display(head);

  printf("Inserting 15 at position 2:\n");
  insertAnyPosition(&head, 2, 15);
  display(head);

  printf("Inserting 20 at position 6:\n");
  insertAnyPosition(&head, 6, 20);
  display(head);

  return 0;
}