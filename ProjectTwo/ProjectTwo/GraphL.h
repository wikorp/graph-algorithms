#pragma once
#include <iostream>
using namespace std;

struct Neighbour {
	int end_node;
	int weight;
	Neighbour* next;
};

class GraphL
{
public:
	int edges;
	int nodes;
	int start_node;
	int end_node;
	Neighbour** neighbours_lists; 
	
	void create_from_file(string file_path, bool directed); // nieskierowany (mst)
	void show();
	//void mst_kruskal();
	void mst_prim(bool show);
	void path_dijikstra(bool show);
	//void path_bellman_ford();
	void clean();
	~GraphL();
};

