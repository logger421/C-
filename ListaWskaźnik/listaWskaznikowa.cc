#include <iostream>

typedef int elementtype;

struct celltype {
elementtype element;
celltype * next;
};

typedef celltype * position;

class Lista
{
protected :
	position l; // wskaźnik do głowy listy
public:
	Lista() //konstruktor
	{
		l = new celltype;
		l->next = NULL;
	}
	~Lista() //destruktor
	{
		while ( l->next != NULL ) 
		{
			position x = l->next; 
			position p = l;
			while ( x->next != NULL ) 
			{
				p = x;
				x = x->next;
        		}
			delete x;
			p->next = NULL;
		}
	}
	
	void Insert(elementtype x, position p); // wstaw x na pozycję p na liście L
	void Delete(position p); // usuwa element na pozycji p z listy. 
	elementtype Retrieve(position p); //zwraca element występujący w L na pozycji p.
	position Locate(elementtype x); //zwraca pozycję pierwszego wystąpienia elementu x w liście L
	position First();
	position Next(position p); //zwraca pozycję następną w stosunku do p w L. 
	position Previous(position p); //zwraca pozycję poprzednią w stosunku do p w L
	position END();
};
void PrintList(Lista *l);

//**********************MAIN***********************************//
int main()
{
	std::cout << "Przykład działania listy wskaźnikowej:\n";
	Lista *l = new Lista();
	std::cout << "Wstawiamy pierwszy element na listę\n";
	l->Insert(5, l->First()); // wstaw i wypisz pierwszy element
	PrintList(l);
	std::cout << "Wstawiamy coś na pierwsze miejsce w liście:\n";
	l->Insert(2, l->First()); // // wstaw coś na pierwszy element i wypisz 
	std::cout << "Pierwszy element: " << l->Retrieve(l->First()) << std::endl;
	PrintList(l);
	std::cout << "Wstawiamy coś na drugie miejsce w liście:\n";
	l->Insert(1, l->Next(l->First())); // wstaw 1 za pierwszym elementem
	std::cout << "Pierwszy element: " << l->Retrieve(l->First()) << std::endl;
	std::cout << "Drugi element: " << l->Retrieve(l->Next(l->First())) << std::endl;
	std::cout << "Trzeci element: " << l->Retrieve(l->Next(l->Next(l->First()))) << std::endl;
	
	l->Insert(3, l->END());
	PrintList(l);
	return 0;
}

//*********************FUNKCJE*********************************//
void PrintList(Lista *l) {
    celltype * node = l->First()->next;
    int i = 1;

    std::cout << "Lista wskaźnikowa:" << std::endl;
    while (node != NULL) {
        std::cout << node->element << " ";
        i++;
        node = node->next;
    } 
    std::cout << "\n";
}

void Lista::Insert(elementtype x, position p)
{
	celltype *node = new celltype(); // utwórz nową komórkę
	node->element = x; // ustaw przechowywaną wartość na dany element x

	position temp = p->next; // zapisz wskazywany element następny węzła p w zmienej tymczasowej
	p->next = node; // ustaw wskazywany element węzła p na nowo utworzoną komórkę
	node->next = temp; // ustaw wskazywany elemenet nowo utworzonej komórki na węzęł poprzednio wskazywany przez element na pozycji p
}

void Lista::Delete(position p)
{
    position temp = p->next->next; // zapisz w zmiennej tymczasowej pozycję następnego węzła za p
    delete p->next; // usun komórkę na pozycji p
    p->next = temp; // zapisz na pozycji p element który był po tej komórce
}
elementtype Lista::Retrieve(position p)
{
	if(p->next != NULL)
		return p->next->element;
	else
		return 0;
}
position Lista::Locate(elementtype x)
{
	position pos = l; // ustaw na pozycję na głowę listy
	while (pos->next->element != x) // przeglądamy listę dopóku w odpowiednim węźle nie znajdziemy naszego x
		pos = pos->next;
	return pos;
}
position Lista::First()
{
	return l;
}
position Lista::Next(position p)
{
	return p->next;
}
position Lista::Previous(position p)
{
	position pos = l; // ustaw pozycję na głowę listy i przeglądaj dopóki następny element nie będzie szukaną pozycją
	while (pos->next != p)
		pos = pos->next;
	return pos;
}
position Lista::END()
{
	position end = l; // ustaw pozycje na początek listy i przeglądaj do czasu aż następny element nie będzie nullem
	while (end->next != NULL)
		end = end->next;
	return end;
}















