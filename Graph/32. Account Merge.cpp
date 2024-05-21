#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, setSize;

   public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        setSize.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            setSize[i] = 1;
        }
    }

    int findSet(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findSet(parent[node]);
    }

    void unionBySize(int u, int v) {
        int rootU = findSet(u);
        int rootV = findSet(v);
        if (rootU == rootV) return;
        if (setSize[rootU] < setSize[rootV]) {
            parent[rootU] = rootV;
            setSize[rootV] += setSize[rootU];
        } else {
            parent[rootV] = rootU;
            setSize[rootU] += setSize[rootV];
        }
    }
};

class Solution {
   public:
    vector<vector<string>> mergeAccounts(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet* ds = new DisjointSet(n);
        unordered_map<string, int> emailToIndexMap;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToIndexMap.count(email) == 0) {
                    emailToIndexMap[email] = i;
                } else {
                    ds->unionBySize(i, emailToIndexMap[email]);
                }
            }
        }
        vector<vector<string>> mergedEmails(n);
        for (auto& entry : emailToIndexMap) {
            string email = entry.first;
            int rootIndex = ds->findSet(entry.second);
            mergedEmails[rootIndex].push_back(email);
        }

        vector<vector<string>> mergedAccounts;
        for (int i = 0; i < n; i++) {
            if (mergedEmails[i].empty()) continue;
            sort(mergedEmails[i].begin(), mergedEmails[i].end());
            vector<string> mergedAccount;
            mergedAccount.push_back(accounts[i][0]);
            for (auto& email : mergedEmails[i]) {
                mergedAccount.push_back(email);
            }
            mergedAccounts.push_back(mergedAccount);
        }
        sort(mergedAccounts.begin(), mergedAccounts.end());
        return mergedAccounts;
    }
};

int main() {
    return 0;
}