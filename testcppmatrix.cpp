#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

int main () {
    using namespace boost::numeric::ublas;
    
    matrix<double> m (3, 3);
    identity_matrix<double> m1 (3);
    matrix<double> m2 (3,3);
    
    for (unsigned i = 0; i < m.size1 (); ++ i){
      for (unsigned j = 0; j < m.size2 (); ++ j){
            m (i, j) = 3 * i + j;
      }
    }
    // m2 = m + 3*m1;
    m2 = prod(m,3*m1);
    std::cout << m2  << std::endl;

    return 0;
}
