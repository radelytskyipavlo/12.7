#include <iostream>
#include <fstream>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
void printList(Elem* L);
void removeEven(Elem*& L);
void doubleOddIndexValues(Elem* L);
void insertSublist(Elem*& L, int position, Info sublist[], int sublistSize);

int main()
{
    Elem* first = NULL;
    Elem* last = NULL;

    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    Info value;
    while (inputFile >> value) {
        enqueue(first, last, value);
    }
    inputFile.close();

    cout << "Input list:" << endl;
    printList(first);

    removeEven(first);
    cout << "List after removing even values:" << endl;
    printList(first);

    doubleOddIndexValues(first);
    cout << "List after doubling values with odd indices:" << endl;
    printList(first);

    Info sublist[] = { 10, 20, 30 }; 
    insertSublist(first, 2, sublist, sizeof(sublist) / sizeof(sublist[0]));
    cout << "List after inserting sublist at position 2:" << endl;
    printList(first);

    return 0;
}

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void printList(Elem* L)
{
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->link;
    }
    cout << endl;
}

void removeEven(Elem*& L)
{
    Elem* prev = NULL;
    Elem* current = L;

    while (current != NULL)
    {
        if (current->info % 2 == 0)
        {
            if (prev == NULL) 
                L = current->link;
            else
                prev->link = current->link;

            Elem* next = current->link;
            delete current;
            current = next;
        }
        else
        {
            prev = current;
            current = current->link;
        }
    }
}

void doubleOddIndexValues(Elem* L)
{
    int index = 1;
    while (L != NULL)
    {
        if (index % 2 != 0)
            L->info *= 2;

        L = L->link;
        index++;
    }
}

void insertSublist(Elem*& L, int position, Info sublist[], int sublistSize)
{
    Elem* current = L;
    int index = 1;

    while (current != NULL && index < position)
    {
        current = current->link;
        index++;
    }

    if (current == NULL)
        return; 

    for (int i = 0; i < sublistSize; i++)
    {
        Elem* newNode = new Elem;
        newNode->info = sublist[i];
        newNode->link = current->link;
        current->link = newNode;
        current = newNode;
    }
}
