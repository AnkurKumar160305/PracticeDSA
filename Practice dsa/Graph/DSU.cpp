// DSU - Disjoint Set Union is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. It provides two primary operations: Find and Union. The Find operation determines which subset a particular element is in, while the Union operation merges two subsets into a single subset. DSU is commonly used in graph algorithms, such as Kruskal's algorithm for finding the minimum spanning tree and detecting cycles in undirected graphs.
// DSU helps to find number of components in a graph and also helps to find if two nodes are connected or not in a graph. It is also used in many other applications like network connectivity, image processing, and clustering.
//Time complexity of DSU is O(4*alpha(n)) where alpha(n) is the inverse Ackermann function which grows very slowly and is considered constant for all practical purposes. So, the time complexity of DSU operations can be considered as O(1) on average.
///There are two methods to find the parent of a node in DSU: Path Compression and Union by Size/Rank. Path Compression is a technique that flattens the structure of the tree whenever Find is called, making future queries faster. Union by Size/Rank is a technique that always attaches the smaller tree under the root of the larger tree, keeping the overall tree height small.

class DisJointSet{
    public:

    vector<int> parent,size;

    DisJointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }


    void Union(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv){
            return;
        }

        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};