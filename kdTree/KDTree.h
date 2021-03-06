#ifndef KDTREE_INCLUDED
#define KDTREE_INCLUDED

#include <iostream>
#include "point.h"



template <size_t N, typename ElemType>
class KDTree
{   
    private:
        struct node
            {
                int data;
                Point<N> dataPoint;
                struct node *next;
                struct node *before;
                ElemType classification;     
            };
            
    private:
        /* data */
        //typedef

        node *head;
        node *tail;
        Point<N> pt; 
        size_t sizeKDTree ;

    public:


        // Constructor: KDTree();
        // Usage: KDTree<3, int> myTree;
        // ----------------------------------------------------
        // Constructs an empty KDTree.
        KDTree(/* args */);



        // Destructor: ~KDTree()
        // Usage: (implicit)
        // ----------------------------------------------------
        // Cleans up all resources used by the KDTree.
        ~KDTree();


        
        // size_t size() const;
        // bool empty() const;
        // Usage: if (kd.empty())
        // ----------------------------------------------------
        // Returns the number of elements in the kd-tree and whether the tree is
        // empty.
        size_t size() const;
        bool empty() const;




        // void insert(const Point<N>& pt, const ElemType& value);
        // Usage: kd.insert(v, "This value is associated with v.");
        // ----------------------------------------------------
        // Inserts the point pt into the KDTree, associating it with the specified
        // value. If the element already existed in the tree, the new value will
        // overwrite the existing one.
        //void insert(const Point<N>& pt);
        void insert(const Point<N>& pt, const ElemType& value);



      


        // bool contains(const Point<N>& pt) const;
        // Usage: if (kd.contains(pt))
        // ----------------------------------------------------
        // Returns whether the specified point is contained in the KDTree.
        // contained in the KDTree.
        bool contains( Point<N>& pt) ;//const
    




        // ElemType& at(const Point<N>& pt);
        // const ElemType& at(const Point<N>& pt) const;
        // Usage: cout << kd.at(v) << endl;
        // ----------------------------------------------------
        // Returns a reference to the key associated with the point pt. If the point
        // is not in the tree, this function throws an out_of_range exception.
        std::string at(const Point<N>& pt);
        
        //ElemType& at(const Point<N>& pt);
        //const ElemType& at(const Point<N>& pt) const;

        void agregarNodos();

            
        // ElemType& operator[](const Point<N>& pt);
        // Usage: kd[v] = "Some Value";
        // ----------------------------------------------------
        // Returns a reference to the value associated with point pt in the KDTree.
        // If the point does not exist, then it is added to the KDTree using the
        // default value of ElemType as its key.
        //ElemType& operator[](const Point<N>& pt);
        std::string operator[]( Point<N>& pt);

    //    node* getHead();

        // ElemType kNNValue(const Point<N>& key, size_t k) const
        // Usage: cout << kd.kNNValue(v, 3) << endl;
        // ----------------------------------------------------
        // Given a point v and an integer k, finds the k points in the KDTree
        // nearest to v and returns the most common value associated with those
        // points. In the event of a tie, one of the most frequent value will be
        // chosen.
        ElemType  kNNValue(const Point<N>& key,   size_t k) const;
        std::string search(const node *root, const Point<N>& pt, const double &  currentDistance ) const;
     

