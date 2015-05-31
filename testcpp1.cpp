#include <iostream>
#include <vector>
#include <algorithm>

extern "C"
{
#include <cblas.h>
}

using namespace std;

class CVector {
public:
  vector<int> alist;
  CVector () {};
  CVector (vector<int> a){alist = a;}
  int total = 0;
  int gettotal(){
    for_each(begin(alist), end(alist), [&](int x) {total += x;});
      return total;
      }
};


int main()
{  
  vector<int> some_list{1, 2, 3, 4, 5};
  CVector ab_list(some_list);

  cout << ab_list.gettotal()  << endl;
  return 0;
}
