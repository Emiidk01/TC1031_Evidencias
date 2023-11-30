/*
Autor: Emiliano Gomez Gonzalez
Catalogo de peliculas
Algoritmos y Estructuras de Datos
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <unordered_set>
using namespace std;

struct Nodo {
    string dato;
    Nodo *siguiente;

    // Constructor por omision
    Nodo() : dato(""), siguiente(nullptr) {}

    // Constructor para facilitar la creacion de nodos
    Nodo(string valor) : dato(valor), siguiente(nullptr) {}
};

// Prototipos de funciones
void menu();
void insertarLista(Nodo *&, string);
void cargarDesdeArchivo(const string&, const string&, Nodo*&);
void imprimirLista(Nodo*);
void buscarLista(Nodo*, string);
void merge(Nodo*&, Nodo*, Nodo*);
void mergeSort(Nodo*&);
void eliminarTodasPeliculas(Nodo*&);
int contarElementos(Nodo*);
void partirLista(Nodo*, Nodo*&, Nodo*&);


int main() {
    menu();

    getch();
    return 0;
}

// Funcion menu
void menu() {
    int opc;
    string dato;

    Nodo* lista = nullptr;

    do {
        cout << "\t.:MENU:.\n";
        cout << "1. Ingresar pelicula al catalogo" << endl;
        cout << "2. Cargar archivo del catalogo de peliculas a la lista" << endl;
        cout << "3. Mostrar catalogo de peliculas (debes cargar peliculas antes)" << endl;
        cout << "4. Consultar (buscar) una pelicula en la lista" << endl;
        cout << "5. Ordenar peliculas" << endl;
        cout << "6. Eliminar todas las peliculas" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "\nIngrese el nombre de la pelicula: ";
                cin >> dato;
                insertarLista(lista, dato);
                cout << "\n¡Pelicula agregada exitosamente!";
                break;
            case 2:
                cout << "\nCargando el catalogo de peliculas...\n";
                cargarDesdeArchivo("peliculas.txt", "datos.txt", lista);
                cout << "Las peliculas se han cargado exitosamente en datos.txt.";
                cout << "\n";
                system("pause");
                break;
            case 3:
                cout << "\nMostrando el catalogo de peliculas:\n";
                imprimirLista(lista);
                cout << "\n";
                system("pause");
                break;
            case 4:
                cout << "\nIngrese el nombre de la pelicula a buscar: ";
                cin >> dato;
                buscarLista(lista, dato);
                cout << "\n";
                system("pause");
                break;
            case 5:
                cout << "\nOrdenando el catalogo de peliculas:\n";
                mergeSort(lista);
                cout << "Catalogo de peliculas ordenado.\n";
                cout << "\n";
                system("pause");
                break;
            case 6:
                cout << "\nEliminando todas las peliculas: \n";
                eliminarTodasPeliculas(lista);
                cout << "Todas las peliculas han sido eliminadas.\n";
                cout << "\n";
                system("pause");
                break;
            case 7:
                cout << "\nSaliendo...";
                cout << "\n";
                system("pause");
                break;
        }
        system("cls");
    } while (opc != 7);
}

// Funcion para insertar elemenetos en la lista
void insertarLista(Nodo*& lista, string n) {
    // Verificar si la pelicula ya existe en la lista
    Nodo* actual = lista;
    unordered_set<string> peliculasSet;
    bool existe = false;

    while (actual != nullptr) {
        peliculasSet.insert(actual->dato);
        if (actual->dato == n) {
            existe = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!existe) {
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = n;

        Nodo* aux1 = lista;
        Nodo* aux2;

        while ((aux1 != nullptr) && (aux1->dato < n)) {
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        if (lista == aux1) {
            lista = nuevo_nodo;
        } else {
            aux2->siguiente = nuevo_nodo;
        }
        nuevo_nodo->siguiente = aux1;

        // Agregar la pelicula al archivo "datos.txt"
        ofstream archivo("datos.txt", ios::app);
        if (archivo.is_open()) {
            archivo << n << endl;
            archivo.close();
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
    } else {
        cout << "La pelicula ya existe en el catalogo." << endl;
        system("pause");
    }
}

// Funcion para cargar datos desde el archivo de texto a la lista
void cargarDesdeArchivo(const string& nombreArchivoEntrada, const string& nombreArchivoSalida, Nodo*& lista) {
    ifstream archivoEntrada(nombreArchivoEntrada);

    if (archivoEntrada.is_open()) {
        string pelicula;
        while (getline(archivoEntrada, pelicula)) {
            // Crear un nuevo nodo con la pelicula leída
            Nodo* nuevoNodo = new Nodo(pelicula);

            // Enlazar el nuevo nodo al frente de la lista
            nuevoNodo->siguiente = lista;
            lista = nuevoNodo;
        }

        archivoEntrada.close();

        // Guardar la lista en el archivo de salida (datos.txt)
        ofstream archivoSalida(nombreArchivoSalida);
        Nodo* temp = lista;
        unordered_set<string> peliculasSet;

        while (temp != nullptr) {
            peliculasSet.insert(temp->dato);
            archivoSalida << temp->dato << endl;
            temp = temp->siguiente;
        }
        archivoSalida.close();

        // Limpiar la lista actual para evitar duplicados
        eliminarTodasPeliculas(lista);

        // Reconstruir la lista desde el archivo
        for (const string& pelicula : peliculasSet) {
            insertarLista(lista, pelicula);
        }
    } else {
        cout << "No se pudo abrir el archivo de entrada." << endl;
    }
}

// Funcion para imprimir la lista
void imprimirLista(Nodo* lista) {
    while (lista != nullptr) {
        cout << lista->dato << endl;
        lista = lista->siguiente;
    }
}

// Funcion para buscar una pelicula en la lista
void buscarLista(Nodo* lista, string nombrePelicula) {
    Nodo* actual = lista;
    bool bandera = false;

    while (actual != nullptr) {
        if (actual->dato == nombrePelicula) {
            bandera = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (bandera) {
        cout << "La pelicula " << nombrePelicula << " SI se encuentra en el catalogo." << endl;
    } else {
        cout << "La pelicula " << nombrePelicula << " NO se encuentra en el catalogo." << endl;
    }
}

void merge(Nodo*& lista, Nodo* izquierda, Nodo* derecha) {
    Nodo* resultado = nullptr;
    unordered_set<string> elementosInsertados;

    while (izquierda != nullptr && derecha != nullptr) {
        if (izquierda->dato < derecha->dato) {
            if (elementosInsertados.find(izquierda->dato) == elementosInsertados.end()) {
                insertarLista(resultado, izquierda->dato);
                elementosInsertados.insert(izquierda->dato);
            }
            izquierda = izquierda->siguiente;
        } else if (derecha->dato < izquierda->dato) {
            if (elementosInsertados.find(derecha->dato) == elementosInsertados.end()) {
                insertarLista(resultado, derecha->dato);
                elementosInsertados.insert(derecha->dato);
            }
            derecha = derecha->siguiente;
        } else {
            // Ambos elementos son iguales, insertar solo uno y avanzar ambos
            if (elementosInsertados.find(izquierda->dato) == elementosInsertados.end()) {
                insertarLista(resultado, izquierda->dato);
                elementosInsertados.insert(izquierda->dato);
            }
            izquierda = izquierda->siguiente;
            derecha = derecha->siguiente;
        }
    }

    // Agregar los elementos restantes, si los hay
    while (izquierda != nullptr) {
        if (elementosInsertados.find(izquierda->dato) == elementosInsertados.end()) {
            insertarLista(resultado, izquierda->dato);
            elementosInsertados.insert(izquierda->dato);
        }
        izquierda = izquierda->siguiente;
    }

    while (derecha != nullptr) {
        if (elementosInsertados.find(derecha->dato) == elementosInsertados.end()) {
            insertarLista(resultado, derecha->dato);
            elementosInsertados.insert(derecha->dato);
        }
        derecha = derecha->siguiente;
    }

    // Actualizamos la lista original con la lista ordenada
    lista = resultado;
}

void mergeSort(Nodo*& lista) {
    if (lista == nullptr || lista->siguiente == nullptr) {
        return;
    }

    // Dividimos la lista en dos mitades
    Nodo* izquierda = nullptr;
    Nodo* derecha = nullptr;
    partirLista(lista, izquierda, derecha);

    // Recursivamente ordenamos las dos mitades
    mergeSort(izquierda);
    mergeSort(derecha);

    // Limpiamos la lista original antes de fusionar
    eliminarTodasPeliculas(lista);

    // Hacemos el merge de las dos mitades ya ordenadas
    merge(lista, izquierda, derecha);
}


// Añade esta función para contar elementos en la lista
int contarElementos(Nodo* lista) {
    int contador = 0;
    while (lista != nullptr) {
        contador++;
        lista = lista->siguiente;
    }
    return contador;
}

// Modifica la función partirLista para que use contarElementos
void partirLista(Nodo* lista, Nodo*& izquierda, Nodo*& derecha) {
    int len = contarElementos(lista);
    int middle = len / 2;

    Nodo* temp = lista;

    for (int i = 0; i < middle; ++i) {
        insertarLista(izquierda, temp->dato);
        temp = temp->siguiente;
    }

    while (temp != nullptr) {
        insertarLista(derecha, temp->dato);
        temp = temp->siguiente;
    }
}


// Fucnion para eliminar las peliculas
void eliminarTodasPeliculas(Nodo*& lista) {
    // Eliminar nodos de la lista
    while (lista != nullptr) {
        Nodo* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }

    // Abrir el archivo para borrar su contenido
    ofstream archivo("datos.txt", ios::trunc);
    archivo.close();
}
