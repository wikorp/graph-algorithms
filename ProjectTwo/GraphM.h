#pragma once
#include <iostream>
using namespace std;

class GraphM
{
public:
	int edges;
	int nodes;
	int start_node;
	int end_node;
	int** matrix;
	
	void create_from_file(string file_path, bool directed); // nieskierowany (pst)
	void show();
	//void mst_kruskal();
	void mst_prim(bool show);
	void path_dijikstra(bool show);
	//void path_bellman_ford();
	void clean();
	~GraphM();

};

