#pragma once
#include <iostream>
using namespace std;

struct HeapElement {
	int start;
	int end;
	int weight;
};

class Heap
{
public:
	int size = 0;
	HeapElement* tab = new HeapElement[size];

	int parent(int index);
	int left(int index);
	int right(int index);
	void heapify(int index);
	void build();

	HeapElement get_min();
	void remove_first();
	void put(HeapElement edge);

	void show();

	~Heap();
};
