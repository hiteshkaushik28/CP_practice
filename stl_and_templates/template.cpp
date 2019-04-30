//FOR Fast input

static string s=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return "";
}(); 

// matrix initialization for size [m+1][n+1]
sums.resize(m+1, vector<int>(n+1, 0));



//MIN heap using priority queue
priority_queue<template, std::vector<template>, std::greater<template> > my_min_heap;





//To convert to binary and then to int
uint32_t int2binary2int(uint32_t n) 
    {
        bitset<32> x(n); 	// convert n into binary and store it in bitset of size 32   
        return x.to_ulong();
    }



/*Check if there is only one bit set in n*/
  if ( n && !(n&(n-1)) )
  		return true




// position of first set bit
unsigned int getFirstSetBitPos(int n)
{
   return log2(n&-n)+1;
}
 



//To take unknown number of input and store it in vector
do
    {
        int input ;
        if ( std::cin >> input )
            v.push_back(input) ;
    } while (std::cin.peek() != '\n' ) ;		//peek is used to check the next input coming in input stream



//---------------------------------------------------------------
				Matrix Exponetiation
//---------------------------------------------------------------

Now, there is a method to calculate the nth fibonacci number in O(log(n)) time. 
For this you need the basics of matrix exponentiation. 
Check out the following matrix The nth fibonacci number can be found using this matrix also 
if we apply repeated squaring to this matrix, the solution is reduced to O(log(n))

long long fibonacci(int n)
{
    long long fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
    int i,j,k;
    while(n)
    {
        if(n&1)
        {
            memset(tmp,0,sizeof tmp);
            for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j]);
            
            for(i=0; i<2; i++) for(j=0; j<2; j++) ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof tmp);

        for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j]);
        
        for(i=0; i<2; i++) for(j=0; j<2; j++) fib[i][j]=tmp[i][j];
        n/=2;
    }
    return (ret[0][1]);
}












//-----------------------------------------------------------
void kadane_max(vector <int> v,int n)
{
	int maximum=0,max_so_far=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int x=v[i];
            maximum+=x;
            max_so_far=max(max_so_far,maximum);           
            
            if(maximum < 0)
            {
                maximum=0;
            }
           
        }
        cout<<max_so_far<<endl;
}










void kadane_min(vector<int> arr,int n)
{
    
    int min_ending_here = INT_MAX;
    int min_so_far = INT_MAX;
     
    for (int i=0; i<n; i++)
    {
        // if min_ending_here > 0, then it could not possibly
        // contribute to the minimum sum further
        if (min_ending_here > 0)
            min_ending_here = arr[i];
         
        // else add the value arr[i] to min_ending_here 
        else
            min_ending_here += arr[i];
         
        min_so_far = min(min_so_far, min_ending_here);          
    }
     
    cout<<min_so_far;
}


//----------------------------------------------------------
//                Next Permutation inplace shifting
//----------------------------------------------------------
void nextPermutation(vector<int>& nums) {
    if(is_sorted(nums.rbegin(),nums.rend())){
        sort(nums.begin(),nums.end());
        return ;
    }
    
    for(int i=nums.size()-1;i>0;i--){
        if(nums[i-1]<nums[i]){
            int mini = INT_MAX;
            int index;
            for(int j=i;j<nums.size();j++){
                if(nums[j]>nums[i-1] && nums[j]<mini){
                    mini = nums[j];
                    index = j;
                }
            }
            swap(nums[i-1],nums[index]);
            
            sort(nums.begin()+i,nums.end());
            break;
        }
    }    
}











//------------------------
void permutations(string str, int i, int n)
{
    // base condition
    if (i == n - 1){
        cout << str << endl;
        return;
    }

    // process each character of the remaining string
    for (int j = i; j < n; j++){
        swap(str[i], str[j]);             // swap character at index i with current character
        permutations(str, i + 1, n);        // recurse for string [i+1, n-1]
        swap(str[i], str[j]);           // backtrack (restore the string to its original state)
    }
}

int main(){             // Find all Permutations of a string
    string str = "ABC";
    permutations(str, 0, str.length());
    return 0;
}





