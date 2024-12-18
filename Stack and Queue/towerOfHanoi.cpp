// #include <iostream>
// using namespace std;
// void towerOfHanoi(int n, char source, char auxiliary, char destination)
// {
//   if (n == 1)
//   {
//     cout << "Move disk 1 from " << source << "to" << destination << endl;
//     return;
//   }
//   towerOfHanoi(n - 1, source, destination, auxiliary);
//   cout << "Move disk" << n << "from" << source << "to" << destination << endl;
//   towerOfHanoi(n - 1, auxiliary, source, destination);
// }
// int main()
// {
//   int numDisks;
//   cout << "Enter the Number of Disks " << endl;
//   cin >> numDisks;
//   towerOfHanoi(numDisks, 'A', 'B', 'C');
//   return 0;
// }

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

void moveDisk(stack<int> &src, stack<int> &dest, char s, char d)
{
  if (src.empty())
  {
    int topDisk = dest.top();
    dest.pop();
    src.push(topDisk);
    cout << "Move Disk " << topDisk << " from " << d << " to " << s << endl;
  }
  else if (dest.empty())
  {
    int topDisk = src.top();
    src.pop();
    dest.push(topDisk);
    cout << "Move Disk " << topDisk << " from " << s << " to " << d << endl;
  }
  else if (src.top() > dest.top())
  {
     int topDisk = dest.top();
        dest.pop();
        src.push(topDisk);
        cout << "Move Disk " << topDisk << " from " << d << " to " << s << endl;
  }
  else
  {
    int topDisk = src.top();
    src.pop();
    dest.push(topDisk);
    cout << "Move Disk " << topDisk << " from " << s << " to " << d << endl;
  }
}
void towerOfHanoiIterative(int n)
{
  stack<int> source, auxiliary, destination;
  char s = 'A', a = 'B', d = 'C';
  for (int i = n; i >= 1; --i)
    source.push(i);
  int totalMoves = pow(2, n) - 1;
  if (n % 2 == 0)
  {
    swap(a, d);
  }
  for (int i = 1; i <= totalMoves; ++i)
  {
    if (i % 3 == 1)
    {
      moveDisk(source, destination, s, d);
    }
    else if (i % 3 == 2)
    {
      moveDisk(source, auxiliary, s, a);
    }
    else if (i % 3 == 0)
    {
      moveDisk(auxiliary, destination, a, d);
    }
  }
}
int main()
{
  int numDisks;
  cout << "Enter the number of Disks: " << endl;
  cin >> numDisks;
  towerOfHanoiIterative(numDisks);
  return 0;
}