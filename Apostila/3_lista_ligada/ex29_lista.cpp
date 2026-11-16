/*
29. SUPONHA QUE LISTA SEJA UMA FILA DE PRIORIDADE ASCENDENTE, IMPLEMENTADA DO
FORMA CIRCULAR. ESCREVA UMA SEQUÊNCIA DE COMANDOS PARA ELIMINAR UM ELEMENTO
DA LISTA.
*/

//biblioteca
#include <iostream>
#include <list> //necessario para lista

using namespace std;

void insere(list<int> &lista, int x)
{
    list<int>::iterator p;

    for(p = lista.begin(); p != lista.end(); p++)
    {
        if(*p >= x)
        {
            lista.insert(p, x);
            return;
        }
    }
    lista.push_back(x);
}

//função - elimina o elemento de maior prioridade
bool elimina(list<int> &lista, int &removido)
{
    if(lista.empty())
    {
        return false;
    }

    //fila de prioridade
    removido = lista.front();
    lista.pop_front();
    return true;
}

//função auxiliar
void imprimir(list<int> &lista)
{
    if(lista.empty())
    {
        cout << "[Vazia]";
    }
    else
    {
        list<int>::iterator p;
        for(p = lista.begin(); p != lista.end(); p++)
        {
            cout << *p << " ";
        }
    }
    cout << endl;
}
int main()
{
    //declaração de variáveis
    list<int> fila;
    int quantidades, numero, auxiliar;

    //entrada de dados
    cout << "Quantidades: ";
    cin >> quantidades;

    for(int i = 0; i < quantidades; i++)
    {
        cin >> ws;
        cin >> numero;
        insere(fila, numero);
    }

    imprimir(fila);

    while(!fila.empty())
    {
        if(elimina(fila, auxiliar))
        {
            cout << "Removido: " << auxiliar << endl;
            cout << "Fila restante: ";
            imprimir(fila);
        }
    }
    return 0;
}