//----------------------------------------------------------
//                 Combination subset sum (B is the target)
//----------------------------------------------------------
void subset_sum(vector<int>&A,int B,vector<int>&temp,set<vector<int>>&ans,int x){
    
    if(B==0){
        ans.insert(temp);
        return;
    }

    for(int i=x;i<A.size();i++){
        if(B-A[i]>=0){
            temp.push_back(A[i]);
            subset_sum(A,B-A[i],temp,ans,i);
            temp.pop_back();
        }
    }
    return;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

    vector<int>temp;
    set<vector<int>>ans;
    sort(A.begin(),A.end());
    subset_sum(A,B,temp,ans,0);
    vector<vector<int>> res(ans.begin(),ans.end());
    return res;
}







//-------------------------------------
		Sieve of Eratosthenes 	Time: O(n log log n)
//------------------------------------

void SieveOfEratosthenes(int n)		//find prime number from 0<=n
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;		// all true are answer
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}










//-------------------------------------
	 Brian Kernighan’s Algorithm:			time: O(logn)
//-------------------------------------
Subtraction of 1 from a number toggles all the bits (from right to left)
 till the rightmost set bit(including the righmost set bit). 
So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)),
 we unset the righmost set bit. If we do n & (n-1) in a loop and count 
 the no of times loop executes we get the set bit count.


unsigned int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}


// Other approach using lookup table 	O(1)
#include <iostream>
using namespace std;
 
int main()
{
   cout << __builtin_popcount (4) << endl;
   cout << __builtin_popcount (15);
 
   return 0;
}









//-------------------------------------
		Binomial Coefficient 	Time: O(k) Space: O(1)
//------------------------------------

int binomialCoeff(int n, int k)
{
    int res = 1;
    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}



//-------------------------------------
		GCD 			Time  O(Log min(a, b))
//------------------------------------

int gcd(int a,int b)	/*Fuction to get gcd of a and b*/
{
   if(b==0)
     return a;
   else
     return gcd(b, a%b);
}









//-------------------------------------
		Juggling algorithm 			time O(n) space(1) 
//------------------------------------

void leftRotate(int arr[], int d, int n)	/*Function to left rotate arr[] of siz n by d*/
{
  int i, j, k, temp;
  for (i = 0; i < gcd(d, n); i++)
  {
    /* move i-th values of blocks */
    temp = arr[i];
    j = i;
    while(1)
    {
      k = j + d;
      if (k >= n)
        k = k - n;
      if (k == i)
        break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}






//------------------------------------------------
				SEGMENT TREE( find min )
//------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  int l;
  int h;
  node *right;
  node *left;  
};    

node* construct(int arr[],int low,int high)
{    
     if(low==high)
    {
        node *temp=new node();
        temp->data=arr[low];
        temp->l=low;
        temp->h=low;
        temp->left=NULL;
        temp->right=NULL;
      
        return temp;
    }  
  
    else
    {
        node *temp=new node();
        //int mid=(low+high)/2;
        int mid=low+(high-low)/2;
        temp->left=construct(arr,low,mid);
        temp->right=construct(arr,mid+1,high);
        temp->l=low;
        temp->h=high;
        temp->data=(temp->left->data > temp->right->data)?temp->right->data:temp->left->data;
        return temp;
    }
     
    return 0;
}    

int find_min(node *root,int x,int y)
{
    if(root->l >= x && root->h <= y)
        return root->data;
    else if(root->l >y || root->h < x)
        return 5000000;
    else
    {
       int p=find_min(root->left,x,y);
        int q=find_min(root->right,x,y);
        return (p<q)?p:q;
    }    
}  

int main() 
{
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    node *root;//=new node();
    root=construct(arr,0,n-1);
    while(q--)
    {
        int low,high;
        cin>>low>>high;
        cout<<find_min(root,low,high)<<endl;
    }    
    return 0;
}





























void DFS(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}







void BFS(int s)			//starting vertex
{    
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;
 
    while(!queue.empty())
    {        
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

//---------------------------------------------------------

LEVEL ORDER AND HEIGHT
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}


void printLevelOrder(struct node* root) 	//call this from main
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}




















//------------------------------------------------
				TRIE
//------------------------------------------------

// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;
 
const int ALPHABET_SIZE = 26;
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
 
// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}
 
// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getNode();
 
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
}




















