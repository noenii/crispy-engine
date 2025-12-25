#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//graphs yo

typedef struct{
    int count;
    bool** matrix;
} graph;

graph* create_graph(int n);
graph* alloc_graph(graph* oldGraph,bool m);
void free_graph(graph* g,int j);

void add_edge(graph* g,int a,int b);
void rm_edge(graph* g,int a,int b);

graph* add_vertex(graph* oldGraph);
graph* rm_vertex(graph* oldGraph,int v);

int main(){
    return 0;
}

graph* create_graph(int n){
    if(n<=0){return NULL;}
    graph* tmp=malloc(sizeof(graph));
    if(!tmp){exit(EXIT_FAILURE);}
    tmp->count=n;
    tmp->matrix=malloc(n*sizeof(bool*));
    for(int i=0;i<n;i++){
        tmp->matrix[i]=calloc(n,sizeof(bool));
        if(!tmp->matrix[i]){
            free_graph(tmp,i);
            return NULL;
        }}
    return tmp;
}

graph* alloc_graph(graph* oldGraph,bool m){
    if(!oldGraph){return NULL;}
    int n;
    if(m){n=oldGraph->count+1;}
    else{n=oldGraph->count-1;}
    graph* newGraph=malloc(sizeof(graph));
    if(!newGraph){return NULL;}
    newGraph->count=n;
    newGraph->matrix=malloc(n*sizeof(bool*));
    if(!newGraph->matrix){free(newGraph); return NULL;}
    for(int i=0;i<n;i++){
        newGraph->matrix[i]=calloc(n,sizeof(bool));
        if(!newGraph->matrix[i]){
            free_graph(newGraph,i);
            return NULL;
        }}
    return newGraph;
}

void free_graph(graph* g,int j){
    for(int i=0;i<j;i++){free(g->matrix[i]);}
    free(g->matrix);
    free(g);
}

void add_edge(graph* g,int a,int b){
    if(a<0||a>=g->count||b<0||b>=g->count){return;}
    g->matrix[a][b]=true;
    g->matrix[b][a]=true;
}

void rm_edge(graph* g,int a,int b){
    if(a<0||a>=g->count||b<0||b>=g->count){return;}
    g->matrix[a][b]=false;
    g->matrix[b][a]=false;
}

graph* add_vertex(graph* oldGraph){
    int n=oldGraph->count+1;
    graph* newGraph = alloc_graph(oldGraph,true);
    if(!newGraph){return NULL;}
    for(int x=0;x<(n-1);x++){for(int y=0;y<(n-1);y++){newGraph->matrix[x][y]=oldGraph->matrix[x][y];}}
    free_graph(oldGraph,n-1);
    return newGraph;
}

graph* rm_vertex(graph* oldGraph,int v){    // WARNING: no check if v is out of bounds
    graph* newGraph = alloc_graph(oldGraph,false);
    if(!newGraph){return NULL;}
    int new_i = 0;
    for(int i=0;i<oldGraph->count;i++){
        if(i==v){continue;}
        int new_j=0;
        for(int j=0;j<oldGraph->count;j++){
            if(j==v){continue;}
            newGraph->matrix[new_i][new_j]=oldGraph->matrix[i][j];
            new_j++;
        }
        new_i++;
    }
    free_graph(oldGraph,oldGraph->count);
    return newGraph;
}