#include <fstream>
#include<stdlib.h>
#include<stdio.h>
#define NMAX 1000
using namespace std;
ifstream f("date.in");
ofstream g("date.out");

struct text {
    int lungime,frecventa,indice;
};

int comp(const void *a, const void *b)
{
    text t1 = *(text*)a;
    text t2 = *(text*)b;
    return t2.frecventa/t2.lungime - t1.frecventa/t1.lungime;

}
int main()
{
    int n,i,p;
    text v[NMAX];
    f >> n;
    for(i = 1; i <= n; i++)
    {
        f >> v[i].lungime >> v[i].frecventa;
        v[i].indice = i;
    }

    qsort(v+1,n,sizeof(text),comp);
    for(i = 1; i <= n; i++) g << v[i].indice<<" ";
    g << '\n';

    f >> p;

    f.close();
    g.close();
    return 0;
}
