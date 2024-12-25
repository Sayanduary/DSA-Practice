#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int degree;
  cout << "Enter the degree of the polynomial: ";
  cin >> degree;
  vector<int> coefficient(degree + 1);
  cout << "Enter The Co-Efficients(from constant term to highest degree): ";
  for (int i = 0; i <= degree; i++)
  {
    cin >> coefficient[i];
  }

  cout << "The Polynomial is: ";
  for (int i = degree; i >= 0; i--)
  {
    cout << coefficient[i];
    if (i > 0)
    {
      cout << "x^" << i;
    }
    if (i > 0 && coefficient[i - 1] > 0)
    {
      cout << " + ";
    }
  }

  return 0;
}