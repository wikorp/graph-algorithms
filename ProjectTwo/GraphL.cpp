#include "GraphL.h"
#include "Heap.h"
#include <iostream>
#include <fstream>
using namespace std;

void GraphL::create_from_file(string file_path , bool directed) {
	clean();
	ifstream file;
	file.open(file_path);

	if (file.is_open())
	{
		file >> edges;
		file >> nodes;
		file >> start_node;
		file >> end_node;
		if (file.fail())
			cout << "file error" << endl;
		else {
			neighbours_lists = new Neighbour* [nodes];
			for (int i = 0; i < nodes; i++) {
				neighbours_lists[i] = NULL;
			}

			for (int i = 0; i < edges; i++)
			{
				int start, end, weight;
				file >> start;
				file >> end;
				file >> weight;
				if (file.fail())
				{
					cout << "file error - READ DATA" << endl;
					break;
				}
				else {
					Neighbour *s = new Neighbour;
					s->next = neighbours_lists[start];
					neighbours_lists[start] = s;
					s->weight = weight;
					s->end_node = end;
					
					if (directed == false) {
						Neighbour* e = new Neighbour;
						e->next = neighbours_lists[end];
						neighbours_lists[end] = e;
						e->weight = weight;
						e->end_node = start;
					}
				}

			}
		}
		file.close();
	}
	else
		cout << "file error - OPEN" << endl;
}

void GraphL::show() {
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "neighbours lists representation of graph" << endl;

	for (int i = 0; i < nodes; i++) {
		Neighbour* iterator;
		iterator = neighbours_lists[i];
		cout << i << ":    ";
		while (iterator != NULL) {
			cout << iterator->end_node << " weight:" << iterator->weight << "    ";
			iterator = iterator->next;
		}
		cout << endl;
	}
	cout << endl;
}

void GraphL::path_dijikstra(bool show) {
	int* predesecor = new int[nodes];
	int* expense = new int[nodes];
	bool* QS = new bool[nodes];

	for (int i = 0; i < nodes; i++) {
		predesecor[i] = -1; 
		expense[i] = INT_MAX;
		QS[i] = true;
	}
	expense[start_node] = 0;

	int n = nodes;
	while (n--) {
		int min = INT_MAX;
		int min_pointer;
		for (int i = 0; i < nodes; i++) {
			if (min > expense[i] && QS[i] == true) {
				min = expense[i];
				min_pointer = i;
			}
		}
		QS[min_pointer] = false;

		Neighbour* iterator;
		iterator = neighbours_lists[min_pointer];
		while (iterator != NULL) {
			if (expense[iterator->end_node] > expense[min_pointer] + iterator->weight) {
				expense[iterator->end_node] = expense[min_pointer] + iterator->weight;
				predesecor[iterator->end_node] = min_pointer;
			}
			iterator = iterator->next;
		}
	}
	if (show == true) {
		cout << "start: " << start_node << endl;
		for (int i = 0; i < nodes; i++) {
			cout << "end: " << i << " | distance: " << expense[i] << " | path: " << i;
			int x = i;
			while (predesecor[x] != -1) {
				cout << " " << predesecor[x];
				x = predesecor[x];
			}
			cout << endl;
		}
		cout << endl;
	}

	delete[] predesecor;
	delete[] expense;
	delete[] QS;
}

void GraphL::mst_prim(bool show) { 
	HeapElement* mst = new HeapElement[nodes - 1];
	int p = 0;
	Heap edges;
	bool* visited = new bool[nodes];
	for (int i = 0; i < nodes; i++)
		visited[i] = false;

	visited[0] = true;

	HeapElement new_edge;
	Neighbour* iterator;
	iterator = neighbours_lists[0];
	while (iterator != NULL) {
		new_edge.end = iterator->end_node;
		new_edge.start = 0;
		new_edge.weight = iterator->weight;
		edges.put(new_edge);

		iterator = iterator->next;
	}

	HeapElement current_edge;
	int n = nodes;
	while (--n) { // gdy graf nie jest spojny to && edges.get_min() != NULL
		while (visited[edges.get_min().end] == true) { // napewno bedzie jezeli to graf spojny 
			edges.remove_first();
		}
		current_edge = edges.get_min();
		edges.remove_first();
		visited[current_edge.end] = true;
		mst[p].end = current_edge.end;
		mst[p].start = current_edge.start;
		mst[p++].weight = current_edge.weight;

		iterator = neighbours_lists[current_edge.end];
		while (iterator != NULL) {
			if (visited[iterator->end_node] == true) {
				iterator = iterator->next;
				continue;
			}
			new_edge.end = iterator->end_node;
			new_edge.start = current_edge.end;
			new_edge.weight = iterator->weight;
			edges.put(new_edge); 

			iterator = iterator->next;
		}
	}

	if (show == true) {														
		int sum = 0;
		for (int i = 0; i < (nodes - 1); i++) {
			cout << "(" << mst[i].start << ", " << mst[i].end << ")  " << mst[i].weight << endl;
			sum += mst[i].weight;
		}
		cout << "MST = " << sum << endl << endl;
	}
	delete[] mst;
	delete[] visited;
}

void GraphL::clean() {
	Neighbour* to_delete;
	Neighbour* iterator;
	for (int i = 0; i < nodes; i++) {
		iterator = neighbours_lists[i];
		while (iterator != NULL) {
			to_delete = iterator;
			iterator = iterator->next;
			delete to_delete;
		}
	}
	delete[] neighbours_lists;
}

GraphL::~GraphL() {
	clean();
}