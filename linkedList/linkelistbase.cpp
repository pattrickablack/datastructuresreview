#include <iostream>

/*
    ESTA ES UNA VERSION ABREVIADA Y FUNCIONAL DE UNA linkedlist  ASCENDENTE Node1 ->  Node2 -> Node3 
    
    THIS IS A BASIC VERSION OF linkedlist  LIKE Node1 ->  Node2 -> Node3 
    
*/

// GENERAL STRUCTURE OF THE NODE
struct node
{
    int data;
    struct node *next;
};





class linked_list
{
    private:
        node *head;
        node *tail;

    public:
    
    linked_list()
    {
        head=NULL;
        tail=NULL;
    }

    void add_node(int n) {
        node *temporal = new node;
        temporal->data =n;
        temporal->next=NULL;
        
        if( head ==NULL ) {
            head = temporal;
            tail = temporal;
        }else {
            tail->next = temporal; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            tail = tail->next;      // REAPUNTANDO tail AL NUEVO NODO
        }

    }

    // Return the curren head-node
    node* getHead() const{
        return head;
    }

    // Check if especific data is inside the linked list
    bool exist(int dataSearch) {

        node *tmp = new node;
        tmp= getHead();

        while (tmp != NULL){
             //std::cout << tmp-> data << std::endl;

            if (tmp->data== dataSearch){
                 std::cout << tmp-> data << " * SI ESTA *" << std::endl;
                return true;
            }
           

            tmp = tmp->next;
        }

         std::cout  << " * NO ESTA *" << std::endl;
        return false;
    }



    // remove node with the especific dataToRemove 
    bool remove(int dataToRemove) {

        node *tmp = new node;
        tmp = getHead();


        node *tmpPrev = new node;
        tmpPrev = NULL;

        while (tmp != NULL){
             //std::cout << tmp-> data << std::endl;

            if (tmp->data== dataToRemove){
                
                std::cout << tmp-> data << " * SI ESTA  -> BORRANDO *" << std::endl;

                if( tmpPrev == NULL && tmp->next !=NULL ) {
                    std::cout << "chequeo A"<<std::endl;

                    //head = tmp->next;
                    tmp->data  = tmp->next->data;
                    tmp->next  = tmp->next->next;

                }else if( tmpPrev == NULL && tmp->next == NULL ) {
                     std::cout << "chequeo B"<<std::endl;
                   // tmp = getHead();
                    head = NULL;
                    tail  = NULL;
                }else{
                     std::cout << "chequeo C"<<std::endl;
                    tmpPrev->next  =  tmp->next;
                    tmp =  tmp->next;
                }

            
                return true;
            }
           
             tmpPrev = tmp;
             tmp = tmp->next;
          
        }

         std::cout  << " * NO ESTA s *" << std::endl;
        return false;
    }

    // Show all de data-nodes on screen
    void showmeLL()
    {

        node *tmp = new node;
        tmp= getHead();

        while (tmp != NULL){
            
            std::cout << tmp-> data << std::endl;

            tmp = tmp->next;
        }

    }

}; // End Class









void showLL(linked_list & ll){

    node *tmp = new node;
    tmp= ll.getHead();

    while (tmp != NULL){
        
        std::cout << tmp-> data << std::endl;

        tmp = tmp->next;
    }

}






int main () {

     linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(43);
     a.add_node(24);

     a.remove(1);
     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
     a.showmeLL();

    a.add_node(84);
    std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS CON 84 DE LL" << std::endl;
    a.showmeLL();


  a.remove(2);
     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
     a.showmeLL();

  a.remove(43);
     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
     a.showmeLL();

  a.remove(84);
     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
     a.showmeLL();

  a.remove(3);
     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
     a.showmeLL();

       a.remove(24);
     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
     a.showmeLL();

    a.add_node(84);
    std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS CON 84 DE LL" << std::endl;
    a.showmeLL();

   a.add_node(25);
    std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS CON 25 DE LL" << std::endl;
    a.showmeLL();

    // showLL(a);
    // CHQUEANDO SI UN DATO EXISTE
    a.exist(25);

    return 0;
}