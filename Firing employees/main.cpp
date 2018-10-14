#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

std::vector<bool> generate_primes(size_t n)
{
    std::vector<bool> primes(n, true);
    for (uint64_t i = 2; i <= (uint64_t)sqrt(n); ++i)
    {
        if (primes[i])
        {
            uint64_t isquare = i * i;
            for (uint64_t j = isquare; j < n; j += i)
                primes[j] = false;
        }
    }

    return primes;
}

void count_parents(vector<int> &employees, vector<int> &parents, int idx)
{
    if (employees[idx] == 0) // Mr. Alfred
    {
        parents[idx] = 0;
    }
    else
    {
        if (parents[employees[idx] - 1] == -1) // Not already assigned
        {
            count_parents(employees, parents, employees[idx] - 1);
        }
        parents[idx] = 1 + parents[employees[idx] - 1];
    }
}

int blacklisted(vector<int> employees)
{
    vector<int> parents;
    parents.assign(employees.size(), -1);

    int i = 0;
    for (int e : employees)
    {
        count_parents(employees, parents, i);
        i++;
    }

    // Count blacklisted nodes
    auto primes = generate_primes(2 * (employees.size() + 1));
    int blackl = 0;
    for (int rank = 1; rank <= employees.size(); rank++)
    {
        if (parents[rank - 1] != 0 && primes[rank + parents[rank - 1]])
        {
            blackl++;
        }
    }

    return blackl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int T, n, x;
    vector<int> employees;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        for (int e = 0; e < n; e++)
        {
            cin >> x;
            employees.push_back(x);
        }

        cout << blacklisted(employees) << endl;

        employees.clear();
    }

    return 0;
}