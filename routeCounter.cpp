//
// Created by Luke Alpha on 2022/3/6.
//
#include "graphtools.h"
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int ANS_routeCounter = 0;
bool vis[MAXN];
int disabled_x, disabled_y;
void routeCounter(int _starting_point, int _destination_point, int current, int last, vector<int> e[]){
    if(current == _destination_point){
        ANS_routeCounter ++;
        vis[current] = 0;
        return ;
    }
    for(vector<int>::iterator iter = e[current].begin(); iter != e[current].end(); ++iter){
        if(!vis[*iter] && *iter != last && !((disabled_x == current && disabled_y == *iter) || (disabled_y == current && disabled_x == *iter)) ){
            vis[*iter] = true;
            routeCounter(_starting_point, _destination_point, *iter, current, e);
            vis[*iter] = false;
        }
    }
    return ;
}
int get_routeCounts(int u,int v, vector<int> e[]){
    ANS_routeCounter = 0;
    vis[u] = true;
    routeCounter(u, v, u, 0, e);
    int returnValue = ANS_routeCounter;
    ANS_routeCounter = 0;
    memset(vis,0,sizeof vis);
    return returnValue;
}
int get_routeCounts_withDisabled(int u,int v, vector<int> e[], int dis_x, int dis_y){
    disabled_x = dis_x;
    disabled_y = dis_y;
    ANS_routeCounter = 0;
    vis[u] = true;
    routeCounter(u, v, u, 0, e);
    int returnValue = ANS_routeCounter;
    ANS_routeCounter = 0;
    memset(vis,0,sizeof vis);
    disabled_x = 0;
    disabled_y = 0;
    return returnValue;
}

int globalRoute(vector<int> e[], int qtyNodes){
    int routeTot = 0;
    for (int i = 1; i <= qtyNodes; i ++){
        for (int j = i + 1; j <= qtyNodes; j ++){
            routeTot += get_routeCounts(i,j,e);
        }
    }
    return routeTot;
}

int globalRoute_withDisabled(vector<int> e[], int qtyNodes, int dis_x, int dis_y){
    disabled_x = dis_x;
    disabled_y = dis_y;
    int returnTot = 0;
    for (int i = 1; i <= qtyNodes; i ++){
        for (int j = i + 1; j <= qtyNodes; j ++){
            returnTot += get_routeCounts(i, j, e);
        }
    }
    disabled_x = 0;
    disabled_y = 0;
    return returnTot;
}