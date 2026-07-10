class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (rankv[pu] < rankv[pv])
            parent[pu] = pv;
        else if (rankv[pu] > rankv[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rankv[pu]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> emailToId;
        unordered_map<string, string> emailToName;

        int id = 0;

        for (auto &acc : accounts) {
            string name = acc[0];

            for (int i = 1; i < acc.size(); i++) {

                if (!emailToId.count(acc[i])) {
                    emailToId[acc[i]] = id++;
                }

                emailToName[acc[i]] = name;
            }
        }

        parent.resize(id);
        rankv.resize(id, 0);

        for (int i = 0; i < id; i++)
            parent[i] = i;

        // Union emails in same account
        for (auto &acc : accounts) {

            int first = emailToId[acc[1]];

            for (int i = 2; i < acc.size(); i++) {
                Union(first, emailToId[acc[i]]);
            }
        }

        // Group emails by root
        unordered_map<int, vector<string>> groups;

        for (auto &it : emailToId) {

            string email = it.first;
            int idx = it.second;

            int root = find(idx);

            groups[root].push_back(email);
        }

        vector<vector<string>> ans;

        for (auto &it : groups) {

            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> account;

            account.push_back(emailToName[emails[0]]);

            for (auto &email : emails)
                account.push_back(email);

            ans.push_back(account);
        }

        return ans;
    }
};