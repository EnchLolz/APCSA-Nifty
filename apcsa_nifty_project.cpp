//header
#include <bits/stdc++.h>
using namespace std;

//constants
#define INF 2e9
#define INF2 4e18
#define MOD 1e9+7
#define MOD2 998244353

//macros
#define nl '\n'
#define se second
#define fi first
#define pb push_back

typedef string str;
typedef pair<int,int> pii;
typedef pair<str,int> psi;
typedef long long ll;

//node structure
struct node{
    str name;
    int type;
    ll out;
    ll in;
    ll level;
    vector<str> pointsto;
    vector<str> pointsfrom;
};

//prints a vector with commas and and
void printlist(vector<str> v){
    int len = v.size();
    if(len>1){
        for(int i=0;i<len-2;i++){
            cout<<v[i]<<", ";
        }
        cout << v[len-2] << " and " << v[len-1] << endl;
    }
    else if(len == 1){
        cout << v[0] << endl;
    }
    else{
        cout << endl;
    }
    return;
}

//graph class
class Graph{
    public:
        //graph values
        str type;
        int nodes;
        int edges;
        //constructor
        Graph(str t){
            this->type = t;
            this->nodes = 0;
            this->edges = 0;
            this->output["food"] = {"Predators and Prey: ","eats","Apex Predators: ","Producers: ","Intermediates: ","Most Flexible Eaters: ","Tastiest: ","Herbivores: ","Omnivores: ","Carnivores: "};
            this->output["zombie"] = {"Contact Records:","had contact with","Patient Zeros: ","Potential Zombies: ","Neither Patient Zero or Potential Zombie: ","Most Viral People: ","Tastiest: ","Spreader Zombies: ","Regular Zombies: ","Zombie Predators: "};
        }
        //adds a node to the graph
        void addNode(str v){
            this->nodes++;
            this->names[v].name = v;
        }
        //adds a directed edge from a to b
        void addEdge(str a, str b){
            this->edges++;
            //if b doest not exist
            if(this->names.find(b) == this->names.end()){
                this->addNode(b);
                this->names[b].in++;
                this->names[a].out++;
                this->names[b].pointsfrom.pb(a);
                this->names[a].pointsto.pb(b);
            }
            //if b exists
            else{
                this->names[b].in++;
                this->names[a].out++;
                this->names[b].pointsfrom.pb(a);
                this->names[a].pointsto.pb(b);
            }
        }
        //prints according to the problem specification
        void print(){
            //resets containers
            this->detectType();
            this->root.clear();
            this->internal.clear();
            this->leaf.clear();
            this->mostout.clear();
            this->mostin.clear();
            this->type1.clear();
            this->type2.clear();
            this->type3.clear();
            //adds stuff to the containers
            int maxout = 0;
            int maxin = 0;
            for(auto it:names){
                if(it.se.out == 0){
                    this->leaf.pb(it.fi);
                }
                if(it.se.in == 0){
                    this->root.pb(it.fi);
                }
                if(it.se.out > 0 && it.se.in > 0){
                    this->internal.pb(it.fi);
                }
                if(it.se.out > maxout){
                    maxout = it.se.out;
                    this->mostout.clear();
                    this->mostout.pb(it.fi);
                }
                else if(it.se.out == maxout){
                    this->mostout.pb(it.fi);
                }
                if(it.se.in > maxin){
                    maxin = it.se.in;
                    this->mostin.clear();
                    this->mostin.pb(it.fi);
                }
                else if(it.se.in == maxin){
                    this->mostin.pb(it.fi);
                }
                if(it.se.type == 1){
                    this->type1.pb(it.fi);
                }
                else if(it.se.type == 2){
                    this->type2.pb(it.fi);
                }
                else if(it.se.type == 3){
                    this->type3.pb(it.fi);
                }
            }
            //printing
            cout << this->output[type][0]<< endl;
            for(auto it: this->names){
                if(it.se.pointsto.size()>0){
                    cout << "    " << it.first << " " << this->output[type][1] << " ";
                    printlist(it.se.pointsto);
                }
            }
            cout << endl << this->output[type][2];
            printlist(this->root);
            cout << this->output[type][3];
            printlist(this->leaf);
            cout << this->output[type][4];
            printlist(this->internal);
            cout << this->output[type][5];
            printlist(this->mostout);
            cout << this->output[type][6];
            printlist(this->mostin);
            cout << endl << "Heights: " << endl;
            for(auto it: this->names){
                cout << "    " << it.first << ": " << it.second.level << endl;
            }
            cout << endl << "Types: " << endl;
            cout << "    " << this->output[type][7];
            printlist(this->type1);
            cout << "    " << this->output[type][8];
            printlist(this->type2);
            cout << "    " << this->output[type][9];
            printlist(this->type3);
        }

    private:
        //important containers for output
        vector<str> topologicalOrder;
        map<str,node> names;
        vector<str> root;
        vector<str> internal;
        vector<str> leaf;
        vector<str> mostout;
        vector<str> mostin;
        vector<str> type1;
        vector<str> type2;
        vector<str> type3;
        map<str,vector<str>> output;
        //topologically sorts the graph in reverse order
        void topologicalSort(){
            this->topologicalOrder.clear();
            unordered_map<str,int> deg;
            queue<psi> q;
            //finds nodes of degree 0
            for(auto it : this->names){
                deg[it.fi] = it.se.out;
                if(it.se.out == 0){
                    q.push({it.fi,0});
                }
            }
            //main algorithm
            while(!q.empty()){
                str v = q.front().fi;
                int level = q.front().se;
                this->topologicalOrder.pb(v);
                this->names[v].level = level;
                for(auto it : this->names[v].pointsfrom){
                    deg[it]--;
                    if(deg[it] == 0){
                        q.push({it,level+1});
                    }
                }
                q.pop();
            }
        }
        //detects the type of each node with dp and topological sort
        void detectType(){
            this->topologicalSort();
            for(auto it : this->topologicalOrder){
                bool has0 = false;
                bool has1 = false;
                for(auto it2 : this->names[it].pointsto){
                    if(this->names[it2].type == 0){
                        has0 = true;
                    }
                    else{
                        has1 = true;
                    }
                }
                if(has0 && has1){
                    this->names[it].type = 2;
                }
                else if(has1){
                    this->names[it].type = 3;
                }
                else if(has0){
                    this->names[it].type = 1;
                }
                else{
                    this->names[it].type = 0;
                }
            }
        }
};


//takes and interprets the input
void input(Graph &graph){
    str s;
    while(getline(cin,s,'\r')){
        //parent
        stringstream ss(s);
        str vertex;
        getline(ss, vertex, ',');
        graph.addNode(vertex);
        //children
        while (ss.good()) {
            str substr;
            getline(ss, substr, ',');
            graph.addEdge(vertex, substr);
        }
        cin.ignore();
    }
    return;
}

//Asumes that the graph is a DAG and fully complete
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //inputting the files
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //what type of graph is it?
    str type = "type";
    //graph object
    Graph graph(type);
    //inputting the graph
    input(graph);
    //outputting the answer
    graph.print();
    return 0;
}

//~Nathan Ye
