#ifndef Pekare_hpp
#define Pekare_hpp

#include <stdio.h>

class list{
    
public:
    list();
    void insert(int item);
    
private:
    
    struct node{
        
        int member;
        node* next;
        node* prev;
        
        node(int item){member = item;}
    };
    
    
    node p_last{4};
    node p_first{4};
public:
    void print();
}

;
#endif /* Pekare_hpp */
