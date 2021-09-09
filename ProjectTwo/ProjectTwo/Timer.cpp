#include "Timer.h" 
#include "GraphM.h"
#include "GraphL.h"
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}


void Timer::measure() {
    int density;
    int i = 5;
    for (int p = 10; p <= 100000; p *= 10) {
        i *= 2;
        long long int frequency, start, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
        double prim_m = 0, prim_l = 0, dijikstra_m = 0, dijikstra_l = 0;
        
        density = 25;
        for (int j = 0; j < 100; j++) {
            generate(i, density, true); // directed (dijikstra)
            start = read_QPC();
            m.path_dijikstra(false);
            elapsed = read_QPC() - start;
            dijikstra_m += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            l.path_dijikstra(false);
            elapsed = read_QPC() - start;
            dijikstra_l += (1000000.0 * elapsed) / frequency;

            generate(i, density, false); // not directed (prim)
            start = read_QPC();
            m.mst_prim(false);
            elapsed = read_QPC() - start;
            prim_m += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            l.mst_prim(false);
            elapsed = read_QPC() - start;
            prim_l += (1000000.0 * elapsed) / frequency;
        }

        cout << "SIZE OF STRUCTURE = " << i << " DENSITY = " << density << endl;
        cout << "Time [us] = " << dijikstra_l / 100 << " -dijikstra_l" << endl;
        cout << "Time [us] = " << dijikstra_m / 100 << " -dijikstra_m" << endl;
        cout << "Time [us] = " << prim_l / 100 << " -prim_l" << endl;
        cout << "Time [us] = " << prim_m / 100 << " -prim_m" << endl << endl;

        prim_m = 0, prim_l = 0, dijikstra_m = 0, dijikstra_l = 0;
        density = 50;
        for (int j = 0; j < 100; j++) {
            generate(i, density, true); 
            start = read_QPC();
            m.path_dijikstra(false);
            elapsed = read_QPC() - start;
            dijikstra_m += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            l.path_dijikstra(false);
            elapsed = read_QPC() - start;
            dijikstra_l += (1000000.0 * elapsed) / frequency;

            generate(i, density, false);
            start = read_QPC();
            m.mst_prim(false);
            elapsed = read_QPC() - start;
            prim_m += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            l.mst_prim(false);
            elapsed = read_QPC() - start;
            prim_l += (1000000.0 * elapsed) / frequency;
        }

        cout << "SIZE OF STRUCTURE = " << i << " DENSITY = " << density << endl;
        cout << "Time [us] = " << dijikstra_l / 100 << " -dijikstra_l" << endl;
        cout << "Time [us] = " << dijikstra_m / 100 << " -dijikstra_m" << endl;
        cout << "Time [us] = " << prim_l / 100 << " -prim_l" << endl;
        cout << "Time [us] = " << prim_m / 100 << " -prim_m" << endl << endl;

        prim_m = 0, prim_l = 0, dijikstra_m = 0, dijikstra_l = 0;
        density = 75;
        for (int j = 0; j < 100; j++) {
            generate(i, density, true); 
            start = read_QPC();
            m.path_dijikstra(false);
            elapsed = read_QPC() - start;
            dijikstra_m += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            l.path_dijikstra(false);
            elapsed = read_QPC() - start;
            dijikstra_l += (1000000.0 * elapsed) / frequency;

            generate(i, density, false);
            start = read_QPC();
            m.mst_prim(false);
            elapsed = read_QPC() - start;
            prim_m += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            l.mst_prim(false);
            elapsed = read_QPC() - start;
            prim_l += (1000000.0 * elapsed) / frequency;
        }

        cout << "SIZE OF STRUCTURE = " << i << " DENSITY = " << density << endl;
        cout << "Time [us] = " << dijikstra_l / 100 << " -dijikstra_l" << endl;
        cout << "Time [us] = " << dijikstra_m / 100 << " -dijikstra_m" << endl;
        cout << "Time [us] = " << prim_l / 100 << " -prim_l" << endl;
        cout << "Time [us] = " << prim_m / 100 << " -prim_m" << endl << endl;

        prim_m = 0, prim_l = 0, dijikstra_m = 0, dijikstra_l = 0;
        density = 99;
        for (int j = 0; j < 100; j++) {
            generate(i, density, true); 
            start = read_QPC();
            m.path_dijikstra(false);
            elapsed = read_QPC() - start;
            dijikstra_m += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            l.path_dijikstra(false);
            elapsed = read_QPC() - start;
            dijikstra_l += (1000000.0 * elapsed) / frequency;

            generate(i, density, false);
            start = read_QPC();
            m.mst_prim(false);
            elapsed = read_QPC() - start;
            prim_m += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            l.mst_prim(false);
            elapsed = read_QPC() - start;
            prim_l += (1000000.0 * elapsed) / frequency;
        }

        cout << "SIZE OF STRUCTURE = " << i << " DENSITY = " << density << endl;
        cout << "Time [us] = " << dijikstra_l / 100 << " -dijikstra_l" << endl;
        cout << "Time [us] = " << dijikstra_m / 100 << " -dijikstra_m" << endl;
        cout << "Time [us] = " << prim_l / 100 << " -prim_l" << endl;
        cout << "Time [us] = " << prim_m / 100 << " -prim_m" << endl << endl;
    }
}

