#include <iostream>
using namespace std;
void addPolynomials(int poly[], int poly2[], int result[], int size)
{
  for (int i = 0; i < size; i++)
  {
    result[i] = poly[i] + poly2[i];
  }
}
void printPolynomial(int poly[], int size)
{
  for (int i = size - 1; i >= 0; i--)
  {
    if (poly[i] != 0)
    {
      cout << poly[i] << " x^" << i << " ";
    }
  }
  cout << endl;
}
int main()
{
  int size = 5; // Maximum degree of the polynomials
  int poly1[size] = {1, 5, 2, 2, 3};
  int poly2[size] = {2, 1, 3, 4, 0};
  int result[size] = {0};
  addPolynomials(poly1, poly2, result, size);
  cout << "Polynomial 1: ";
  printPolynomial(poly1, size);

  cout << "Polynomial 2: ";
  printPolynomial(poly2, size);

  cout << "Resultant Polynomial: ";
  printPolynomial(result, size);

  return 0;
}