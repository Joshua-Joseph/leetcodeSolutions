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
    // this function returns a copy node 
    Node* makeClone(unordered_map<Node*, Node*> &og2clone, Node* node){
        // if a node has already been copied it will be present in the map
        if(og2clone.find(node)!=og2clone.end()){
            return og2clone[node];
        }
        // create a new Node with same values and store it in map
        Node* newNode = new Node(node->val);
        og2clone[node] = newNode;
        // create copies for all its neighbors
        for(auto nbr:node->neighbors){
            newNode->neighbors.push_back(makeClone(og2clone, nbr));
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        // map from original graph to cloned graph
        unordered_map<Node*, Node*> og2clone;
        Node* clone = makeClone(og2clone, node);
        return clone;
    }
};