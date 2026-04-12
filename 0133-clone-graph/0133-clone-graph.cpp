/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*> mp;

    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;

        // creating a clone of the start node
        mp[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(Node* neigh : curr->neighbors){
                if(mp.find(neigh) == mp.end()){
                    mp[neigh] = new Node(neigh->val, {}); //create copy
                    q.push(neigh);
                }

                mp[curr]->neighbors.push_back(mp[neigh]); // add vertex to the cloned node
            }
        }

        return mp[node];
    }
};