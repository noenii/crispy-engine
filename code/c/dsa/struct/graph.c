#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//graphs yo

typedef struct{
    int count;
    bool** matrix;
} graph;

graph* create_graph(int n);
graph* alloc_graph(const graph* oldGraph,bool add);
void free_graph(graph* g);

void add_edge(graph* g,int a,int b);
void rm_edge(graph* g,int a,int b);

graph* add_vertex(graph* oldGraph);
graph* rm_vertex(graph* oldGraph,int v);

void DFS_wrapper(graph* g,int start);
void DFS(graph* g,int v,bool* arr);
void BFS(graph* g,int start);

int get_int(const char* prompt);

int main(){
    bool running=true;
    graph* g=NULL;
    while(running){
        int option=get_int("\nSelect: 1) Add Vert | 2) Remove Vert | 3) Add Edge | 4) Remove Edge 5) View (DFS) | 6) View (BFS) | 7) Exit\n>");
        switch(option){
            case 1:{
                if(!g){
                    graph* temp=create_graph(1);
                    if(!temp){printf("\nError Allocating Memory.");}
                    else{g=temp;}
                }   else{
                    graph* temp=add_vertex(g);
                    if(!temp){printf("\nError Allocating Memory.");}
                    else{g=temp;}
                }
                break;
            }
            case 2:{
                if(!g){printf("\nNo Vertices."); break;}
                if(g->count==1){
                    free_graph(g);
                    g=NULL;
                    break;
                }
                int v=get_int("\nVertex: ");
                if(v<0||v>=g->count){
                    printf("\nInvalid vertex.");
                    break;
                }
                graph* temp = rm_vertex(g, v);
                if(!temp){
                    printf("\nError Allocating Memory.");
                    break;
                }
                g=temp;
                break;
            }
            case 3:{
                if(!g){printf("\nNo Vertices."); break;}
                int opt1=get_int("\nVert 1: ");
                int opt2=get_int("\nVert 2: ");
                add_edge(g,opt1,opt2);
                break;
            }
            case 4:{
                if(!g){printf("\nNo Vertices."); break;}
                int opt1=get_int("\nVert 1: ");
                int opt2=get_int("\nVert 2: ");
                rm_edge(g,opt1,opt2);
                break;
            }
            case 5:{
                if(!g){printf("\nNo Vertices."); break;}
                int opt3=get_int("\nEnter a vertex: ");
                DFS_wrapper(g,opt3);
                break;
            }
            case 6:{
                if(!g){printf("\nNo Vertices."); break;}
                int opt3=get_int("\nEnter a vertex: ");
                BFS(g,opt3);
                printf("\n");
                break;
            }
            case 7:{
                if(!g){running=false; break;}
                free_graph(g);
                running=false;
                break;
            }
        }
    }
    return 0;
}

graph* create_graph(int n) {
    if(n<=0){return NULL;}
    graph* g=malloc(sizeof(graph));
    if(!g){return NULL;}
    g->count=n;
    g->matrix=calloc(n,sizeof(bool*));
    if(!g->matrix){
        free(g);
        return NULL;
    }
    for(int i=0;i<n;i++){
        g->matrix[i]=calloc(n,sizeof(bool));
        if(!g->matrix[i]){
            for(int j=0;j<i;j++){free(g->matrix[j]);}
            free(g->matrix);
            free(g);
            return NULL;
        }
    }
    return g;
}

graph* alloc_graph(const graph* oldGraph,bool add){
    if(!oldGraph){return NULL;}
    if (!add&&oldGraph->count<=1){return NULL;}
    int newCount=add?oldGraph->count + 1:oldGraph->count - 1;
    graph* g=malloc(sizeof(graph));
    if(!g){return NULL;}
    g->count=newCount;
    g->matrix=calloc(newCount,sizeof(bool*));
    if(!g->matrix){
        free(g);
        return NULL;
    }
    for(int i=0;i<newCount;i++){
        g->matrix[i]=calloc(newCount,sizeof(bool));
        if(!g->matrix[i]){
            for(int j=0;j<i;j++){free(g->matrix[j]);}
            free(g->matrix);
            free(g);
            return NULL;
        }
    }
    return g;
}

void free_graph(graph* g){
    if(!g){return;}
    if(g->matrix){
        for(int i=0;i<g->count;i++){free(g->matrix[i]);}
        free(g->matrix);
    }
    free(g);
}

void add_edge(graph* g,int a,int b){
    if(a<0||a>=g->count||b<0||b>=g->count||a==b){return;}
    g->matrix[a][b]=true;
    g->matrix[b][a]=true;
}

void rm_edge(graph* g,int a,int b){
    if(a<0||a>=g->count||b<0||b>=g->count){return;}
    g->matrix[a][b]=false;
    g->matrix[b][a]=false;
}

graph* add_vertex(graph* oldGraph){
    graph* newGraph = alloc_graph(oldGraph,true);
    if(!newGraph){return NULL;}
    for(int x=0;x<(newGraph->count-1);x++){for(int y=0;y<(newGraph->count-1);y++){newGraph->matrix[x][y]=oldGraph->matrix[x][y];}}
    free_graph(oldGraph);
    return newGraph;
}

graph* rm_vertex(graph* oldGraph,int v){
    if(!oldGraph||v<0||v>=oldGraph->count){return NULL;}
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
    free_graph(oldGraph);
    return newGraph;
}

void DFS(graph* g,int v,bool* arr){
    arr[v]=true;
    printf("%d ",v);
    for(int i=0;i<g->count;i++){
        if(g->matrix[v][i]&&!arr[i]){DFS(g,i,arr);}
    }
}

void DFS_wrapper(graph* g,int start){
    if(!g||start<0||start>=g->count){return;}
    bool* visited=calloc(g->count,sizeof(bool));
    DFS(g,start,visited);
    printf("\n");
    free(visited);
}

void BFS(graph* g,int start){
    if(!g||start<0||start>=g->count){return;}
    bool* visited=calloc(g->count,sizeof(bool));
    int* queue=malloc(g->count*sizeof(int));
    if(!visited||!queue){
        free(visited);
        free(queue);
        return;
    }
    int front=0,rear=0;
    visited[start]=true;
    queue[rear++]=start;
    while(front<rear){
        int cur=queue[front++];
        printf("%d ",cur);
        for(int i=0;i<g->count;i++) {
            if(g->matrix[cur][i]&&!visited[i]){
                visited[i]=true;
                queue[rear++]=i;
            }}
    }
    free(queue);
    free(visited);
}

int get_int(const char* prompt){
    int value;
    char term;
    while(true){
        printf("%s", prompt);
        if(scanf("%d%c",&value,&term)!=2||term!='\n'){
            printf("Invalid input. Enter an integer.\n");
            while(getchar() != '\n');
        }   else{return value;}
    }
}

void printGraph(graph* g){
    if(!g){return;}
    for(int i=0;i<g->count;i++){
        for(int j=0;j<g->count;j++){
            if(g->matrix[i][j]){printf("[T]");}
            else{printf("[F]");}
        }
        printf("\n");
    }
}