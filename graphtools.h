//
// Created by Luke Alpha on 2022/2/27.
//
#include <vector>

#ifndef TRAFFIC_GRAPHTOOLS_H

#define TRAFFIC_GRAPHTOOLS_H
#define MAXN 1010
#define MAXM 1010
int read();
int get_routeCounts(int u,int v, std::vector<int> e[]);
int get_routeCounts_withDisabled(int u,int v, std::vector<int> e[], int x, int y);
void add_edge(int u,int v, std::vector<int> e[]);
int globalRoute(std::vector<int> e[], int qtyNodes);
int globalRoute_withDisabled(std::vector<int> e[], int qtyNodes, int dis_x, int dis_y);
#endif //TRAFFIC_GRAPHTOOLS_H
