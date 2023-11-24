/*
Proyecto: Catalogo de peliculas
Avance 03
Autor: Emiliano Gomez Gonzalez
Fecha: 10/11/23
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct Nodo{
    string dato;
    Nodo *siguiente;

    // Constructor por omisión
    Nodo() : dato(""), siguiente(nullptr) {}

    // Constructor para facilitar la creación de nodos
    Nodo(string valor) : dato(valor), siguiente(nullptr) {}
};

// Prototipos de funciones
void menu();
void insertarLista(Nodo *&, string);
void cargarDesdeArchivo(const string&, Nodo*&);
void imprimirLista(Nodo*);
void buscarLista(Nodo *, string);
void merge(Nodo *&, Nodo *, Nodo *);
void mergeSort(Nodo *&);
void eliminarTodasPeliculas(Nodo *&);

int main(){
    menu();


    return 0;
}

// Funcion menu
void menu(){
    int opc;
    string dato;

    Nodo *lista = NULL;

    do{
        cout<<"\t.:MENU:.\n";
        cout<<"1. Ingresar pelicula al catalogo"<<endl;
        cout<<"2. Cargar archivo del catalogo de peliculas a la lista"<<endl;
        cout<<"3. Mostrar catalogo de peliculas (debes cargar peliculas antes)"<<endl;
        cout<<"4. Consultar (buscar) una pelicula en la lista"<<endl;
        cout<<"5. Ordenar peliculas"<<endl;
        cout<<"6. Eliminar todas las pelicula"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opc;

        switch(opc){
            case 1: 
                cout<<"\nIngrese el nombre de la pelicula: ";
                cin>>dato;
                insertarLista(lista,dato);
                cout<<"\n¡Pelicula agregada exitosamente!";
                break;
            case 2: 
                cout<<"\nCargando el catalogo de peliculas...\n";
                cargarDesdeArchivo("peliculas.txt",lista);
                cout<<"Las peliculas se han cargado exitosamente.";
                cout<<"\n";
                system("pause");
                break;
            case 3:
                cout<<"\nMostrando el catalogo de peliculas:\n";
                imprimirLista(lista);
                cout<<"\n";
                system("pause");
                break;
            case 4:
                cout<<"\nIngrese el nombre de la pelicula a buscar: ";
                cin>>dato;
                buscarLista(lista,dato);
                cout << "\n";
                system("pause");
                break;
            case 5: 
                cout<<"\nOrdenando el catalogo de peliculas:\n";
                mergeSort(lista);
                cout<<"Catalogo de peliculas ordenado.\n";
                cout<<"\n";
                system("pause");
                break;
            case 6: 
                cout<<"\nEliminando todas las peliculas: \n";
                eliminarTodasPeliculas(lista);
                cout<<"Todas las peliculas han sido eliminadas.\n";
                cout<<"\n";
                system("pause");
                break;
            case 7:
                cout<<"\nSaliendo...";
                cout<<"\n";
                system("pause");
                break;
        }
        system("cls");
    }while(opc != 7);
}


// Funcion para insertar elemenetos en la lista
void insertarLista(Nodo *&lista, string n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != nullptr) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if(lista == aux1){
        lista = nuevo_nodo;
    }
    else{
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;

    // Agregar la pelicula al archivo "peliculas.txt"
    ofstream archivo("peliculas.txt", ios::app);
    if (archivo.is_open()) {
        archivo << n << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}


// Funcion para cargar datos desde el archivo de texto a la lista
void cargarDesdeArchivo(const string &nombreArchivo, Nodo *&lista) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string pelicula;
        while (getline(archivo, pelicula)) {
            // Crear un nuevo nodo con la pelicula leIda
            Nodo* nuevoNodo = new Nodo(pelicula);

            // Enlazar el nuevo nodo al frente de la lista
            nuevoNodo->siguiente = lista;
            lista = nuevoNodo;
        }

        archivo.close();
    } else {
        cout<<"No se pudo abrir el archivo."<<endl;
    }
}

// Funcion para imprimir la lista
void imprimirLista(Nodo *lista) {
    while (lista != nullptr) {
        cout<<lista->dato<<endl;
        lista = lista->siguiente;
    }
}

// Funcion para buscar una pelicula en la lista
void buscarLista(Nodo *lista, string nombrePelicula){
    Nodo *actual = lista;
    bool bandera = false;

    while (actual != nullptr) {
        if (actual->dato == nombrePelicula) {
            bandera = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (bandera) {
        cout<<"La pelicula "<<nombrePelicula<<" SI se encuentra en el catalogo."<<endl;
    } else {
        cout<<"La pelicula "<<nombrePelicula<<" NO se encuentra en el catalogo."<<endl;
    }
}


// Funcion para realizar el merge de los subarreglos
void merge(Nodo *&lista, Nodo *izquierda, Nodo *derecha){
    Nodo *resultado = nullptr;

    while (izquierda != nullptr && derecha != nullptr) {
        if (izquierda->dato < derecha->dato) {
            insertarLista(resultado, izquierda->dato);
            izquierda = izquierda->siguiente;
        } else {
            insertarLista(resultado, derecha->dato);
            derecha = derecha->siguiente;
        }
    }

    while (izquierda != nullptr) {
        insertarLista(resultado, izquierda->dato);
        izquierda = izquierda->siguiente;
    }

    while (derecha != nullptr) {
        insertarLista(resultado, derecha->dato);
        derecha = derecha->siguiente;
    }

    // Actualizamos la lista original con la lista ordenada
    lista = resultado;
}


// Funcion para realizar el merge sort
void mergeSort(Nodo *&lista){
    if (lista == nullptr || lista->siguiente == nullptr) {
        return;
    }

    // Dividimos la lista en dos mitades
    Nodo *izquierda = nullptr;
    Nodo *derecha = nullptr;
    Nodo *temp = lista;

    int len = 0;
    while (temp != nullptr) {
        len++;
        temp = temp->siguiente;
    }

    int middle = len / 2;
    int i = 0;

    temp = lista;
    while (temp != nullptr) {
        if (i < middle) {
            insertarLista(izquierda, temp->dato);
        } else {
            insertarLista(derecha, temp->dato);
        }

        temp = temp->siguiente;
        i++;
    }

    // Recursivamente ordenamos las dos mitades
    mergeSort(izquierda);
    mergeSort(derecha);

    // Hacemos el merge de las dos mitades ya ordenadas
    merge(lista, izquierda, derecha);
}

// Fucnion para eliminar las peliculas
void eliminarTodasPeliculas(Nodo *&lista){
    // Eliminar nodos de la lista
    while (lista != nullptr) {
        Nodo *temp = lista;
        lista = lista->siguiente;
        delete temp;
    }

    // Abrir el archivo  para borrar su contenido
    ofstream archivo("peliculas.txt", ios::trunc);
    archivo.close();
}