//------------------------------------------------
				TERNARY SEARCH TREE (TST)
//------------------------------------------------
// C program to demonstrate Ternary Search Tree (TST) insert, travese 
// and search operations
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
 
// A node of ternary search tree
struct Node
{
    char data;
 
    // True if this character is last character of one of the words
    unsigned isEndOfString: 1;
 
    struct Node *left, *eq, *right;
};
 
// A utility function to create a new ternary search tree node
struct Node* newNode(char data)
{
    struct Node* temp = (struct Node*) malloc(sizeof( struct Node ));
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}
 
// Function to insert a new word in a Ternary Search Tree
void insert(struct Node** root, char *word)
{
    // Base Case: Tree is empty
    if (!(*root))
        *root = newNode(*word);
 
    // If current character of word is smaller than root's character,
    // then insert this word in left subtree of root
    if ((*word) < (*root)->data)
        insert(&( (*root)->left ), word);
 
    // If current character of word is greate than root's character,
    // then insert this word in right subtree of root
    else if ((*word) > (*root)->data)
        insert(&( (*root)->right ), word);
 
    // If current character of word is same as root's character,
    else
    {
        if (*(word+1))
            insert(&( (*root)->eq ), word+1);
 
        // the last character of the word
        else
            (*root)->isEndOfString = 1;
    }
}
 
// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(struct Node* root, char* buffer, int depth)
{
    if (root)
    {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);
 
        // Store the character of this node
        buffer[depth] = root->data;
        if (root->isEndOfString)
        {
            buffer[depth+1] = '\0';
            printf( "%s\n", buffer);
        }
 
        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(root->eq, buffer, depth + 1);
 
        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth);
    }
}
 
// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(struct Node* root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}
 
// Function to search a given word in TST
int searchTST(struct Node *root, char *word)
{
    if (!root)
        return 0;
 
    if (*word < (root)->data)
        return searchTST(root->left, word);
 
    else if (*word > (root)->data)
        return searchTST(root->right, word);
 
    else
    {
        if (*(word+1) == '\0')
            return root->isEndOfString;
 
        return searchTST(root->eq, word+1);
    }
}
 
// Driver program to test above functions
int main()
{
    struct Node *root = NULL;
 
    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");
 
    printf("Following is traversal of ternary search tree\n");
    traverseTST(root);
 
    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    searchTST(root, "cats")? printf("Found\n"): printf("Not Found\n");
    searchTST(root, "bu")?   printf("Found\n"): printf("Not Found\n");
    searchTST(root, "cat")?  printf("Found\n"): printf("Not Found\n");
 
    return 0;
}























//------------------------------------

		UNION AND FIND
https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/		
//------------------------------------


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}



















//------------------------------------------------
				DJKSTRA
//------------------------------------------------


#include <bits/stdc++.h>
using namespace std;
int n,m;
typedef pair<int,int> Pair;
void djkstra(vector<vector<pair<int,int>>>v)
{
    priority_queue< Pair, vector <Pair> , greater<Pair> > pq;
    vector<int> visit(n+1,0);
    vector<long long int>ways(n+1,1);
    vector<int> dj(n+1,21400);
    
    pq.push(make_pair(0,1));
    dj[1]=0;
    int node=1;
    
    while(!pq.empty())
    {
        int start=pq.top().second;
        pq.pop();
      
        if(visit[start]==0)
        {    
            visit[start]=1;
            vector<pair<int,int>>::iterator i;
            for(i=v[start].begin();i!=v[start].end();i++)
            {
                int end=(*i).first;
                int w=(*i).second;
               
                if(dj[end] > dj[start] + w)
                {
                   
                        dj[end]=dj[start]+w;
                        ways[end]=1;
                        pq.push(make_pair(dj[end],end));
                    
                }     
            }    
        }   
     }   
}    

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        
        cin>>n>>m;
        vector<vector<pair<int,int>>> v(n+1);
        for(int i=0;i<m;i++)
        {
            int s,d,w;
            cin>>s>>d>>w;
            v[s].push_back(make_pair(d,w));
            v[d].push_back(make_pair(s,w));
        }    
        vector<pair<int,int>>::iterator it;
    
        djkstra(v);
    }    
    return 0;
}




















