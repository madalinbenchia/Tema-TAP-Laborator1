#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
vector <int> text,index;
vector<stack<int> > stiva;
vector<vector <int> > lista;
vector <int>::iterator it;
int n,p;
bool compara(int a,int b)
{
    return text[b] > text[a];
}
void citire()
{
    int aux;
    f >> n >> p;
    lista.resize(p);
    stiva.resize(p);
    for(int i = 0; i < n; i++)
    {
        f >> aux;
        text.push_back(aux);
        index.push_back(i);
    }
    sort(index.begin(),index.end(),compara);

}
void algoritm_1()
{
    int i, n = n - n % p, j = 0;
    for(i = 0; i < n/2; i++)
    {
        lista[i % p].push_back(text[index[i]]);
        stiva[i % p].push(text[index[n-i-1]]);
    }
    while(j != n % p)
    {
        lista[j].push_back(text[index[i]]);
        ++j;
        ++i;
    }
    for(i = 0; i < n/2; i++)
    {
        lista[i%p].push_back(stiva[i%p].top());
        stiva[i%p].pop();
    }
}
void algoritm_2()
{
    for(int i = 0; i < n; i++)
        lista[i % p].push_back(text[index[i]]);
}
int main()
{
    citire();
    if(n > p * 2)
        algoritm_1();
    else algoritm_2();
    g << '\n';
    for(int i = 0; i < p; i++)
    {
        for(it = lista[i].begin(); it < lista[i].end(); it++)
            g<<*it<<" ";
        g << '\n';
    }
    return 0;
}
