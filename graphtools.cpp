#include <cstdio>
#include <iostream>
#include <vector>

#define LL long long
using namespace std;

int read(){
    char ch = getchar();int x = 0,f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}

void add_edge(int u,int v, std::vector<int> e[]){
    e[u].push_back(v);
    e[v].push_back(u);
}