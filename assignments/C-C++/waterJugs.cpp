/*
 * Name: James Schvaneveldt
 * Date Submitted: 12/5/23
 * Lab Section: 003
 * Assignment Name: Water Jug Measuring Problem
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

//a set of pass by reference functions that alter a given state per the command
void fillA(state &input){
    input.first = 3;
}

void fillB(state &input){
    input.second = 4;
}

void emptyA(state &input){
    input.first = 0;    
}

void emptyB(state &input){
    input.second = 0;     
}

void pourAToB(state &input){
    while(input.second < 4 && input.first > 0){
        input.first--;
        input.second++;        
    }     
}

// GENERIC (breadth-first search, outward from source_node)
void pourBToA(state &input){
    while(input.first < 3 && input.second > 0){
        input.first++;
        input.second--;        
    }    
}

void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;
  
  while (!to_visit.empty()) {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n";
  } else {
    cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
  }
}

//a a generalized helper function that adds neighboring nodes and their labels
void build_graph_helper(state start, int i){
    state changed = start; //create state to modify
    //based on given index, modify potoential neighbor
    switch(i){
        case 0:
            fillA(changed);
            break;
        case 1:
            fillB(changed);
            break;
        case 2:
            emptyA(changed);
            break;
        case 3:
            emptyB(changed);
            break;
        case 4:
            pourAToB(changed);
            break;
        case 5:
            pourBToA(changed);
            break;
        default:
            break;
    }
    //after neighbor is modified, ensure it is different from starting item
    if(changed != start){
        pair<state, state> label(start, changed); //create pair of states
        nbrs[start].push_back(changed); //add changed item to list of neighbors
        edge_label[label] = actions[i]; //add proper label to change based on index
    }
    
}

//original build_graph function
void build_graph(void)
{
    state start = make_pair(0,0); //oringal case to start from
    int A = 3; //max capacity of jug A
    int B = 4; //max capacity of jug B
    state end = make_pair(A, B); //generate end case for loop
    while(start != end){ //loop through every iteration of combonations until it hits (3,4)
        for(int i = 0; i < 6; i++){ //run through every function
            build_graph_helper(start, i); //adds given case to neighbor and label maps
        }
        if(start.second == B){ //if B hits capacity, increment A and rest B
            start = make_pair(start.first + 1, 0);
        }
        else{ //else, increment B
            start = make_pair(start.first, start.second + 1);
        }
    }
}


/*int main(void)
{
    build_graph();
    state start = make_pair(0,0);
    
    for (int i=0; i<5; i++)
        nbrs[make_pair(i,5-i)].push_back(make_pair(-1,-1));
    search (start);
    if (visited[make_pair(-1,-1)]) 
        print_path (start, pred[make_pair(-1,-1)]);
    else
        cout << "No path!\n";
    
    return 0;
}*/

