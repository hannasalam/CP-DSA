class Trie {
public:
    struct Node{
        Node *letters[26];
        bool flag = false;
        bool check(char c){
            return letters[c-'a']!=nullptr;
        }
        Node* next(char c){
            return letters[c-'a'];
        }
    };
    Node* root;
    Trie() {

        root= new Node();
    }
    
    void insert(string word) {
        auto temp = root;
        for(auto c:word){
            if(temp->check(c)){
                temp = temp->next(c);
            }
            else{
                temp->letters[c-'a'] = new Node();
                temp = temp->next(c);
            }
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        auto temp = root;
        for(auto c:word){
            if(temp->check(c)){
                temp = temp->next(c);
            }
            else return false;
        }
        return (temp->flag);
    }
    
    bool startsWith(string prefix) {
        auto temp = root;
        for(auto c:prefix){
            if(temp->check(c)){
                temp = temp->next(c);
            }
            else return false;
        }
        return true;
    }
};