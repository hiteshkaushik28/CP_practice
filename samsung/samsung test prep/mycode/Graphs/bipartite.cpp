#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *nxt;

    // constructor
    node(int d, node* n = NULL)
    {
        data = d;
        nxt = n;
    }
};

class queue {
public:
    node *head;
    node *rear;

    // default constructor
    queue()
    {
        head = rear = NULL;
    }

    void push(int x);
    void pop();
    int front() { return head->data; }
    bool empty() { return head == NULL; }
};

void queue::push(int x) {
    node *tmp = new node(x);
    if(rear)
        rear->nxt = tmp;
    rear = tmp;
    if(!head)
        head = rear;
}

void queue::pop() {
    node *tmp = head;
    if(head == rear)
        head = rear = NULL;
    else
        head = head->nxt;
    delete tmp;
}

int n;
int graph[110][110];

bool isbipartite(){
    //0 -> 1st color;
	//1 -> 2nd color; 
	//-1 -> no color; 
    int color[n];
    for(int i=0;i<n;i++)
        color[i] = -1;
    color[0] = 1;
    queue q;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if (graph[u][i] == 1) {
                if(color[i] == -1){
                    color[i] = 1 - color[u];
                    q.push(i);
                }
                else if(color[i] == color[u]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    cout << isbipartite() << "\n";
    return 0;
}