       std::string showmeAll();
       std::string showmeAll(node *root); 


}; // End class  KDTree






    template <size_t N, typename ElemType>
    ElemType  KDTree< N, ElemType>::kNNValue(const Point<N>& pt,    size_t k) const {
        
        
        // double bestDistance = INFINITY;
        // double temporalDistance =INFINITY ;
         ElemType  result ;

        /*--------------------  SEARCH START CODE -------------------- */

        
            std::cout << " INICIANDO  SEARCH START CODE  -------------------------------------------\n ";
            

          node * nodeRoot =head;
        
         double currentDistance = Distance( pt, nodeRoot->dataPoint  );

        std::string resultado = search(nodeRoot, pt, currentDistance );
        std::cout << "\nEL resultado temporal para el knn-tree es ;" << resultado << std::endl;
         /*--------------------  END SEARCH CODE --------------------  */


        return result;

    }// End kNNValue





    template <size_t N, typename ElemType>
    std::string KDTree< N, ElemType>::search(const node* root,  const Point<N>& pt,  const double & currentDistance ) const
      {

             ElemType result;
            // double currentDistance = distance;

            /*--------------------  STARTING RECURSIVE SEARCH CODE --------------------  */

            std::cout << "\n--------------------  STARTING RECURSIVE SEARCH CODE --------------------  \n";
        
            if(root==NULL){
                // result = root->classification;
                return result;
            }

             std::cout << "\n>voy en el nodo:";
            for (int i =0 ; i< root->dataPoint.size() ; i++) {
                 std::cout << root->dataPoint[i] << ", " ;
            }
            std::cout<<std::endl;
            
            const node *tmp = root;

            // std::stringstream converter;

            // std::stringstream converterA;
            // std::stringstream converterB;
            // std::stringstream converterC;

            std::string miDatoA="";
            std::string miDatoB="";
            std::string miDatoC="";

            std::string miDato="";

            if (tmp->next ==NULL && tmp->before ==NULL)
            {
                std::cout << "\n>ambos son NULL\n";
                
                // for (int i =0 ; i< tmp->dataPoint.size() ; i++) {
                    
                //     std::stringstream converterA;
                //     converterA << tmp->dataPoint[i];
                //     converterA  >>  miDatoA;

                //      miDato += miDatoA + ", ";

                // }

                // converterA << tmp->dataPoint[0];
                // converterA  >>  miDatoA;
                
                // converterB << tmp->dataPoint[1];
                // converterB  >>  miDatoB;
                
                // converterC << tmp->dataPoint[2];
                // converterC  >>  miDatoC;
                
                // miDato = miDatoA + miDatoB + miDatoC;
                // std::stringstream converterClassification;
                //  converterClassification <<tmp->classification;
                //  std::string myClassification = "";
                //  converterClassification >> myClassification;

                //  miDato = miDato + "["+ myClassification +"]";
                    
                    std::stringstream converterA;
                    converterA << tmp->classification;
                    converterA  >>  miDatoA;

                     miDato =  miDatoA + " ";
                return  miDato;

            }



            
            //   for (int i =0 ; i< tmp->dataPoint.size() ; i++) {

            //          std::stringstream converterA;
            //         converterA << tmp->dataPoint[i];
            //         converterA  >>  miDatoA;

            //          miDato +=  miDatoA + ", ";

            //     }
                
                // std::stringstream converterClassification;
                //  converterClassification <<tmp->classification;
                //  std::string myClassification = "";
                //  converterClassification >> myClassification;

                // miDato = miDato + "["+  myClassification  +"]";
            // converterA << tmp->dataPoint[0];
            // converterA  >>  miDatoA;
            // converterB << tmp->dataPoint[1];
            // converterB  >>  miDatoB;
            // converterC << tmp->dataPoint[2];
            // converterC  >>  miDatoC;

           
                     std::stringstream converterA;
                    converterA << tmp->classification;
                    converterA  >>  miDatoA;

                     miDato =  miDatoA + " ";


            if (tmp->next != NULL   &&   tmp->before != NULL)
            {
                
                double distanciaIzquierda =  Distance (pt, tmp->before->dataPoint); 
                double distanciaDerecha   =  Distance (pt, tmp->next->dataPoint);

                std::cout << "\n> Tiene datos en cada rama \n";
                std::cout << ">  DistanciaIzquierda " << distanciaIzquierda << "| DistanciaActual = "  << currentDistance << "|  distanciaDerecha =" <<  distanciaDerecha;

                if (  ( distanciaIzquierda  <  currentDistance )   &&   (distanciaDerecha <  currentDistance) ) 
                {
                   
                    return  search(tmp->before, pt, distanciaIzquierda) + " | "  +  miDato +  " | "+  search(tmp->next, pt, distanciaDerecha );
                
                }
                else if ( (distanciaIzquierda  <  currentDistance )  &&   (distanciaDerecha >  currentDistance) ) 
                {

                    return  search(tmp->before, pt, distanciaIzquierda) + " | "  +  miDato; 
                
                }
                else if ( (distanciaIzquierda  >  currentDistance )  &&   ( distanciaDerecha <  currentDistance ) ) 
                {

                    return  miDato +  " | "+  search(tmp->next, pt, distanciaDerecha );
                
                }

              


               
            }
            else if (tmp->next == NULL && tmp->before != NULL)
            {
                std::cout << "\n> Tiene datos en rama IZQUIERDA \n";
                std::cout<< "Avanzamos por la izquierda independiente de la distancia";
               
                double distanciaIzquierda =  Distance (pt, tmp->before->dataPoint); 
                
                std::cout << ">  DistanciaIzquierda " << distanciaIzquierda << "| DistanciaActual = "  << currentDistance << std::endl;

                if ( (distanciaIzquierda  <  currentDistance)   ) 
                {
                  std::cout<< "Guardamos esta distancia por ser menor que la distancia actual";
                
                }
              
                 return  search(tmp->before, pt, distanciaIzquierda) + " | "  +  miDato; 

            }
            else if (tmp->next != NULL && tmp->before == NULL)
            {
                std::cout << "\n> Tiene datos en rama DERECHA \n"; 
                std::cout<< "Avanzamos por la derecha independiente de la distancia";

                double distanciaDerecha =  Distance (pt, tmp->next->dataPoint); 
               std::cout <<  "| DistanciaActual = "  << currentDistance << "|  distanciaDerecha =" <<  distanciaDerecha <<std::endl;


                if ( (distanciaDerecha  <  currentDistance)   ) 
                {
                  std::cout<< "Guardamos esta distancia por ser menor que la distancia actual"<<std::endl;
                
                }
              
                 return   miDato + " | "  +  search(tmp->next, pt, distanciaDerecha) ;  
                 
            }

             /*--------------------  END RECURSIVE SEARCH CODE --------------------  */

        return miDato;

    }



    // Constructor
    template <size_t N, typename ElemType>
    KDTree< N, ElemType>::KDTree()
    {


        std::cout <<"creating KDTree";

    
        sizeKDTree = 0;
        head=NULL;
        tail=NULL;

    }





    template <size_t N, typename ElemType>
    KDTree< N, ElemType>::~KDTree()
    {
    }




    template <size_t N, typename ElemType>
    void KDTree< N, ElemType>::insert(const Point<N>& pt, const ElemType& value)
    {

            std::cout << " INICIANDO insert -------------------------------------------\n ";
            
            // CREATING New_Node
            node *tmp = new node;
            tmp->data = 0;
            tmp->dataPoint = pt;
            tmp->next   = NULL;
            tmp->before = NULL;
            tmp->classification = value;
            
            // CREATING Node_Tracking for navigate the tree
            node *n_tracking = new node;
            
            // Pointing Node_Tracking to Node_Root
            n_tracking = head;

            // CREATING NODO BACKUP
            node *n_back = new node;
            n_back=NULL;
        

            int indice = 0;
            int indicePoint= indice%N;
            double comparadorComponente ;
            double newPointComponente;



            if (n_tracking!= NULL){

                // SELECTING COMPONENT IN THE FIRST POINT
                comparadorComponente = n_tracking->dataPoint[indicePoint];

                //std::cout << " DEBUGIN add_node 1 -------------------------------------------\n ";
                
                // SELECTING COMPONENT IN THE NEW POINT
                newPointComponente = pt[indicePoint];
            }else{
            // std::cout << " DEBUGIN add_node 2 -------------------------------------------\n ";
                
                // SELECTING COMPONENT ZERO IN THE FIRST POINT
                comparadorComponente =0;
                // SELECTING COMPONENT ZERO IN THE NEW POINT
                newPointComponente =0;
            }
        
        
            // looking for  next position for newData
            while (n_tracking != NULL ){
                
                
                indicePoint= indice % N;
                std::cout << "iterando en :> "<<  n_tracking->dataPoint[indicePoint] << "  indice de Posicion:> "<< indicePoint <<std::endl;
                
                comparadorComponente = n_tracking->dataPoint[indicePoint];
                newPointComponente = pt[indicePoint];
                //comparadorComponente =n_tracking-> data;

                if (newPointComponente >= comparadorComponente) { // RIGHT


                    std::cout << n_tracking-> data << "       -> VAMOS A LA DERECHA *" << std::endl;
                    n_back     = n_tracking;
                    n_tracking = n_tracking->next; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                

                }else  if (newPointComponente < comparadorComponente) { // LEFT

                    std::cout << " * VAMOS A IZQUIERDA  <-  " << n_tracking-> data  << std::endl;
                    n_back     = n_tracking;
                    n_tracking = n_tracking->before; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                
                }

                indice++;

            }//end while

        
            indice--;
            indicePoint = indice%N;
            newPointComponente = pt[indicePoint];

            if( head == NULL ) { // if LL is empty add newNode to Head
                std::cout <<"anadiendo nodo :> "<<   tmp->data  << "  al Nodo ROOT "<< std::endl;

                head = tmp;
                //tail = tmp;

            }else {  // if get to the end of LL then add newNode at the end of the branch
                
            
                if( newPointComponente >= n_back->dataPoint[indicePoint]){
                    
                    std::cout << "anadiendo el Nodo Nuevo -> "<<  tmp->data  << " a la DERECHA "<< std::endl;
                    n_back->next = tmp; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            
                }else{

                    std::cout << tmp->data  << " <-  anadiendo el Nodo Nuevo a la IZQUIERDA "<< std::endl;
                    n_back->before = tmp; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            
                }
            
            
            
                //tail = tail->next;      // REAPUNTANDO tail AL NUEVO NODO
            
            }

            // INCREMENTANDO EL TAMANO DE LOS NODOS
            sizeKDTree++;


    }// End insert()









    template <size_t N, typename ElemType>
    std::string KDTree< N, ElemType>::operator[]( Point<N>& pt) {

            
            std::cout << " INICIANDO Operator[] -------------------------------------------\n ";
            
            // CREATING New_Node
            node *tmp = new node;
            tmp->data = 0;
            tmp->dataPoint = pt;
            tmp->next   = NULL;
            tmp->before = NULL;
            //tmp->classification = value;
            
            // CREATING Node_Tracking
            node *n_tracking = new node;
            
            // Pointing Node_Tracking to Node_Root
            n_tracking = head;

            // CREATING NODO BACKUP
            node *n_back = new node;
            n_back=NULL;
        
            int indice = 0;
            int indicePoint= indice%N;
            double comparadorComponente ;
            double newPointComponente;

            if (n_tracking!= NULL){
                comparadorComponente = n_tracking->dataPoint[indicePoint];

                //std::cout << " DEBUGIN add_node 1 -------------------------------------------\n ";
        
                newPointComponente = pt[indicePoint];
            }else{
            // std::cout << " DEBUGIN add_node 2 -------------------------------------------\n ";
                    comparadorComponente =0;
                newPointComponente =0;
            }
        
        
            // looking for  next position for newData
            while (n_tracking != NULL ){
                
                
                indicePoint= indice%N;
                std::cout << "iterando en :> "<<  n_tracking->dataPoint[indicePoint] << "  indice de Posicion:> "<< indicePoint <<std::endl;
                
                comparadorComponente = n_tracking->dataPoint[indicePoint];
                newPointComponente = pt[indicePoint];
                //comparadorComponente =n_tracking-> data;

                if (newPointComponente > comparadorComponente) { // RIGHT


                    std::cout << n_tracking-> data << "       -> VAMOS A LA DERECHA *" << std::endl;
                    n_back     = n_tracking;
                    n_tracking = n_tracking->next; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                

                }else  if (newPointComponente < comparadorComponente) { // LEFT

                    std::cout << " * VAMOS A IZQUIERDA  <-  " << n_tracking-> data  << std::endl;
                    n_back     = n_tracking;
                    n_tracking = n_tracking->before; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                
                }else if (newPointComponente == comparadorComponente) {
                    if(pt[0] == n_tracking->dataPoint[0]   &&   pt[1] == n_tracking->dataPoint[1]  && pt[2] == n_tracking->dataPoint[2] ) {
                    return "YA EXISTE";

                    }else{
                        // NO ES IGUA? CONTINUAMOS...
                        std::cout << n_tracking-> data << "       -> VAMOS A LA DERECHA *" << std::endl;
                        n_back     = n_tracking;
                        n_tracking = n_tracking->next; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                
                    }
                
                    
                }

                indice++;

            }//end while

        
            // NO EXISTE? ENTONCES AGREGELO 
            indice--;
            indicePoint = indice%N;
            newPointComponente = pt[indicePoint];

            if( head == NULL ) { // if LL is empty add newNode to Head
                std::cout <<"anadiendo nodo :> "<<   tmp->data  << "  al Nodo ROOT "<< std::endl;

                head = tmp;
                //tail = tmp;

            }else {  // if get to the end of LL then add newNode at the end of the branch
                
            
                if( newPointComponente >= n_back->dataPoint[indicePoint]){
                    
                    std::cout << "anadiendo el Nodo Nuevo -> "<<  tmp->data  << " a la DERECHA "<< std::endl;
                    n_back->next = tmp; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            
                }else{

                    std::cout << tmp->data  << " <-  anadiendo el Nodo Nuevo a la IZQUIERDA "<< std::endl;
                    n_back->before = tmp; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            
                }
            
            
            
                //tail = tail->next;      // REAPUNTANDO tail AL NUEVO NODO
            
            }

            // INCREMENTANDO EL TAMANO DE LOS NODOS
            sizeKDTree++;

            return "FUE AGREGADO UN NODO NUEVO";
        
    }// End  operator[]( Point<3>& pt)







    /*
    void KDTree::agregarNodos(){
            
            //    ESTA ES UNA FUNCION SOLO DE PRUEBA QUE DEBE SER BORRADA A FUTURO
            
            std::cout << "\n Agregando Nodos \n" ;

            node *root = new node;

            // root=NULL;
            // head = root;

            if( head == NULL ) { // if LL is empty add newNode to Head
            
                std::cout << "\n Agregando Nodo ROOT \n" ;
                
                root->data = 1;
                root->dataPoint[0] = 1; //<-
                root->dataPoint[1] = 1;
                root->dataPoint[2] = 1;
                root->next=NULL;
                root->before=NULL;

                head = root;
                
            }

        
            //std::cout << showmeAll(root);

            std::cout << "\n Agregando Nodo 2 \n" ;
            node *nodo2 = new node;
            nodo2->data = 2;
            
            nodo2->dataPoint[0] = 2;
            nodo2->dataPoint[1] = 2;//<-
            nodo2->dataPoint[2] = 2;

            nodo2->next   = NULL;
            nodo2->before = NULL;
            root->next= nodo2;



            std::cout << "\n Agregando Nodo 3 \n" ;
            node *nodo3 = new node;
            nodo3->data = 3;
            
            Point<3> ptPrueba ;
            ptPrueba[0] =3;
            ptPrueba[1] =3;
            ptPrueba[2] =3;

            nodo3->dataPoint =ptPrueba;

            nodo3->next   = NULL;
            nodo3->before = NULL;

            nodo2->before = nodo3;


            std::cout << "\n Agregando Nodo 4 \n" ;
            node *nodo4 = new node;
            nodo4->data = 4;

            nodo4->dataPoint[0] = 4;
            nodo4->dataPoint[1] = 4;
            nodo4->dataPoint[2] = 4;//<-

            nodo4->next=NULL;
            nodo4->before=NULL;
            nodo3->next= nodo4;

            std::cout << "\n TERMINANDO DE AGREGAR NODOS 2 \n" ;

        }// End agregarNodos

    */






    // bool contains(const Point<3>& pt) ;//const
    template <size_t N, typename ElemType>
    bool KDTree< N, ElemType>::contains( Point<N>& pt ) //node *root,
    {

            std::cout << "\n>Ingresando a Contains (Node , Point) ---------------------------------------------------------\n";

        
            
            // CREATING Node_Tracking
            node *n_tracking = new node;
            
            // Pointing Node_Tracking to Node_Root
            n_tracking = head;

            // CREATING NODO BACKUP
            node *n_back = new node;
            n_back=NULL;
        
            int indice = 0;
            int indicePoint= indice%N;
            double comparadorComponenteNodo ;
            double comparadorComponentePoint;



            if (n_tracking!= NULL){
                comparadorComponenteNodo = n_tracking->dataPoint[indicePoint];

            
                comparadorComponentePoint = pt[indicePoint];
            }else{
            
                    comparadorComponenteNodo =0;
                comparadorComponentePoint =0;
            }
        
        
            // looking for  next position for newData
            while (n_tracking != NULL ){
                
                
                indicePoint= indice%N;
                std::cout << "iterando en :> "<<  n_tracking->dataPoint[indicePoint] << "  Indice General "<< indice <<"  indice de Posicion Point:> "<< indicePoint <<std::endl;
                

                comparadorComponenteNodo  =  n_tracking->dataPoint[indicePoint];
                comparadorComponentePoint =  pt[indicePoint];

              std::cout << "comparadorComponenteNodo = " <<comparadorComponenteNodo << "  comparadorComponentePoint ="<< comparadorComponentePoint << std::endl;
                if (comparadorComponentePoint > comparadorComponenteNodo) { // RIGHT

                
                        std::cout << n_tracking-> data << "       -> VAMOS A LA DERECHA *" << std::endl;
                        n_back     = n_tracking;
                        n_tracking = n_tracking->next; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                


                }else  if (comparadorComponentePoint < comparadorComponenteNodo) { // LEFT

                    std::cout << " * VAMOS A IZQUIERDA  <-  " << n_tracking-> data  << std::endl;
                    n_back     = n_tracking;
                    n_tracking = n_tracking->before; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                

                }else if (comparadorComponentePoint == comparadorComponenteNodo) { // RIGHT

                   
                std::cout << " SI LO ENCONTRE, vamos a revizar todos los puntos "<< std::endl;
                // std::cout << "pt[0] = " <<pt[0] << "   n_tracking->dataPoint[0]= "<<  n_tracking->dataPoint[0] <<std::endl;
                // std::cout << "pt[1] = " <<pt[1] << "   n_tracking->dataPoint[1]= "<<  n_tracking->dataPoint[1] <<std::endl; 
               
                    if(pt[0] == n_tracking->dataPoint[0]   &&   pt[1] == n_tracking->dataPoint[1]  && pt[2] == n_tracking->dataPoint[2] ) {
                          std::cout << " SI LO ENCONTRE "<< std::endl;
                        return true;
                    }else{
                        
                        std::cout << n_tracking-> data << "       -> VAMOS A LA DERECHA *" << std::endl;
                        n_back     = n_tracking;
                        n_tracking = n_tracking->next; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                
                    }
                
                }


                indice++;

            }//end while


            return false;

    } // End contains
        







    template <size_t N, typename ElemType>
    std::string KDTree< N, ElemType>::at(const Point<N>& pt)
    {


            std::cout << "\n>Ingresando a at (Node , Point) ---------------------------------------------------------\n";


            
            // CREATING Node_Tracking
            node *n_tracking = new node;
            
            // Pointing Node_Tracking to Node_Root
            n_tracking = head;

            // CREATING NODO BACKUP
            node *n_back = new node;
            n_back=NULL;
        
            int indice = 0;
            int indicePoint= indice%N;
            double comparadorComponenteNodo ;
            double comparadorComponentePoint;



            if (n_tracking!= NULL){
                comparadorComponenteNodo = n_tracking->dataPoint[indicePoint];

                
                comparadorComponentePoint = pt[indicePoint];
            }else{
                    comparadorComponenteNodo =0;
                comparadorComponentePoint =0;
            }
        
        
            // looking for  next position for newData
            while (n_tracking != NULL ){
                
                
                indicePoint= indice%N;
                std::cout << "iterando en :> "<<  n_tracking->dataPoint[indicePoint] << "Indice General "<< indice <<"  indice de Posicion Point:> "<< indicePoint <<std::endl;
                

                comparadorComponenteNodo  =  n_tracking->dataPoint[indicePoint];
                comparadorComponentePoint =  pt[indicePoint];
        

                if (comparadorComponentePoint > comparadorComponenteNodo) { // RIGHT

                
                        std::cout << n_tracking-> data << "       -> VAMOS A LA DERECHA *" << std::endl;
                        n_back     = n_tracking;
                        n_tracking = n_tracking->next; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                    

                
                

                }else  if (comparadorComponentePoint < comparadorComponenteNodo) { // LEFT

                    std::cout << " * VAMOS A IZQUIERDA  <-  " << n_tracking-> data  << std::endl;
                    n_back     = n_tracking;
                    n_tracking = n_tracking->before; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                

                }else if (comparadorComponentePoint == comparadorComponenteNodo) { // RIGHT


                    if(pt[0] == n_tracking->dataPoint[0]   &&   pt[1] == n_tracking->dataPoint[1]  && pt[2] == n_tracking->dataPoint[2] ) {
                        return " REFERENCIA DENTRO DEL NODO ";
                    
                    }else{
                        
                        std::cout << n_tracking-> data << "       -> VAMOS A LA DERECHA *" << std::endl;
                        n_back     = n_tracking;
                        n_tracking = n_tracking->next; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                
                    }
                
                }


                indice++;

            }//end while


            return "ERROR ";

    } // End at(const Point<3>& pt)






    template <size_t N, typename ElemType>
    size_t KDTree< N, ElemType>::size() const {
        return sizeKDTree;
    }

    template <size_t N, typename ElemType>
    bool KDTree< N, ElemType>::empty() const{
    return  (sizeKDTree==0)? true : false;
    }





    template <size_t N, typename ElemType>
    std::string KDTree< N, ElemType>::showmeAll() 
    {
            
            node *root = new node;

            root = head ;// getHead();
            
            std::cout  << "\n>ESTAMOS EN showmeAll() *" << std::endl;
            return showmeAll(root);
    }



    template <size_t N, typename ElemType>
    std::string KDTree< N, ElemType>::showmeAll(node *root) 
    {
        

            std::cout << "\n>Ingresando a showmeALL(Node) \n";
        
            if(root==NULL){
                return "";
            }
            std::cout << "\n>voy en el nodo: "<< root->data <<"\n";
            
            node *tmp = root;

            // std::stringstream converter;

            // std::stringstream converterA;
            // std::stringstream converterB;
            // std::stringstream converterC;

            std::string miDatoA="";
            std::string miDatoB="";
            std::string miDatoC="";

            std::string miDato="";

            if (tmp->next ==NULL && tmp->before ==NULL)
            {
                std::cout << "\n>ambos son NULL\n";
                
                for (int i =0 ; i< tmp->dataPoint.size() ; i++) {
                    
                    std::stringstream converterA;
                    converterA << tmp->dataPoint[i];
                    converterA  >>  miDatoA;

                     miDato += miDatoA + ", ";

                }

                // converterA << tmp->dataPoint[0];
                // converterA  >>  miDatoA;
                
                // converterB << tmp->dataPoint[1];
                // converterB  >>  miDatoB;
                
                // converterC << tmp->dataPoint[2];
                // converterC  >>  miDatoC;
                
                // miDato = miDatoA + miDatoB + miDatoC;
                std::stringstream converterClassification;
                 converterClassification <<tmp->classification;
                 std::string myClassification = "";
                 converterClassification >> myClassification;

                 miDato = miDato + "["+ myClassification +"]";
                return  miDato;
            }
            
              for (int i =0 ; i< tmp->dataPoint.size() ; i++) {

                     std::stringstream converterA;
                    converterA << tmp->dataPoint[i];
                    converterA  >>  miDatoA;

                     miDato +=  miDatoA + ", ";

                }
                
                std::stringstream converterClassification;
                 converterClassification <<tmp->classification;
                 std::string myClassification = "";
                 converterClassification >> myClassification;

                miDato = miDato + "["+  myClassification  +"]";
            // converterA << tmp->dataPoint[0];
            // converterA  >>  miDatoA;
            // converterB << tmp->dataPoint[1];
            // converterB  >>  miDatoB;
            // converterC << tmp->dataPoint[2];
            // converterC  >>  miDatoC;

            // miDato = miDatoA + miDatoB + miDatoC;


            if (tmp->next != NULL   &&   tmp->before != NULL)
            {
                std::cout << "\n> Tiene datos en cada rama \n";
                return  showmeAll(tmp->before) + " | "  +  miDato +  " | "+showmeAll(tmp->next);
            }
            else if (tmp->next == NULL && tmp->before != NULL)
            {
                std::cout << "\n> Tiene datos en rama IZQUIERDA \n";
                return    showmeAll(tmp->before)+" | "+ miDato ;
            }
            else if (tmp->next != NULL && tmp->before == NULL)
            {
                std::cout << "\n> Tiene datos en rama DERECHA \n";
                return miDato +" | " + showmeAll(tmp->next)    ;
            }

            return "";


    } // End showmeAll
        


#endif // KDTREE_INCLUDED

