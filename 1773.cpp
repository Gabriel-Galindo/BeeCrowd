#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int mat[1005][1005];
int visitado[1005];
int requisito[1005];

int BFS(int ini,int v){
    queue<int> fila;
    int i,j;
    int nafila[v];
    memset(nafila,0,sizeof(nafila));
    visitado[ini]=1;
    nafila[ini]=1;
    fila.push(ini);
    while (!fila.empty()){
        for(i=1;i<v;i++){
            if(mat[fila.front()][i]){
                if(visitado[requisito[i]]&&!visitado[i]){
                    visitado[i]=1;
                    fila.push(fila.front());
                    nafila[fila.front()]++;
                    for(j=0;j<v;j++){
                        if(visitado[j]&&!nafila[j]){
                            fila.push(j);
                            nafila[j]=1;
                        }
                    }
                }
            }
        }
        nafila[fila.front()]--;
        fila.pop();
    }
    for(i=1;i<v;i++){
        if(!visitado[i]) return 0;
    }
    return 1;
}

int main(){
    int vertices,arestas,x,y,temp;
    while(cin>>vertices>>arestas){
        for(x=0;x<vertices;x++){
            visitado[x]=0;
            requisito[x]=0;
            for(y=0;y<vertices;y++){
                mat[x][y]=0;
            }
        }
        while(arestas--){
            cin>>x>>y;
            mat[x-1][y-1]=1;
            mat[y-1][x-1]=1;
        }
        for(x=1;x<vertices;x++){
            cin>>temp;
            requisito[x]=temp-1;
        }
        if(BFS(0,vertices)) cout<<"sim"<<endl;
        else cout<<"nao"<<endl;
    }
    return 0;
}