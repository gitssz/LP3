#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Item
{
public:
    int profit;
    int weight;
    double ratio;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
        this->ratio = (double)profit / weight;
    }
};

class KnapsackNode
{
public:
    vector<int> items;
    int profit;
    int weight;
    KnapsackNode(vector<int> items, int profit, int weight)
    {
        this->items = items;
        this->profit = profit;
        this->weight = weight;
    }
};

class Knapsack
{
public:
    int maxWeight;
    vector<Item> items;
    Knapsack(int maxWeight, vector<Item> items)
    {
        this->maxWeight = maxWeight;
        this->items = items;
    }
    int solve()
    {
        sort(this->items.begin(), this->items.end(), [](const Item &a, const Item &b)
             { return a.ratio > b.ratio; });
        int bestprofit = 0;
        queue<KnapsackNode> q;
        q.push(KnapsackNode({}, 0, 0));
        while (!q.empty())
        {
            KnapsackNode node = q.front();
            q.pop();
            int i = node.items.size();
            if (i == this->items.size())
            {
                bestprofit = max(bestprofit, node.profit);
            }
            else
            {
                Item item = this->items[i];
                KnapsackNode withItem(node.items, node.profit + item.profit,
                                      node.weight + item.weight);
                if (isPromising(withItem, this->maxWeight, bestprofit))
                {
                    q.push(withItem);
                }
                KnapsackNode withoutItem(node.items, node.profit, node.weight);
                if (isPromising(withoutItem, this->maxWeight, bestprofit))
                {
                    q.push(withoutItem);
                }
            }
        }
        return bestprofit;
    }
    bool isPromising(KnapsackNode node, int maxWeight, int bestprofit)
    {
        return node.weight <= maxWeight && node.profit + getBound(node) >
                                               bestprofit;
    }
    int getBound(KnapsackNode node)
    {
        int remainingWeight = this->maxWeight - node.weight;
        int bound = node.profit;
        for (int i = node.items.size(); i < this->items.size(); i++)
        {
            Item item = this->items[i];
            if (remainingWeight >= item.weight)
            {
                bound += item.profit;
                remainingWeight -= item.weight;
            }
            else
            {
                bound += remainingWeight * item.ratio;
                break;
            }
        }
        return bound;
    }
};

int main()
{
    vector<Item> items = {
        Item(60, 10),
        Item(100, 20),
        Item(120, 30)};
    Knapsack knapsack(50, items);
    int result = knapsack.solve();
    cout << "Best profit: " << result << endl;
    return 0;
}

