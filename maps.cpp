#include <iostream>
using namespace std ;
#include <map>


int main() {
    map <char , int > mp{
        {'T', 7}
    } ;
    mp['u']=9;
    pair <char , int > p1('j', 5) ; // creating a pair 
    mp.insert(p1) ;       // there two types of insertion . we can also mp.insert(pair(char , int )('j', 5)) ; 
    cout << mp['T'] << endl ; 
    mp.erase(p1.first) ; // deleting j 
    mp.clear() ; // deleting the whole map 
    mp.empty();  // bool type returns 1 if T
    mp.size() ; // the size of the map 
    // acces all the pairs of the map 
    for(map<char , int >::iterator itr=mp.begin() ; itr!= mp.end() ; ++itr) { // mp::iterator== auto , mp.begin() the first pair of the map , mp.end the last pair
        //access every pair
        cout << itr->second << endl ;//(*itr).second== itr->second


    }
}
