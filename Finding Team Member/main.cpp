#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct item_t
{
    int strength;
    int i;
    int j;
};

class item_t_compare
{
  public:
    bool operator()(const item_t &lhs, const item_t &rhs) const
    {
        return lhs.strength < rhs.strength;
    }
};

typedef priority_queue<item_t, vector<item_t>, item_t_compare> item_queue;

void teams(item_queue q, int teams[], int people_no)
{
    int teams_no = people_no / 2, i = 0;

    for (int j = 0; j < people_no; j++)
        teams[j] = -1;

    while (i < teams_no)
    {
        item_t current = q.top();
        q.pop();

        // Set teammates if they are not coupled
        if (teams[current.i] == -1 && teams[current.j] == -1)
        {
            teams[current.i] = current.j + 1;
            teams[current.j] = current.i + 1;
            i++;
        }
    }
}

int main()
{
    int T, x, people_no;

    // Teams to be formed
    cin >> T;

    people_no = 2 * T;

    item_queue q;

    for (int i = 1; i <= people_no; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> x;

            item_t it;
            it.strength = x;
            it.i = i;
            it.j = j;
            q.push(it);
        }
    }

    int result[people_no];
    teams(q, result, people_no);

    for (int i = 0; i < people_no; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}