#include <iostream>
using namespace std;
#include <vector>




int main(){
   vector <int> v1={1,2,3} ;
   cout << v1[1] << endl ; 
   v1.front() ; // gives the first element of the vector 
   v1.back() ; // gives the last element of the vector 
   v1.capacity() ; // gives the capacity of the vector  
   // if the vector is full the size is auto-doubled
   // for example
   v1.push_back(9) ;
   cout << v1.capacity() << endl  ; 
   v1.pop_back() ; //pops the last element  of the vector.The size is decreased not the capacity
   v1.shrink_to_fit(); // reduced the capacity to the number of elements of the vector
   v1.insert(v1.begin() , 5) ; // inserting an element at the beginning of the vector
   v1.insert(.begin()+1 , 5) ; // inserting an element at the beginning +1 pcsitionv1v1  of the vector

   v1.erase(v1.begin()) //erase an element at the beginnign of the vector 
   for(int i =0 ; i< v1.size() ; ++i) cout << v1[i] ; // iterting through  vectors 
   for(auto itr =v1.begin() ; itr !=v1.end() ; ++ itr ) cout << *itr // iterting through  vectors
   
   
   }
