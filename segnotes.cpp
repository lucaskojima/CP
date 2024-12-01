// Point update Range query
// each node stores the interval value
// Update: assignment
// Query : associative ops

struct SegmentTree {
	vector<ll> seg; int n;
	SegmentTree(int n) : seg(4 * n), n(n) {}

	void update(int p, int l, int r, int i, int v) {
		if (i < l || r < i) return;
		if (l == r) { seg[p] = v; return; }

		int m = (l + r) / 2;
		int e = 2 * p + 1, d = 2 * p + 2;
		update(e, l, m, i, v);
		update(d, m + 1, r, i, v);

		seg[p] = seg[e] + seg[d];
	}
	void update(int i, int v) { update(0, 0, n - 1, i, v); }

	ll query(int p, int l, int r, int lx, int rx) {
		if (rx < l || r < lx) return 0LL;
		if (lx <= l && r <= rx) return seg[p];

		int m = (l + r) / 2;
		int e = 2 * p + 1, d = 2 * p + 2;
		return query(e, l, m, lx, rx) + query(d, m + 1, r, lx, rx);
	}
	ll query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

// Range update Point query
// each node stores how much should be added to the interval
// Update: associative and commutative ops
// Query : (!)

struct SegmentTree {
	vector<ll> seg; int n;
	SegmentTree(int n) : seg(4 * n), n(n) {}

	void update(int p, int l, int r, int lx, int rx, int v) {
		if (rx < l || r < lx) return;
		if (lx <= l && r <= rx) { seg[p] += v; return; }

		int m = (l + r) / 2;
		int e = 2 * p + 1, d = 2 * p + 2;
		update(e, l, m, lx, rx, v);
		update(d, m + 1, r, lx, rx, v);
	}
	void update(int l, int r, int v) { update(0, 0, n - 1, l, r, v); }

	ll query(int p, int l, int r, int i) {
		if (i < l || r < i) return 0LL;
		if (l == r) return seg[p];

		int m = (l + r) / 2;
		int e = 2 * p + 1, d = 2 * p + 2;
		return seg[p] + query(e, l, m, i) + query(d, m + 1, r, i);
	}
	ll query(int i) { return query(0, 0, n - 1, i); }
};

// Range update Point query (with Lazy)
// each node stores how much should be added to the interval
// Update: associative ops
// Query : (!)

struct SegmentTree {
	vector<int> seg; int n;
	SegmentTree(int n) : seg(4 * n), n(n) {}

	void refresh(int p, int l, int r) {
		if (l == r || seg[p] == -1) return;
		int e = 2 * p + 1, d = 2 * p + 2;
		seg[e] = seg[p];
		seg[d] = seg[p];
		seg[p] = -1;
	}

	void update(int p, int l, int r, int lx, int rx, int v) {
		refresh(p, l, r);
		if (rx < l || r < lx) return;
		if (lx <= l && r <= rx) { seg[p] = v; return; }

		int m = (l + r) / 2;
		int e = 2 * p + 1, d = 2 * p + 2;
		update(e, l, m, lx, rx, v);
		update(d, m + 1, r, lx, rx, v);
	}
	void update(int l, int r, int v) { update(0, 0, n - 1, l, r, v); }

	int query(int p, int l, int r, int i) {
		refresh(p, l, r);
		if (l == r) return seg[p];

		int m = (l + r) / 2;
		int e = 2 * p + 1, d = 2 * p + 2;
		if (i <= m)
			return query(e, l, m, i);
		else
			return query(d, m + 1, r, i);
	}
	int query(int i) { return query(0, 0, n - 1, i); }
};


