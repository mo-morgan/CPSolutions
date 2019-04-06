struct SegTree {
    ll N;
    ll size;
    int tree_mode;
    vector<ll> tree;
    SegTree(ll n, const vector<ll> &arr, int mode) {
		N = n;
        tree_mode = mode;
        size = 2 * power(2, ceil(log2(n)));
        switch(mode) {
            case SUM_SEG:
                tree.resize(size);
                break;
            case MIN_SEG:
                tree.resize(size, LL_MAX);
                break;
            case MAX_SEG:
                tree.resize(size, LL_MIN);
                break;
            case FREQ_SEG:
                tree.resize(size, LL_MIN);
                break;
            default:
                tree.resize(size);
        }
        ll j = 0;
        FOR(i, size/2, size-1) {
            if (j >= N)
				break;
            tree[i] = arr[j];
            j++;
        }
        FORD(i, size/2 - 1, 1) pull(i);
    }

    // 1-based index
    void update(ll i, ll k) {
        ll v = size / 2 + i;
        tree[v] = k;
        v = v / 2;
        while (v > 0) {
            pull(v);
            v = v / 2;
        }
    }

    void pull(ll v) {
        if (tree_mode == SUM_SEG || tree_mode == FREQ_SEG)
            tree[v] = tree[2*v] + tree[2*v+1];
        else if (tree_mode == MIN_SEG)
            tree[v] = min(tree[2*v], tree[2*v+1]);
        else if (tree_mode == MAX_SEG)
            tree[v] = max(tree[2*v], tree[2*v+1]);
    }

    // query for the values in [x, y]
    ll query(ll x, ll y) {
        return query(x, y, 1, 0, size/2-1);
    }

    ll query(ll x, ll y, ll i, ll l, ll r) {
        if (r < x || y < l) {
			if (tree_mode == SUM_SEG || tree_mode == FREQ_SEG)
				return 0;
			else if (tree_mode == MIN_SEG) 
				return MAX;
			else if (tree_mode == MAX_SEG)
				return MIN;
        }
        if (x <= l && r <= y)
            return tree[i];
        // else recurse on the children
        ll m = (l + r)/2;
        if (tree_mode == SUM_SEG || tree_mode == FREQ_SEG)
            return query(x, y, 2*i, l, m) + query(x, y, 2*i+1, m+1, r);
        else if (tree_mode == MIN_SEG)
            return min(query(x, y, 2*i, l, m), query(x, y, 2*i+1, m+1, r));
        else if (tree_mode == MAX_SEG)
            return max(query(x, y, 2*i, l, m), query(x, y, 2*i+1, m+1, r));
    }
};