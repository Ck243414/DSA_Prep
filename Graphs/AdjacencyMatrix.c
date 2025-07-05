#include<stdio.h>
#define V 4

void addEdge(int matrix[V][V],int i, int j){
    matrix[i][j]=1;
    matrix[j][i]=1; //if undirected
}

void printMatrix(int matrix[V][V]){
    int i=0,j=0;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int mat[V][V]={0};
    addEdge(mat,0,1);
    addEdge(mat,0,2);
    addEdge(mat,2,3);
    printMatrix(mat);
    return 0;
}