

#include <iostream>
#include <random>

#include "Unsorted.h"


int main(){
    UnsortedType list;
    std::cout <<"Values when list is empty: \n";

    for(int i = 0; i < list.GetLength(); i++){
       list.GetNextItem().Print(std::cout);

    }
    
    try{

    
    list.Head().Print(std::cout);

    list.Tail().Print(std::cout);
    }catch(const std::out_of_range& e){
        std::cout<<"List is Empty" << std::endl;
    }


    int stop = rand() % 50;

    for(int i = 0; i < 50; i++){
        if(i==stop){
            for(int i = 0; i < stop; i++){
    list.GetNextItem().Print(std::cout);

    }

    try{


    list.Head().Print(std::cout);

    list.Tail().Print(std::cout);
    }catch(const std::out_of_range& e){
    std::cout<<"List is Empty" << std::endl;
    }
        }
        ItemType CurrentType;
        CurrentType.Initialize(rand());
        list.PutItem(CurrentType);
        
    }
std::cout << "Print values once 50 items have been added\n";

    for(int i = 0; i < 50; i++){
    list.GetNextItem().Print(std::cout);

    }

    try{


    list.Head().Print(std::cout);

    list.Tail().Print(std::cout);
    }catch(const std::out_of_range& e){
    std::cout<<"List is Empty" << std::endl;
    }

    


}
