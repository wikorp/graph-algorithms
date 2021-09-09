#include "GraphM.h"
#include "Heap.h"
#include <iostream>
#include <fstream>
using namespace std;

void GraphM::create_from_file(string file_path, bool directed) {
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
			matrix = new int* [nodes];
			for (int i = 0; i < nodes; i++) {
				matrix[i] = new int[nodes];
			}
			for (int i = 0; i < nodes; i++) 
				for (int j = 0; j < nodes; j++) 
					matrix[i][j] = 0;

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
					matrix[start][end] = weight;
					if (directed == false)
						matrix[end][start] = weight;
				}

			}
		}
		file.close();
	}
	else
		cout << "file error - OPEN" << endl;
}

void GraphM::show() {
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Weiht matrix representation of graph" << endl;

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void GraphM::path_dijikstra(bool show) {
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
			if (min > expense[i] && QS[i] == true) { // musi byc spojny
				min = expense[i];
				min_pointer = i;
			}
		}
		QS[min_pointer] = false;

		for (int i = 0; i < nodes; i++) {
			if (matrix[min_pointer][i] != 0) {
				if (QS[i] == true && (expense[i] > (expense[min_pointer] + matrix[min_pointer][i]))) {
					expense[i] = expense[min_pointer] + matrix[min_pointer][i];
					predesecor[i] = min_pointer;
				}

			}
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

void GraphM::mst_prim(bool show) {
	HeapElement* mst = new HeapElement[nodes - 1];
	int p = 0;
	Heap edges;
	bool* visited = new bool[nodes];
	for (int i = 0; i < nodes; i++)
		visited[i] = false;

	visited[0] = true;

	HeapElement new_edge;
	for (int i = 0; i < nodes; i++) {
		if (matrix[0][i] != 0) {
			new_edge.end = i;
			new_edge.start = 0;
			new_edge.weight = matrix[0][i];
			edges.put(new_edge);
		}
	}
	
	HeapElement current_edge;
	int n = nodes;
	while (--n) {
		while (visited[edges.get_min().end] == true) { // napewno bedzie jezeli to graf spojny
			edges.remove_first();
		}
		current_edge = edges.get_min();
		edges.remove_first();
		visited[current_edge.end] = true;
		mst[p].end = current_edge.end;
		mst[p].start = current_edge.start;
		mst[p++].weight = current_edge.weight;
		
		HeapElement new_edge;
		for (int i = 0; i < nodes; i++) {
			if (matrix[current_edge.end][i] == 0 || visited[i] == true) 
				continue;

			new_edge.end = i;
			new_edge.start = current_edge.end;
			new_edge.weight = matrix[current_edge.end][i];
			edges.put(new_edge);
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

void GraphM::clean() {
	for (int i = 0; i < nodes; i++)
		delete matrix[i];
	delete[] matrix;
}

GraphM::~GraphM() {
	clean();
}