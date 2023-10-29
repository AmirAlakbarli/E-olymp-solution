#include <stdio.h>
#include <set>

using namespace std;

int main()
{
    int n;
    int m;

    set<int> labels;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int label;
        scanf("%d", &label);
        labels.insert(label);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int label;
        scanf("%d", &label);
        labels.insert(label);
    }

    for (auto &label : labels)
    {
        printf("%d ", label);
    }
}