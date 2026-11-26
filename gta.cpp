#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


struct Nodo{
    bool visited = false;
    vector<int> adj;

    int add_Agj(int x){
        adj.push_back(x);
    }
};

struct Consegna {
    int partenza;
    int arrivo;
};

/*qua contiamo i varchi che attraversiamo, dobbiamo però
sapere quali sono i varchi, quindi li dobbiamo trovare e metterli da
qialche parte (penagos propone stag(ck)).

*/
int dfs(vector<Nodo> grafo, int partenza, int arrivo, int counter = 0){
    Nodo start = grafo[partenza];
    for(int i : grafo[partenza].adj){
        if(i==arrivo){
                                            //ok :);
        }
        else{
            dfs(grafo, i, arrivo);
        }
    }
}



int main(){
    ifstream in ("inpput.txt");

    int N, M, P;
    int U, V;

    in>>N>>M>>P;
    
    vector<Nodo> grafo (N);
    
    vector<Consegna> consegne (P);
    
    for (int i=0; i< M ; i++){
        in>>U>>V;
        grafo[U].add_Agj(V);
        grafo[V].add_Agj(U);
    }

    for (int i=0; i<P; i++){
        in>>consegne[i].partenza>>consegne[i].arrivo;
    }

    


    return 0;
}