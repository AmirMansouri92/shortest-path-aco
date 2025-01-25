#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
using namespace std;


const int NUM_ANTS = 10;
const int MAX_ITERATION = 20;
const float ALPHA = 1;
const float BETA = 2;
const float EVAPORATION_RATE = 0.4;
const float Q=100.0;


int numNodes, numEdges, startNode, endNode;
vector<vector<double>> distances;


void readSPP(string& filename, vector<vector<double>>& distances){
    ifstream file(filename);
    if(!file.is_open()){
        cerr<<"Error: could not open file"<<filename<<endl;

    }
    file>>numNodes>>numEdges>>startNode>>endNode; //read the number of nodes, the number of edges, the starting node, the ending node
    distances.resize(numNodes, vector<double> (numNodes, numeric_limits<int>::max()));
    int k, j, d;
    for (int i=0; i<numEdges; i++){
        file>> k >>j>>d; //read node id, x, y
        distances[k][j]=d;
        distances[j][k]=d;

    }
    file.close();
}


void printNodes(){
    cout<< "Nodes"<<endl;
    cout<<"number of node is: "<<numNodes<<"number of edges is: "<<numEdges<<", the start node is:"<<startNode<<"\n"<<", the end node is:"<<endNode<<endl;
    for(int i=0; i<numNodes; i++){
        for(int j=0; j<numNodes; j++){
            cout<<"d"<<i<<j<<": "<<distances[i][j]<<"\n";

        }
        cout<<endl;
    }  
}


class Ant{
    public:
    vector<int> path;
    vector<bool> visited;
    double pathlength;
 
    Ant() : pathlength(0.0){
        visited.resize(numNodes, false);
        /*for (int i= 0; i < numNodes; i++){
            cout <<visited [0] <<endl;
        }*/
        path.clear();
        path.push_back(startNode);
        visited[startNode] = true;
        pathlength = 0.0;      
    }

    int chooseNextNode(vector<vector<double>>& pheromones){
        int currentNode = path.back();
        vector<double> probabilities(numNodes, 0.0);
        double sum = 0.0;
        double pheromone, distance;
        for(int i=0; i<numNodes; i++){
            if(!visited[i] && !visited[endNode]){
                pheromone = pheromones [currentNode][i];
                distance = distances[currentNode][i];
                probabilities[i]= pow(pheromone, ALPHA) * pow(1/distance, BETA);
                sum += probabilities[i];
            }
        }
        if (sum == 0) return -1;
        for(int i=0; i<numNodes; i++){
            probabilities[i] /= sum;
        }
        
        double random = (rand()/ (double) RAND_MAX);
        double sum2 = 0.0;
        for(int i=0; i<numNodes; i++){
            if(!visited[i]&& !visited[endNode]){
                sum2 += probabilities[i];
                if(random<=sum2){
                    visited [i] = true;
                    path.push_back(i);
                    pathlength += distances[currentNode][i];
                    return i;
                    cout<<"i:"<<i<<"\n";
                }
            }
        }
        return -1;
    }
};

class ACS{

    public:
    vector<vector<double>> pheromones;
    Ant globalBestAnt;
    ACS(){
        pheromones = vector<vector<double>> (numNodes, vector<double> (numNodes, 1));
        globalBestAnt.pathlength =numeric_limits<int>::max();
    }

    

    void run(){
        for(int i=0; i<MAX_ITERATION; i++){
            vector<Ant> ants = initializeAnts ();
            for(Ant& ant: ants){
                constructPath(ant);
                updatePheromones(ant);
                if(ant.pathlength<globalBestAnt.pathlength){
                    globalBestAnt = ant;
                }
            }
            evaporatePheromones();
            displayBest(ants, i);
        }
        cout<<"best path: \n";
        for(int node: globalBestAnt.path){
            cout << node << " ";
        }
        if(globalBestAnt.pathlength == numeric_limits<int>::max()){
            cout<<"there is no path between these two nodes";         
        }
        else
        cout<< "\nthe total distance: "<<globalBestAnt.pathlength<<endl;
    }
    


    vector<Ant> initializeAnts (){
        vector<Ant> ants(NUM_ANTS, Ant());
        return ants;
    }

    void constructPath(Ant& ant){
        while(!ant.visited[endNode]){
            ant.chooseNextNode(pheromones);
        }
    }

    void updatePheromones(Ant& ant){
        for(int i=0; i<numNodes-1; i++){
            if(!ant.visited[endNode]){
                int from = ant.path[i];
                int to = ant.path [i+1];
                pheromones [from][to] += Q/ant.pathlength;
                pheromones [to][from] += Q/ant.pathlength;
            }
        }
    }

    void evaporatePheromones(){
        for(int i=0; i<numNodes; i++){
            for(int j=0; j<numNodes; j++){
                pheromones[i][j] *= (1- EVAPORATION_RATE);
            }
        }
    }

    void displayBest(vector<Ant>& ants, int iteration){
        Ant bestAnt = ants [0];
        for (Ant& ant: ants){
            if(ant.pathlength<bestAnt.pathlength){
                bestAnt = ant;
            }
        }
        cout<<"iteration: "<<iteration<<"\tBest Path Length: "<<bestAnt.pathlength<<endl;
    }
};


int main(){
    srand(time(0));
    string filename = "SPP_data.txt";
    int numNodes, startNode, endNode;
    //read SSP data from the file
    readSPP(filename, distances);
    //print the data
    //printNodes();
    ACS obj1;
    obj1.run();
    return 0;
}