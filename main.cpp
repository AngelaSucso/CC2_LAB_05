#include <iostream>
using namespace std;

class Node{
private:
    int elem;
    Node * next;
public:
    //la clase lista esta muy relacionada con la clase node por eso amerita usar friend class
    Node(int);
    Node(Node &);
    friend class LinkedList;
    friend class Iterator;
};

Node::Node(int elem){           //cons
    this->elem=elem;
    next=nullptr;
}

Node::Node(Node &o){            //copia
    elem=o.elem;
    next=o.next;
}

class LinkedList{
private:
    int size;
    Node * head;
public:
    LinkedList();
    ~LinkedList();
    LinkedList(LinkedList &);
    void insert(int);                       //funcion insertar
    void print();                           //funcion imprimir
    void remove(int);                       //funcion remover
};

LinkedList::LinkedList(){                   //constr
    size=0;
    head=nullptr;
}

LinkedList::LinkedList(LinkedList &lista){  //copia
    size=lista.size;
    head=lista.head;
}

LinkedList::~LinkedList(){                  //destructor
    Node *aux;
    while(head != nullptr){

       aux = head->next;                    //Guardando la posicion del nodo siguiente
       delete head;                         //Borrando lo que hay en la posicion de head
       head = aux;                          //Head apunta al siguiente del Head anterior
    }
    cout<<endl<<"Destructor";
};

void LinkedList::insert(int valor){         //funcion imprimir
    Node *nuevo_N=new Node(valor);           //creamos un puntero nuevo nodo

    if(head==nullptr){                      //si el head es apunta a nulo
        head=nuevo_N;                        //head apuntara los mismo que apunta nuevo nodo
    }
    else{
        Node *pos = head;                   //*pos se iguala a lo que apunta head, un nodo
        while(pos->next!=nullptr){          //pos ingresa al atributo next del nodo y este no apunta a nulo
            pos=pos->next;                  //pos apuntara a lo que apunta el atributo next
        }
        pos->next=nuevo_N;                   //si next apunta a nulo, pos apuntara al nuevo nodo
    }
}

void LinkedList::print(){                   //funcion imprimir
    Node *pos=head;                         //*pos apunta a lo que head
    while(pos->next!=nullptr){              //*pos en al atributo next no apunta a nulo
        cout<<pos->elem<<" ";               //ingresara al nodo e imprimira el atributo elem
        pos=pos->next;                      //e ingresara al atributo next para apuntar al siguiente nodo
    }
    cout<<pos->elem;                        //al ser el ultimo nodo imprimira el atributo elem del nodo
}

void LinkedList::remove(int valor){
    if(head==nullptr){
        cout<<"Estas bobo o que?";
    }
    else{
        Node *temp=new Node(0);                         //nodo temporal
        temp->next=head;                                //estara antes del head
        Node *aux1=head;
        Node *aux2=temp;
        cout<<endl;
        while(aux1!=nullptr && aux1->elem!=valor){      //desplazamiento hasta que encuentre el valor
            aux1=aux1->next;                            //o se termina la lista
            aux2=aux2->next;
        }
        if(aux1==nullptr){
            cout<<"El elemento no esta en la lista"<<endl;      //al desplazar no encuentra el valor
        }
        else{
            aux2->next=aux1->next;                              //elimina el nodo
            if(head==aux1){                                     //cuando el head apunta al
                head=head->next;                                //nodo a eliminar
            }
            delete aux1;                                        //elimina nodo requerido
        }
        delete temp;                                            //elimina nodo temporal
    }
}

int main(){
    LinkedList lista;
    lista.insert(1);
    lista.insert(2);
    lista.insert(3);
    lista.insert(4);
    lista.insert(5);
    lista.insert(6);
    lista.insert(7);
    lista.insert(8);
    lista.insert(9);
    lista.insert(10);
    lista.print();
    lista.remove(3);
    lista.print();
    lista.remove(1);
    lista.print();

    return 0;
}
