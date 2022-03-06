#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include "graphtools.h"
#define LL long long

using namespace std;
int qtyEdges, qtyNodes;

vector<int> e[MAXM];
bool is_connected [MAXN][MAXN];
int absoluteFlow[MAXN][MAXN];
int hotspotFlow[MAXN][MAXN];
int structuralFlow[MAXN][MAXN];

int main(){
    qtyEdges = read(),qtyNodes = read();
    for (int i = 1; i <= qtyEdges; i ++){
        int u = read(), v = read();
        add_edge(u,v,e);
    }
    int routeTot = globalRoute(e,qtyNodes);
    cout << "Structural Flow:" << endl;
    for (int i = 1; i <= qtyNodes; i ++){
        for (vector<int>::iterator iter = e[i].begin(); iter != e[i].end(); ++iter){
            if(*iter < i){
                continue;
            }
            int ans = routeTot - globalRoute_withDisabled(e,qtyNodes,i,*iter);
            int CriticalRoute = get_routeCounts_withDisabled(i,*iter,e,i,*iter);
            if (CriticalRoute){
                std::cout<<"Non-Critical Route: "<<i<<" -> "<<*iter<< " = " << -CriticalRoute << endl;
                structuralFlow[i][*iter] = structuralFlow[*iter][i] = -CriticalRoute;
            }
            else {
                std::cout<< "Critical Route: "<<i<<" -> "<<*iter<< " = " << ans << endl;
                structuralFlow[i][*iter] = structuralFlow[*iter][i] = ans;
            }
        }
    }
    return 0;
}