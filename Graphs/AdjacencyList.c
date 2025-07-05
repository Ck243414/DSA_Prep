#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void addEdge(struct Node* adj[],int i,int j){
    struct Node*node=newNode(j);
    node->next=adj[i];
    adj[i]=node;
    //if undirected then following also should be there
    struct Node*oppnode=newNode(i);
    oppnode->next=adj[j];
    adj[j]=oppnode;
}

void displayAdjacencyList(struct Node* adj[],int V){
    for(int i=0;i<V;i++){
        printf("%d ", i);
        struct Node*temp=adj[i];
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    int V=4;
    struct Node*adj[V];
    for(int i=0;i<V;i++){
        adj[i]=NULL;
    }
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    printf("Adjacency List Representation:\n");
    displayAdjacencyList(adj, V);

    return 0;
}