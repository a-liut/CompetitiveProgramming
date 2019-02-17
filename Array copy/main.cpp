#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

#define LEFT(i) 2 * i + 1
#define RIGHT(i) 2 * i + 2
#define PARENT(i) (i - 1) / 2

using namespace std;

struct query
{
    query(size_t xx,
          size_t yy,
          size_t kk)
        : x(xx), y(yy), k(kk) {}

    size_t x, y, k;
};

template <typename IntType>
struct segment_tree
{

    segment_tree(size_t n)
        : _size(n), m_leaves(n)
    {
        // round up to the next power of 2
        size_t m = size_t(1) << static_cast<size_t>(ceil(log2(n)));
        m_tree.resize(2 * m - 1, IntType(0));
        build(0, n - 1, 0);
    }

    void build(size_t lo, size_t hi, size_t pos)
    {
        if (lo == hi)
        {
            m_leaves[lo] = pos; // save leaf position
            return;
        }
        size_t mid = (lo + hi) / 2;
        build(lo, mid, LEFT(pos));
        build(mid + 1, hi, RIGHT(pos));
    }

    struct range
    {
        range(size_t l,
              size_t h)
            : lo(l), hi(h) {}

        size_t lo, hi;
    };

    range root() const
    {
        return range(0, size());
    }

    size_t size() const
    {
        return _size;
    }

    void copy(query const &q, size_t query_id)
    {
        range r(q.y, q.y + q.k);
        copy(r, query_id, root(), 0);
    }

    size_t get_query_id(size_t i)
    {
        assert(i < size());
        size_t max = 0;
        size_t pos = m_leaves[i]; // position of the i-th leaf

        while (true)
        { // return max from leaf to root
            if (m_tree[pos] > max)
            {
                max = m_tree[pos];
            }
            if (pos == 0)
            { // root
                break;
            }
            pos = PARENT(pos);
        }

        return max;
    }

  private:
    size_t _size;
    vector<size_t> m_leaves;
    vector<IntType> m_tree;

    void copy(range const &r, size_t query_id, range node_segment, size_t pos)
    {

        // total overlap
        if (r.lo <= node_segment.lo and r.hi >= node_segment.hi)
        {
            m_tree[pos] = query_id;

            // block if leaf
            if (node_segment.lo == node_segment.hi)
                return;
        }

        // no overlap
        if (r.lo > node_segment.hi or r.hi < node_segment.lo)
        {
            return;
        }

        // partial overlap
        size_t mid = (node_segment.lo + node_segment.hi) / 2;
        copy(r, query_id, {node_segment.lo, mid}, LEFT(pos));
        copy(r, query_id, {mid + 1, node_segment.hi}, RIGHT(pos));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    uint64_t n = 0; // number of elements in arrays
    cin >> n;

    uint64_t m = 0; // number of queries
    cin >> m;

    typedef int int_type;

    vector<int_type> A;
    vector<int_type> B;
    A.reserve(n);
    B.reserve(n);

    for (uint64_t i = 0; i < n; ++i)
    {
        int_type x = 0;
        cin >> x;
        A.push_back(x);
    }

    for (uint64_t i = 0; i < n; ++i)
    {
        int_type x = 0;
        cin >> x;
        B.push_back(x);
    }

    segment_tree<int_type> st(n);

    vector<query> queries;
    queries.reserve(m); // upper bound

    for (uint64_t i = 0; i < m; ++i)
    {
        // copy(x, y, k)
        size_t type;
        cin >> type;

        if (type == 1)
        {

            size_t x, y, k;
            cin >> x >> y >> k;
            queries.emplace_back(x, y, k);
            st.copy(queries.back(),
                    queries.size()); // next query id
        }
        else if (type == 2)
        {
            // access(query_id)
            size_t pos;
            cin >> pos;

            size_t query_id = st.get_query_id(pos);
            if (query_id == 0)
            {
                cout << B[pos] << "\n";
            }
            else
            {
                auto q = queries[query_id - 1];
                cout << A[pos - q.y + q.x] << "\n";
            }
        }
        else
        {
            cerr << "unknown query type" << endl;
            return 1;
        }
    }

    cout << flush;
    
    return 0;
}