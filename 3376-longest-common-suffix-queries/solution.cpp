class Solution {
public:

    struct Node {
        int child[26];
        int idx;

        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<Node> trie;

    void update(int &storedIdx, int newIdx,
                vector<string>& wordsContainer) {

        if (storedIdx == -1 ||
            wordsContainer[newIdx].size() <
            wordsContainer[storedIdx].size() ||
            (wordsContainer[newIdx].size() ==
             wordsContainer[storedIdx].size() &&
             newIdx < storedIdx)) {

            storedIdx = newIdx;
        }
    }

    void insert(string &word, int index,
                vector<string>& wordsContainer) {

        int node = 0;

        update(trie[node].idx, index, wordsContainer);

        for (int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];

            update(trie[node].idx, index, wordsContainer);
        }
    }

    int search(string &word) {

        int node = 0;

        for (int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                return trie[node].idx;
            }

            node = trie[node].child[c];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(Node());

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for (auto &q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};
