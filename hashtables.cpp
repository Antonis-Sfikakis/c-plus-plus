
#include "hashtable.h"
#include <iostream>
#include <cstdlib>
using std::string
using namespace std ;   

class  hash
{
    private:        
        static const int  tablesize=10;//static const means that we can define and use inside the class 
        struct item{ //list
            string name ; 
            string drink ;
            item *next ;
        } ; 
        item * hashtable[tablesize] ; //hash is array with list pointers 
    

    public:
        hash();
        int Hash(string key); 
        void AddItem(string name , string drink) ; 
        int NumberOfItems(int index) ; 
        void PrintTable() ; 
        void FindDrink(string name) ; //search function 
        void RemoveItem(string name );
};


hash:: hash(){
  for(int i =0; i < tablesize ; i++) {
    hashtable[i] = new item; 
    hashtable[i]->name ="empty" ; 
    hashtable[i]->drink="empty" ;
    hashtable[i]->next= NULL; 

  }
   
}

int hash:: Hash(string key ){
    int hash=0;
    int index = key.length() ;
    for(int i=0 ; i < key.length() ; ++i)//adding up the the key values 
    //we are going to mod with the table size to find the spot of the key
      hash+= key.at(i) ; 
    index=hash % tablesize ; 
    return index ;  
}  


void hash ::AddItem(string name , string drink){
  int index=Hash(name) ; 
  if(hashtable[index]=="empty"){
    hashtable[index]->name=name ; //the position is empty 
    hashtable[index]->drink=drink;
  }else{
    item * ptr = hashtable[index] ;  // create new position
    item * n = new item ;
    n->name  = name ;
    n->drink = drink ; //go to the end of the list 
    n->next=NULL ;
    while(ptr->next!=NULL) ptr=ptr->next;
    ptr->next=n;  
  }
} 



int hash:: NumberOfItems(int index) {
  int count =0; 
  if(hashthash(index)->name=="empty") return 0;
  else{
    count++;
    item * ptr = hashtable[index] ; 
    while (ptr->next != NULL ) {
      count++;
      ptr = ptr -> next ; 
    }
     
  }
  return count ; 
}


void hash :: Printable() {
  int number 
  for(int i=0 ; i<tablesize ; ++i) {
    cout << i << ":" ;
     if(hashtable[i]->name=="empty") continue; 
     else{
        item* ptr = hashtable[i];
        while((ptr->next)!=NULL ){
          cout<<prt->name<<" "<<prt->drink<<endl;
          prt=ptr->next ;
        }
     }
  }
}

void hash::FindDrink(string name)
{
  int index= Hash(name) ; 
  item *ptr = hashtable[index] ;  //search in hash table  
  if(ptr->drink=="empty") return ;
  else{
    while ((ptr->next)!=NULL && !(ptr->name == name)){
      ptr=ptr->next ;
    }
    if(!(ptr->name == name))return ;
    cout << ptr->drink << endl; 
  }
}


void hash::RemoveItem(string name ){
  int index=Hash(name ); 
  item * ptr = hashtable [index],*p1,*p2;
  //if the first element is empty then there are no items to remove.
  if(ptr->nane=="empty"){
    cout << name << endl ;
    cout << "NOT FOUND " << endl; 
  }
  //case 1 -  only 1 item  and that bucket has a matching name
  else if(ptr->name== name && ptr->next== NULL) {
    hashtable[index]->name="empty" ; 
    hashtable[index]->drink="empty" ; 

  }
  //case 2 -  match is located in the first bucket but there are more items in the bucket 
  else if(ptr->name==name ){
    hashtable[index]=hastable[index]->next;
    delete ptr ; 
  }
  //case 3 -   match found in second or third buckets .
  else{
    p1=hashtable[index]->name ; 
    p2=hashtable[index] ; 
    while(p1!=NULL && p1->name!=name){
      p2=p1;
      p1=p1->next ; 
    }
    //case 3.1 - no match
    if(p1==NULL ) return ;//name not exist
    else{
      ptr=p1;//deleting item
      p1=p1->next;
      p2->next=p1;
      delete ptr ;
    }
  }


}
