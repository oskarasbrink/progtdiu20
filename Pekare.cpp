#include "Pekare.hpp"
#include <iostream>

list::list(){
    
    p_first.next = &p_last;
    p_last.prev = &p_first;
}
void list::insert(int item){
    node temp{item};
    //std::cout<<p_first.next;
    temp.next = p_first.next;
    temp.prev = &p_first;
    std::cout<<temp.prev->member<<" "<<temp.member<<" ";
    std::cout<<temp.next->member<<"---";
    temp.next->prev = &temp;

    p_first.next = &temp;
    std::cout<<p_first.next->member<<'\n';
    //std::cout<<p_first.next->member<<"  ";
    
 /*  node temp1{2};
    temp1.next = p_first.next;
    temp1.prev = &p_first;

    p_first.next->prev = &temp1;

    p_first.next = &temp1;
    std::cout<<p_first.next->member<<" "<<p_first.next->next->member;*/
}

void list::print(){
    node* curry = p_first.next;
    std::cout<<curry->member<<"  "<<curry->next->member<<"  ";
    
    
    }
  
    
    // curr=curr->next;
   // std::cout<<curr->member;
    
    //std::cout<<p_first.member<<"  "<<p_first.next->member<<p_first.next->next->member;
    //std::cout<<curr->member<<" , ";
    
    //curr = curr->next;
    
   // std::cout<<curr->member;

