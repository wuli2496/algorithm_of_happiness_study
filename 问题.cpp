#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

struct Node
{
    int u;
    int noColorAdjNodes;

    bool operator<(const Node& other) const
    {
        if (noColorAdjNodes != other.noColorAdjNodes)
        {
            return noColorAdjNodes < other.noColorAdjNodes;
        }

        return u > other.u;
    }
};

class Solution
{
public:
    Solution(int vertexes, int edges)
    {
        this->vertexes = vertexes;
        this->edges = edges;
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        verNoColor[u]++;
        verNoColor[v]++;

        return;
    }

    void execute()
    {
        priority_queue<Node> pq;
        for (auto& p: verNoColor)
        {
            Node node;
            node.u = p.first;
            node.noColorAdjNodes = p.second;
            pq.push(node);
        }

        int colorNum = 0;
        vector<int> tmp;
        while (!pq.empty())
        {
            Node curNode = pq.top(); pq.pop();
            if (colors[colorNum].size() == 0)
            {
                colors[colorNum].insert(curNode.u);
                updateNoColorAdjNum(curNode.u);
            }
            else
            {
                bool exist = false;
                 for (auto p: colors[colorNum])
                {
                    if (find(adjList[p].begin(), adjList[p].end(), curNode.u) != adjList[p].end())
                    {
                        exist = true;
                        break;
                    }
                }

                if (!exist)
                {
                    colors[colorNum].insert(curNode.u);
                    updateNoColorAdjNum(curNode.u);
                }
                else
                {
                    tmp.push_back(curNode.u);
                }
            }

            if (pq.empty() && tmp.size() != 0)
            {
                for(auto& node : tmp)
                {
                    Node newNode;
                    newNode.u = node;
                    newNode.noColorAdjNodes = verNoColor[node];
                    pq.push(newNode);
                }
                tmp.clear();
                ++colorNum;
            }
        }

        print();
    }

private:
    void print()
    {
       cout << colors.size() << endl;
       map<int, int> ans;
       for(auto& p : colors)
       {
           for (auto& node : p.second)
           {

               ans[node] = p.first;
           }
       }

       bool first = true;
       for (auto& p: ans)
       {
           if (first)
           {
               first = false;
           }
           else
           {
               cout << " ";
           }
           cout << p.second;
       }
       cout << endl;
    }

    void updateNoColorAdjNum(int u)
    {
        for (size_t i = 0; i < adjList[u].size(); ++i)
        {
            verNoColor[adjList[u][i]]--;
        }
    }
private:
    int vertexes;
    map<int, vector<int>> adjList;
    int edges;
    map<int, set<int>> colors;
    map<int, int> verNoColor;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("f:\\OJ\\data sets\\gc_100_5");
    streambuf* cinback = cin.rdbuf(fin.rdbuf());

    int v, e;
    cin >> v >> e;
    Solution solution(v, e);
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        solution.addEdge(u, v);
    }
    solution.execute();

    cin.rdbuf(cinback);

    return 0;
}
