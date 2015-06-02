#include <iostream>
#include <vector>

//declare function
double average(std::vector<double> * ARRAY);

int main(){
  std::vector<double> vec1 {1.0,2.2,3.3,4.7,5.9};

  /*
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size1 = vec1.size();
  */

  double result = average(&vec1);

  std::cout << result << std::endl;
  return 0;
}


// Pass a vector by pointer
double average(std::vector<double> * ARRAY){
  double sum = 0.0;
  
  /*for(std::vector<double>::size_type i =0; i != SIZE; ++i){
    sum  = sum + (*ARRAY)[i];
  }
  */
  for (auto&& i : *ARRAY){
    sum = sum + i;
  }

  return sum;
}
