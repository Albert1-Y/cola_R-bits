//
//  main.cpp
//  cola_R-bits
//
//  Created by Albert Yerem Caceres Marca on 15/04/23.
//

#include <iostream>

using namespace std;

class cola
{
    int A[10];
    int* Inicio = A;
    int* Fin = A + 9;
    int* Head = nullptr;
    int* Tail = nullptr;
    bool can = true;

  public:

    void print()
    {
        for (int n = 0; n<10; n++)
            cout << A[n] << "-";
        cout << endl;
    }

    void Push(int n)
    {
        if (Head)
        {
            if (Tail < Fin && can)
            {
                Tail++;
                *Tail = n;
            }
            else if (Tail >= Inicio && Tail < Head - 1)
            {
                Tail++;
                *Tail = n;
                can = false;
            }
            else
            {
                if (Tail == Fin)
                {
                    Tail = Inicio;
                    *Tail = n;
                    can = false;
                }
                else
                    cout << "Cola llena" << endl;
            }
        }
        else
        {
            Head = Inicio;
            Tail = Inicio;
            *Tail = n;
        }
    }

    int Pop()
    {
        int tmp = 0;
        if (Head)
        {
            tmp = *Head;
            if (Head == Tail)
            {
                Head = nullptr;
                Tail = nullptr;
            }
            else if (Head == Fin)
            {
                Head = Inicio;
            }
            else
            {
                Head++;
            }
        }
        else
            cout << "COLA VACÍA" << endl;
        
        return tmp;
    }


};

int main()
{
    cola Queue;

    cout << "Prueba de llenado de Cola" << endl;
        for (int i = 1; i < 9; i++)
            Queue.Push(i);
            
        Queue.Pop();
        Queue.Pop();
        Queue.Pop();
        Queue.Push(23);
        Queue.Push(26);
        Queue.Push(25);
        Queue.Push(29);
        Queue.Push(44);
        Queue.Push(55);
        Queue.Push(66);
        Queue.Push(77);
        
        for (int i = 1; i < 13; i++)
            Queue.Pop();
        
        
        
        return 0;
}

