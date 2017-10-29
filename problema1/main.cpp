#include <fstream>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include <stack>
#define NMAX 100
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct cub {
    int latura, culoare, indice;
};

int comp(const void *a, const void*b)
{
    cub c1 = *(cub*)a;
    cub c2 = *(cub*)b;
    return c2.latura - c1.latura;
}

int main()
{  int n, p,i,h=0;
   cub v[NMAX];
   stack<cub> stiva;
   f >> n >> p;
   for(i = 1; i <= n;i++)
   {
        f>>v[i].latura>>v[i].culoare;
        v[i].indice = i;
   }

   qsort(v+1,n,sizeof(cub),comp);
   stiva.push(v[1]);
   g<<v[1].indice<<" ";
   h+=stiva.top().latura;
   for(i = 2;i <= n; i++)
      {
          if(v[i].culoare != stiva.top().culoare)
          {  stiva.push(v[i]);
             g<<v[i].indice<<" ";
             h+=v[i].latura;
          }

      }

   g<<'\n'<<h<<'\n';
   f.close();
   g.close();
   return 0;
}
