class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) ++LOG;

        vector<int> tin(n), tout(n), depth(n), parent(n);
        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> pref(n);
        int timer = 0;

        vector<int> order;
        order.reserve(n);

        struct State {
            int u, p, stage;
        };

        vector<State> st;
        st.push_back({0, 0, 0});

        while (!st.empty()) {
            auto& cur = st.back();
            int u = cur.u, p = cur.p;

            if (cur.stage == 0) {
                tin[u] = timer++;
                order.push_back(u);
                parent[u] = p;
                up[0][u] = p;

                for (int j = 1; j < LOG; ++j)
                    up[j][u] = up[j - 1][up[j - 1][u]];

                pref[u] = (u == 0 ? 0 : pref[p]) ^ (1 << (s[u] - 'a'));

                cur.stage = 1;
            }

            if (cur.stage == 1) {
                cur.stage = 2;
                for (int v : adj[u]) {
                    if (v == p) continue;
                    depth[v] = depth[u] + 1;
                    st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];
            for (int j = 0; j < LOG; ++j)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; --j) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        vector<int> bit(n + 2, 0);

        auto add = [&](int idx, int val) {
            for (++idx; idx <= n; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto queryPrefix = [&](int idx) {
            int res = 0;
            for (++idx; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];
            return res;
        };

        auto rangeXor = [&](int l, int r, int val) {
            add(l, val);
            if (r + 1 < n) add(r + 1, val);
        };

        vector<bool> ans;

        for (const string& q : queries) {
            string type;
            int u;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                if (delta != 0) {
                    rangeXor(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int pu = pref[u] ^ queryPrefix(tin[u]);
                int pv = pref[v] ^ queryPrefix(tin[v]);

                int w = lca(u, v);
                int pathMask = pu ^ pv ^ (1 << (s[w] - 'a'));

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};