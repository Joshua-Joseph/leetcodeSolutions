class TrieNode{
    // a trieNode with a charachter, end of string boolean and an array of type TrieNode pointer 
    // pointing to other a-z charachter combinations 
    public:
    char ch;
    bool isTerminal;
    TrieNode* childArray[26];
    
    TrieNode(char c){
        this->ch = c;
        this->isTerminal = false;
        for(int i=0; i<26; i++){
            this->childArray[i] = NULL;
        }
    }
};

class Trie {
public:
    // the root will be a blank charachter
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.length(); i++){
            int pos = word[i] - 'a';
            if(temp->childArray[pos]!=NULL){
                temp = temp->childArray[pos];
                if(i==word.length()-1){
                    temp->isTerminal = true;
                }
            }
            else{
                temp->childArray[pos] = new TrieNode(word[i]);
                temp = temp->childArray[pos]; 
                if(i==word.length()-1){
                    temp->isTerminal = true;
                }
            }
        }
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.length(); i++){
            int pos = word[i] - 'a';
            if(temp->childArray[pos]!=NULL){
                temp = temp->childArray[pos];
                if(i==word.length()-1){
                    return temp->isTerminal;
                }
            }
            else{
                return false;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i=0; i<prefix.length(); i++){
            int pos = prefix[i] - 'a';
            if(temp->childArray[pos]!=NULL){
                temp = temp->childArray[pos];
                if(i==prefix.length()-1){
                    return true;
                }
            }
            else{
                return false;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */