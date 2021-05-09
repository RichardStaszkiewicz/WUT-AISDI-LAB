#include <bits/stdc++.h>

using namespace std;

const int R=1e9+7;
vector<vector<pair<int,int> > > V;
int tab[1000000];
void djk(int a)
{
    priority_queue<pair<int, int> > queue;
    queue.push(make_pair(0,a));
    while(!queue.empty())
    {
        pair<int,int> x = queue.top();
        queue.pop();
        for(auto it: V[x.second])
        {
            if(tab[it.first]>tab[x.second]+it.second)
            {
                tab[it.first]=tab[x.second]+it.second;
                queue.push(make_pair(-tab[it.first], it.first));
            }
        }
    }
}
int main()
{
    return 0;
}