//------------------------------------------------
				KOSA RAJU
//------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void find(int pos,vector<vector<int>> &v,stack<int> &s,vector<int> &visit)
{
    visit[pos]=1;
    for(int i=0;i<v[pos].size();i++)
    {
        if(!visit[v[pos][i]])
            find(v[pos][i],v,s,visit);
    }
    s.push(pos);
}

void dfs(int pos,vector<vector<int>> &rv,vector<int> &visit,vector<vector<int>> &ans,int y)
{
    visit[pos]=1;
    ans[y].push_back(pos);
    for(int i=0;i<rv[pos].size();i++)
    {
        if(!visit[rv[pos][i]])
            dfs(rv[pos][i],rv,visit,ans,y);
    }
}

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;        
        cin >> n>> m;
        
        vector<vector<int>>v(n+1);
        vector<vector<int>>rv(n+1);
        vector<int>visit(n+1,0);
        stack<int> stack1;
        
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x>> y;
            v[x].push_back(y);
            rv[y].push_back(x);
        }
        
        for(int i=0;i<=n;i++)
            visit[i]=0;
        
        for(int i=1;i<=n;i++)
        {
            if(!visit[i])
                find(i,v,stack1,visit);
        }
        
        for(int i=0;i<=n;i++)
            visit[i]=0;
        
        while(!stack1.empty())
        {
            int y=stack1.top();
            stack1.pop();
            if(!visit[y])
            {
                dfs(y,rv,visit,ans,y);
            }
        }
        
        // do something here
    }
    return 0;
}


//------------------------------------------------
				TARJAN
//------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int flag=0;
int flag1=0;
int n,m;
   
void tarjan(int u,vector<int> &initial, vector<int> &ances, stack<int> &st, vector<bool> &stackM,vector<int>v[],vector<int>&pv)
{
	static int time=0;
	initial[u]=ances[u]=++time;
	
	st.push(u);
	stackM[u]=true;
	
	vector<int>::iterator it;
	for(it=v[u].begin();it!=v[u].end();it++)
	{
		int x=*it;
        if(x==0)continue;
      
		if(initial[x]==-1)
		{
			tarjan(x,initial,ances,st,stackM,v,pv);
			ances[u]=min(ances[u],ances[x]);
		}	
		
		else if(stackM[x]==true)
			ances[u]=min(ances[u],initial[x]);
	}
	
	int w=0;
	if(ances[u] ==initial[u])
	{
		
        while(st.top()!=u)
		{
			w=st.top();
			stackM[w]=false;
			st.pop();
		}
		w=st.top();
        stackM[w]=false;
		st.pop();
	}
}

int main() 
{
    cin>>n>>m;
    vector <int> v[n+1];
    
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        
    }    
    vector <int> initial(n+2,-1);
    vector <int> ances(n+2,-1);
    vector <bool> stackM(n+2,false);
    vector <int> pv(n+2,0);
    stack <int> st;
       
    for(int i=1;i<=n;i++)
    {    
		if(initial[i]==-1)
			tarjan(i,initial,ances,st,stackM,v,pv);
	}		
    return 0;
}











//--------------------------------------------------------
		Min heap
//------------------------------------------------------------




//---------------------------------------------------------
		Vector implementation
//---------------------------------------------------------


------> vector.c
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void vector_init(vector *v)
{
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
}

int vector_total(vector *v)
{
    return v->total;
}

static void vector_resize(vector *v, int capacity)
{
    #ifdef DEBUG_ON
    printf("vector_resize: %d to %d\n", v->capacity, capacity);
    #endif

    void **items = realloc(v->items, sizeof(void *) * capacity);
    if (items) {
        v->items = items;
        v->capacity = capacity;
    }
}

void vector_add(vector *v, void *item)
{
    if (v->capacity == v->total)
        vector_resize(v, v->capacity * 2);
    v->items[v->total++] = item;
}

void vector_set(vector *v, int index, void *item)
{
    if (index >= 0 && index < v->total)
        v->items[index] = item;
}

void *vector_get(vector *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->items[index];
    return NULL;
}