void Timer::test() {
    generate(5, 25, true);
    m.show();
    l.show();
    generate(5, 25, false);
    m.show();
    l.show();

    generate(4, 50, true);
    m.show();
    l.show();
    generate(4, 50, false);
    m.show();
    l.show();
}

void Timer::generate(int nodes_number, int density, bool directed) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, nodes_number - 1);

    m.clean();
    l.clean();
    int max_edges_directed = nodes_number * nodes_number - nodes_number;
    int max_edges_not_directed = (nodes_number * nodes_number - nodes_number) / 2;
    int edges_directed = (max_edges_directed * density) / 100;
    int edges_not_directed = (max_edges_not_directed * density) / 100;
    int edges;
    if (directed)
        edges = edges_directed;
    else edges = edges_not_directed;

    m.matrix = new int* [nodes_number];
    for (int i = 0; i < nodes_number; i++) {
        m.matrix[i] = new int[nodes_number];
    }
    for (int i = 0; i < nodes_number; i++)
        for (int j = 0; j < nodes_number; j++)
            m.matrix[i][j] = 0;
    m.edges = edges;
    m.nodes = nodes_number;
    m.start_node = 0; // mozna wylosowac w nieskierowanym
    m.end_node = 1;  // nie ma znaczenia

    l.neighbours_lists = new Neighbour * [nodes_number];
    for (int i = 0; i < nodes_number; i++) {
        l.neighbours_lists[i] = NULL;
    }
    l.edges = edges;
    l.nodes = nodes_number;
    l.start_node = 0;
    l.end_node = 1;

    int** exist;
    exist = new int* [nodes_number];
    for (int i = 0; i < nodes_number; i++) {
        exist[i] = new int[nodes_number];
    }

    for (int i = 1; i < nodes_number; i++)
        for (int j = 0; j < nodes_number; j++)
            exist[i][j] = 0;
    /*
    // zagwarantowanie spojnosci
    int a, b, weigth = 1;
    for (int i = 1; i < nodes_number; i++) {
        exist[0][i] = true;

        weigth = dist(gen) + 1;
        m.matrix[0][i] = weigth;

        Neighbour* s = new Neighbour;
        s->next = l.neighbours_lists[0];
        l.neighbours_lists[0] = s;
        s->weight = weigth;
        s->end_node = i;

        if (directed == false) {
            exist[i][0] = true;

            m.matrix[i][0] = weigth;

            Neighbour* e = new Neighbour;
            e->next = l.neighbours_lists[i];
            l.neighbours_lists[i] = e;
            e->weight = weigth;
            e->end_node = 0;
        }
    }
    edges = edges + 1 - nodes_number;
    //

  
    //trwaja prace nad zagwarantowaniem spojnosci w bardziej zrandomizowany sposob
    //cout << 1 << " dsd" << edges << endl;
    int a, b, edges_consistent = 0, weigth;/*
    bool* consistent = new bool [nodes_number];
    for (int i = 0; i < nodes_number; i++)
        consistent[i] = false;
    //cout << 2 << endl;
    a = 0;
    consistent[0] = true;
    while (edges_consistent < (nodes_number - 1)) {
        b = dist(gen);
        while (consistent[b] == true) {
            b = dist(gen);
        }
        consistent[b] == false;
        exist[a][b] = true;

        weigth = dist(gen) + 1;
        m.matrix[a][b] = weigth;

        Neighbour* s = new Neighbour;
        s->next = l.neighbours_lists[a];
        l.neighbours_lists[a] = s;
        s->weight = weigth;
        s->end_node = b;

        if (directed == false) {
            exist[b][a] = true;

            m.matrix[b][a] = weigth;

            Neighbour* e = new Neighbour;
            e->next = l.neighbours_lists[b];
            l.neighbours_lists[b] = e;
            e->weight = weigth;
            e->end_node = a;
        }
        a = b;  // teraz koncowy bedzie startowym aby zagwarantowac spojnosc
        edges_consistent++;
    }
    delete[] consistent;
    //cout << 6 << endl;
    edges = edges - edges_consistent;
    */

    int a, b, weigth;
    int* shuf = new int[nodes_number];
    for (int i = 0; i < nodes_number; i++) {
        shuf[i] = i;
    }

    int bufor;
    for (int i = 0; i < nodes_number; i++) {
        a = dist(gen);
        b = dist(gen);
        bufor = shuf[a];
        shuf[a] = shuf[b];
        shuf[b] = bufor;
    }

    a = 0;
    b = shuf[a];
    weigth = dist(gen) + 1;
    exist[a][b] = true;

    m.matrix[a][b] = weigth;

    Neighbour* s = new Neighbour;
    s->next = l.neighbours_lists[a];
    l.neighbours_lists[a] = s;
    s->weight = weigth;
    s->end_node = b;

    if (directed == false) {
        exist[b][a] = true;

        m.matrix[b][a] = weigth;

        Neighbour* e = new Neighbour;
        e->next = l.neighbours_lists[b];
        l.neighbours_lists[b] = e;
        e->weight = weigth;
        e->end_node = a;
    }

    for (int i = 0; i < nodes_number - 1; i++) {
        a = shuf[i];
        b = shuf[i + 1];
        weigth = dist(gen) + 1;
        exist[a][b] = true;

        m.matrix[a][b] = weigth;

        Neighbour* s = new Neighbour;
        s->next = l.neighbours_lists[a];
        l.neighbours_lists[a] = s;
        s->weight = weigth;
        s->end_node = b;

        if (directed == false) {
            exist[b][a] = true;

            m.matrix[b][a] = weigth;

            Neighbour* e = new Neighbour;
            e->next = l.neighbours_lists[b];
            l.neighbours_lists[b] = e;
            e->weight = weigth;
            e->end_node = a;
        }
    }
    
    while (edges - nodes_number > 0) { 
        edges--;
        int guard = 0;
        bool find = false;
        while (guard < 10) {
            a = dist(gen);
            b = dist(gen);
            if (exist[a][b] == 0 && a != b) {
                find = true;
                break;
            }
            guard++;
        }

        if (find == false) { // napewno znajdzie
            for (int i = 0; i < nodes_number; i++)
                for (int j = 0; j < nodes_number; j++)
                    if (exist[i][j] == 0 && i != j) { 
                        a = i;
                        b = j;
                    }
        }
        weigth = dist(gen) + 1;
        exist[a][b] = true;

        m.matrix[a][b] = weigth;

        Neighbour* s = new Neighbour;
        s->next = l.neighbours_lists[a];
        l.neighbours_lists[a] = s;
        s->weight = weigth;
        s->end_node = b;

        if (directed == false) {
            exist[b][a] = true;

            m.matrix[b][a] = weigth;

            Neighbour* e = new Neighbour;
            e->next = l.neighbours_lists[b];
            l.neighbours_lists[b] = e;
            e->weight = weigth;
            e->end_node = a;
        }
    }
}

