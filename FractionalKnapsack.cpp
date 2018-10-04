#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool cmp (struct Item a, struct Item b) {
    double ratio1 = (double) (a.value / a.weight);
    double ratio2 = (double) (b.value / b.weight);
    return ratio1 > ratio2;
}

int main() {
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int allowedWeight = 50;
    int i = 0;
    int n = sizeof(items) / sizeof(items[0]);
    sort(items, items + n, cmp);
    double currentValue = 0.0;
    int currentWeight = 0;
    for (i = 0; i < n; ++i) {
        if (currentWeight + items[i].weight <= allowedWeight) {
            currentValue += items[i].value;
            currentWeight += items[i].weight;
        }
        else {
            int remainingWeight = allowedWeight - currentWeight;
            double valueOfRemainingWeight = items[i].value * (((double)remainingWeight/items[i].weight));
            currentWeight += remainingWeight;
            currentValue += valueOfRemainingWeight;
            break;
        }
    }
    printf("%lf %d", currentValue, currentWeight);
}
