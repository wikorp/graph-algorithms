#include "Heap.h"
#include <iostream>
#include <fstream>
using namespace std;

int Heap::parent(int index) {
	return (index - 1) / 2;
}

int Heap::left(int index) {
	return (index * 2) + 1;
}

int Heap::right(int index) {
	return (index * 2) + 2;
}

void Heap::heapify(int index) { // filter down
	int min = index;
	if (left(index) < size and tab[min].weight > tab[left(index)].weight)
		min = left(index);
	if (right(index) < size and tab[min].weight > tab[right(index)].weight)
		min = right(index);

	if (min == index)
		return;

	HeapElement bufor = tab[index];
	tab[index] = tab[min];
	tab[min] = bufor;

	heapify(min);
}

void Heap::build() {
	int firstLeaf = (size - 2) / 2 + 1;

	for (int i = firstLeaf - 1; i >= 0; i--)
		heapify(i);
}

void Heap::remove_first() {
	if (size == 0)
		return;

	tab[0] = tab[size - 1];
	size--;
	heapify(0);
	HeapElement* new_tab = new HeapElement[size];
	for (int i = 0; i < size; i++)
		new_tab[i] = tab[i];

	delete[] tab;
	tab = new_tab;
}

HeapElement Heap::get_min() {
	if (size > 0)
		return tab[0];
}

void Heap::put(HeapElement edge) {
	HeapElement* new_tab = new HeapElement[size + 1];
	for (int i = 0; i < size; i++)
		new_tab[i] = tab[i];
	delete[] tab;
	tab = new_tab;
	size++;

	int i = size - 1;
	while (i > 0 and tab[parent(i)].weight > edge.weight) {
		tab[i] = tab[parent(i)];
		i = parent(i);
	}

	tab[i] = edge;
}

void Heap::show() {
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Heap:      !MIGHT BE NECESSARY MAXIMAZE THE WINDOW!" << endl;
	for (int i = 0; i < size; i++) {
		cout << tab[i].weight << " ";
	}
	cout << endl;

	int floor = 1;
	int scale = 128;
	for (int i = 0; i < size; i++) {

		int elements = floor;
		while (elements > 0 and i < size) {
			for (int i = 0; i <= scale / (floor + 1); i++)
				cout << " ";

			cout << tab[i].weight << " ";
			elements--;
			i++;
		}
		cout << endl;
		floor *= 2;
		i--;
	}
}

Heap::~Heap() {
	delete[] tab;
}
