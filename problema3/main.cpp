#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

 struct Element {
    int profit, pos,time;
 };

bool cmp(Element &a, Element &b) {
    if (a.time == b.time) {
        return a.profit > b.profit;
    }
    return a.time < b.time;
}

int main()
{
    int n;
    f >> n;
    vector<Element> actv(n);

    for (auto it = actv.begin(); it != actv.end(); ++it) {
        Element activity;

        f >> activity.profit >> activity.time;

        activity.pos = it - actv.begin() + 1;
        *it = activity;
    }



    sort(actv.begin(), actv.end(), cmp);

    int time = 0, profit = 0;
    vector<int> chosen;

    for (auto i : actv) {
        if (i.time > time) {
            profit += i.profit;
            chosen.push_back(i.pos);
            ++time;
        }
    }


    g << profit << '\n';

    for (auto i : chosen) {
        g << i << ' ';
    }

    g << '\n';
    f.close();
    g.close();

    return 0;
}
