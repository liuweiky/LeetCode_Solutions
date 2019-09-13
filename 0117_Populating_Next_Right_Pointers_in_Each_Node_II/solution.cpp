/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        
        queue<pair<Node*, int>> q;
        int cur = 0;
        q.push(make_pair(root, 0));
        vector<Node*> v;
        
        while (!q.empty())
        {
            pair<Node*, int> p = q.front();
            q.pop();
            
            if (p.second != cur)
            {
                for (int i = 0; i < v.size(); i++)
                {
                    if (i == v.size() - 1)
                        v[i]->next = NULL;
                    else
                        v[i]->next = v[i + 1];
                }
                
                v.clear();
                cur = p.second;
            }
            
            v.push_back(p.first);
            
            if (p.first->left != NULL)
                q.push(make_pair(p.first->left, cur + 1));
            if (p.first->right != NULL)
                q.push(make_pair(p.first->right, cur + 1));
        }
        
        for (int i = 0; i < v.size(); i++)
        {
            if (i == v.size() - 1)
                v[i]->next = NULL;
            else
                v[i]->next = v[i + 1];
        }
        
        return root;
    }
};
