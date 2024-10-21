#include <iostream>

using namespace std;

template<typename T>
class Nodo {
    T dato;
    Nodo* next;

public:
    Nodo(T dato, Nodo* next) : dato(dato), next(next) {}

    T getDato() {
        return dato;
    }

    void setDato(T dato) {
        this->dato = dato;
    }

    Nodo* getNext() {
        return next;
    }

    void setNext(Nodo* next) {
        this->next = next;
    }
};

template<typename T>
class ListaCircular {
    Nodo<T>* head;
    int size;

public:
    ListaCircular() : head(nullptr), size(0) {}

    int getSize() {
        return size;
    }

    Nodo<T>* getHead() {
        return head;
    }

    void agregarInicio(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor, head);
        if (!head) {
            head = nuevo;
            nuevo->setNext(head); // Apunta a sí mismo
        } else {
            Nodo<T>* current = head;
            while (current->getNext() != head) {
                current = current->getNext();
            }
            current->setNext(nuevo);
            nuevo->setNext(head);
            head = nuevo;
        }
        size++;
    }

    void agregarFinal(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor, nullptr);
        if (!head) {
            head = nuevo;
            nuevo->setNext(head); // Apunta a sí mismo
        } else {
            Nodo<T>* current = head;
            while (current->getNext() != head) {
                current = current->getNext();
            }
            current->setNext(nuevo);
            nuevo->setNext(head);
        }
        size++;
    }

    void agregarPorIndice(int indice, T valor) {
        if (indice < 0 || indice > size) {
            cout << "Índice fuera de rango." << endl;
            return;
        }

        if (indice == 0) {
            agregarInicio(valor);
        } else if (indice == size) {
            agregarFinal(valor);
        } else {
            Nodo<T>* current = head;
            for (int i = 0; i < indice - 1; i++) {
                current = current->getNext();
            }
            Nodo<T>* nuevo = new Nodo<T>(valor, current->getNext());
            current->setNext(nuevo);
        }
        size++;
    }

    void mostrarLista() {
        if (!head) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo<T>* current = head;
        do {
            cout << current->getDato() << " -> ";
            current = current->getNext();
        } while (current != head);
        cout << "(de vuelta al inicio)" << endl;
    }
};

int main() {
    ListaCircular<int> lista;
    lista.agregarInicio(10);
    lista.agregarFinal(20);
    lista.agregarPorIndice(1, 15);

    lista.mostrarLista(); // Salida: 10 -> 15 -> 20 -> (de vuelta al inicio)

    return 0;
}