void vector_delete(vector *v, int index)
{
    if (index < 0 || index >= v->total)
        return;

    v->items[index] = NULL;

    for (int i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)
        vector_resize(v, v->capacity / 2);
}

void vector_free(vector *v)
{
    free(v->items);
}



------> Driver program

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main(void)
{
    int i;

    vector v;
    vector_init(&v);

    vector_add(&v, "Bonjour");
    vector_add(&v, "tout");
    vector_add(&v, "le");
    vector_add(&v, "monde");

    for (i = 0; i < vector_total(&v); i++)
        printf("%s ", (char *) vector_get(&v, i));
    printf("\n");

    vector_delete(&v, 3);
    vector_delete(&v, 2);
    vector_delete(&v, 1);

    vector_set(&v, 0, "Hello");
    vector_add(&v, "World");

    for (i = 0; i < vector_total(&v); i++)
        printf("%s ", (char *) vector_get(&v, i));
    printf("\n");

    vector_free(&v);
}




























//---------------------------------------------------------
		Unordered map implementation (HASH)
https://www.codeproject.com/Articles/866996/Fast-Implementations-of-Maps-with-Integer-Keys-in		
//---------------------------------------------------------


include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem {
   int data;   
   int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
   return key % SIZE;
}

struct DataItem *search(int key) {
   //get the hash 
   int hashIndex = hashCode(key);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(int key,int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   int key = item->key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->key = -1; 

   insert(1, 20);
   insert(2, 70);
   insert(42, 80);
   insert(4, 25);
   insert(12, 44);
   insert(14, 32);
   insert(17, 11);
   insert(13, 78);
   insert(37, 97);

   display();
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

   delete(item);
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }
}



// subarray template
/*
https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
*/
int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
  }

One thing needs to be mentioned is that when asked to find maximum substring, 
we should update maximum after the inner while loop to guarantee that the substring is valid. 
On the other hand, when asked to find minimum substring, we should update minimum inside the inner while loop.

int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int counter=0, begin=0, end=0, d=0; 
        while(end<s.size()){
            if(map[s[end++]]++>0) counter++; 
            while(counter>0) if(map[s[begin++]]-->1) counter--;
            d=max(d, end-begin); //while valid, update d
        }
        return d;
    }


//----------------------------------------------------------------
            Binary search on matrix with sorted data. find kth smallest
//-----------------------------------------------------------------
public int kthSmallest(int[][] matrix, int k) {
        int lo = matrix[0][0], hi = matrix[matrix.length - 1][matrix[0].length - 1] + 1;//[lo, hi)
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0,  j = matrix[0].length - 1;
            for(int i = 0; i < matrix.length; i++) {
                while(j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }
            if(count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }



//----------------------------------------------------------------
            Manachar Algorithm  O(n)
//-----------------------------------------------------------------
 string longestPalindrome(string s1) {
         string s = "$#";
        for(int i=0;i<s1.length();i++){
            s+=s1[i];
            s+='#';
        }
        s+='@';
        //cout<<s;
        vector<int>p(s.length(),0);
        int c=0,r=0;
        int ans = INT_MIN;
        int index = 0;
        
        for(int i=1;i<s.length()-1;i++){
            int mirr = 2*c - i;
            
            if(r>i)
                p[i] = min(r-i,p[mirr]);
            
            while(s[i-(p[i] + 1)] == s[i+(p[i] + 1)] )
                p[i]++;
            
            if(i + p[i] > r){
                r = i + p[i];
                c = i;
            }
            
            if(ans<p[i]){
                index = i;
                ans = p[i];
            }
        }
        //cout<<index<<" "<<ans;
        string ans1 = "";
        for(int i=index-((ans-1));i<=index+((ans-1));i++){
            if(s[i]!='#' && s[i]!='@' && s[i]!='$')
                ans1+=s[i];
        }
        return ans1;    




//-------------------------------------------------------------------------------------------------------------------------------------
                    LINKS
//-------------------------------------------------------------------------------------------------------------------------------------        
Trial and error algo(Binary search kth smallest)
    -->https://leetcode.com/problems/find-k-th-smallest-pair-distance/discuss/109082/Approach-the-problem-using-the-%22trial-and-error%22-algorithm

Find a repeating and a missing number
    -->https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/    