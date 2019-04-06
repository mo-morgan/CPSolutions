struct SegTreeLp {
    ll N;
    ll size;
    vector<ll> tree;
    vector<ll> lazy;
    SegTreeLp(ll n, const vector<ll> &arr) {
        N = n;
        size = 2 * power(2, ceil(log2(n)));
        tree.resize(size);
        lazy.resize(size);
        ll j = 0;
        FOR(i, size/2, size-1) {
            if (j >= N)
                break;
            tree[i] = arr[j];
            j++;
        }
        FORD(i, size/2 - 1, 1) pull(i);
    }

    ll length(ll i) {
        if (i >= size/2) return 1;
        return length(2*i) + length(2*i + 1);
    }

    // 1-based index
    void update(ll x, ll y, ll k) {
        update(x, y, k, 1, 1, size/2-1);
    }

    void update(ll x, ll y, ll k, ll i, ll l, ll r) {
        if (r < x || y < l)
            return;
        if (x <= l && r <= y) {
            tree[i] += k * length(i);
            lazy[i] += k;
            return;
        }
        ll m = (l+r) / 2;
        push(i);
        update(x, y, k, 2*i, l, m);
        update(x, y, k, 2*i+1, m+1, r);
        pull(i);
    }

    void pull(ll i) {
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    void push(ll i) {
        if (lazy[i] != 0) {
            tree[2*i] += lazy[i] * length(2*i);
            tree[2*i+1] += lazy[i] * length(2*i+1);
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
            lazy[i] = 0;
        }
    }

    // query for the values in [x, y]
    ll query(ll x, ll y) {
        return query(x, y, 1, 1, size/2-1);
    }

    ll query(ll x, ll y, ll i, ll l, ll r) {
        if (r < x || y < l)
            return 0;
        if (x <= l && r <= y)
            return tree[i];

        ll m = (l+r) / 2;
        push(i);
        return query(x, y, 2*i, l, m) + query(x, y, 2*i+1, m+1, r);
    }
};