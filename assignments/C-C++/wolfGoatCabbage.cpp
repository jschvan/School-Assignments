 /*
 * Name: James Schvaneveldt
 * Date Submitted: 12/5/23
 * Lab Section: 003
 * Assignment Name: Rabbit Cabbage Wolf Problem Solver
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <bitset>
using namespace std;

// Reflects what each node represents...
// int with each bit == 0 left of river, bit == 1 right of river
typedef int state;

// Bit position representation for wolf/goat/cabbage/me
bool bit(int x, int i) { return (x>>i) & 1; }
const int wolf=0, goat=1, cabbage=2, me=3;

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

bool goodState(state s){
    if(s == 3 || s == 6 || s == 7 || s == 8 || s == 9 || s == 12){
        return false;
    }
    else{
        return true;
    }
}


// GENERIC (breadth-first search, outward from curnode)
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

string state_string(state s)
{
  string items[4] = { "wolf", "goat", "cabbage", "you" }, result = "";
  for (int i=0; i<4; i++)
    if (!bit(s, i)) result += items[i] + " ";
  result += " |river| ";
  for (int i=0; i<4; i++)
    if (bit(s, i)) result += items[i] + " ";
  return result;
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << state_string(t) << "\n";
  } else {
    cout << "Initial state: " << state_string(s) << "\n";
  }
}

string neighbor_label(int s, int t)
{
  string items[3] = { "wolf", "goat", "cabbage" }, which_cross;
  if (bit(s,me) == bit(t,me)) return "";    // must cross river
  int cross_with = 0;
  for (int i=0; i<3; i++) {
    if (bit(s,i) != bit(t,i) && bit(s,i)==bit(s,me)) { cross_with++; which_cross = items[i]; }
    if (bit(s,i) != bit(t,i) && bit(s,i)!=bit(s,me)) return "";
  }
  if (cross_with > 1) return "";
  if (cross_with == 0) return "Cross alone";
  else return "Cross with " + which_cross;
}

//function to build nbrs and edge_label map sets
void build_graph(void)
{
    bitset<4> state_bs; //creates starter bitset to begin iterations through
    bitset<4> final_bs("1111"); //creates final bitset goal to reach
    for(int j = 0; j < 15; j++){ //runs through every possible bitset
        for(int i = 0; i < 4; i++){ //modifies each bit of the bitset 
            //ensures 'me' is on the same side of bit trying to be modified
            if(state_bs[me] == state_bs[i]){ 
                //creates bitset to check for proximity
                bitset<4> next_bs = state_bs; 
                
                //modifies 'me' bit
                next_bs[me].flip(); 
                
                //if not 'me' bit, flip
                //allows for cases where just 'me' crosses the river
                if(i != me){
                    next_bs[i].flip();
                }
                
                //ensures state is allowed before adding to set
                if(goodState(next_bs.to_ulong())){
                    //converts bitset to int
                    int bs_int = state_bs.to_ulong();
                    int next_int = next_bs.to_ulong();
                    
                    //adds modified bitset to neighbor map for original bitset
                    nbrs[bs_int].push_back(next_int);
                    
                    //create pair and generates label for transition from one to the next
                    pair<state, state> label_pair (bs_int, next_int);
                    //adds to edge label set
                    edge_label[label_pair] = neighbor_label(bs_int, next_int);    
                }
            }
        }
        //imcrements state one step forward
        state_bs = state_bs.to_ulong() + 1;
    }
    
}


/*int main(void)
{
    build_graph();
    state start = 0, end = 15;
    search(start);
    if (visited[end])
        print_path (start, end);
    else
        cout << "No path!\n";
    
    return 0;
}*/

