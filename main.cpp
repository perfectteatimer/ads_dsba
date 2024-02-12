#include <iostream>
#include <vector>

struct UnionFind // disjoint sets forest
{
    UnionFind(int n) : sz(n)
    {
        // resize the vector r to n elements each of them with value 0
        r.resize(n, 0);

        for (int i = 0; i < n; i++)
            p.push_back(i);
    }

    // return the leader of x, which represents the set where x belongs
    int find(int x)
    {
        return p[x] != x ? find(p[x]) : x;
    }

    // union the set where x belongs with the set where y belongs
    void join(int x, int y)
    {
        // replace x and y with their leaders
        x = find(x);
        y = find(y);

        // corner case: if x and y are the same value, then we do not do anything
        if (x == y)
            return;

        // merging two sets into one, so we reduce by 1 the number of disjoint sets
        sz--;

        // link operation
        if (r[x] > r[y])
        {
            p[y] = x;
        }else
        {
            p[x] = y;
            if (r[x] == r[y])
                r[y]++;
        }
    }

    int count()
    {
        return sz;
    }

    void print()
    {
        std::cout << "parent vector: " << std::endl;
        for (int i = 0; i < p.size(); i++)
            std::cout << p[i] << ' ';
        std::cout << std::endl;

        std::cout << "rank vector: " << std::endl;
        for (int i = 0; i < r.size(); i++)
            std::cout << r[i] << ' ';
        std::cout << std::endl;
    }


    int sz; // size - number of disjoint sets

    // parent vector
    std::vector<int> p; // p[i]: parent of i-th node
    std::vector<int> r; // r[i]: rank of i-th node
};

// 3
// 0 1
// 1 2
// 2 0
// return true if it has a cycle. False otherwise.
bool hasCycle(int n, std::vector<std::pair<int,int>> edges)
{
    UnionFind s(n);
    for(auto edge : edges)
    {
        if(s.find(edge.first) == s.find(edge.second))
            return true;
        s.join(edge.first, edge.second);
    }
    return false;
}

// 2
// 0 1
// 0 2
// 3 4

// Check nmber of connected components in a graph of n nodes
int countComponents(int n, std::vector<std::pair<int,int>> edges)
{
    UnionFind s(n);
    for(auto edge : edges)
        s.join(edge.first, edge.second);
    return s.count();
}

// Check if a graph is a Tree. Returns true if the graph is a tree. Else, returns false
// 2
// 0 1
// 0 2
// 3 4


bool isTree(int n, std::vector<std::pair<int,int>> edges)
{
    return countComponents(n, edges) == 1 && !hasCycle(n, edges);
}


int main()
{
    // create 5 disjoint sets
    UnionFind mySets(5);

    mySets.join(0,1);
    mySets.join(2,3);
    mySets.join(0,2);
    mySets.join(3,4);

    std::cout << "number of disjoint sets: " << mySets.count() << std::endl;

    mySets.print();

    return 0;
}