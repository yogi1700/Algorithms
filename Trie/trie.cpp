struct TrieNode{
    map<char,pair<TrieNode*, int> >children;
    bool end;
    TrieNode(){
        end = false;
    }
};

void insert(TrieNode *root, string word){
    
    TrieNode *current = root;
    
    for(int i=0;i<word.size();i++){
        TrieNode *node = current->children[word[i]].first;
        if(node == NULL){
            node = new TrieNode();
            current->children[word[i]] = make_pair(node,1);
        }
        else{
            int freq = current->children[word[i]].second;
            freq++;
            //cout<<word[i]<<endl;
            current->children[word[i]] = make_pair(node,freq);
        }
        current = node;
    }
    current->end = true;
}

string shortprefix(TrieNode *root, string word){
    TrieNode *current = root;
    string str;
    for(int i=0;i<word.size();i++){
        
        TrieNode *node = current->children[word[i]].first;
        
        str +=word[i];
        if(node == NULL || current->children[word[i]].second <= 1){
            
            break;
        }
        current = node;
    }
  
    return str;
}
vector<string> Solution::prefix(vector<string> &A) {
    TrieNode *root = new TrieNode();
    for(int i=0;i<A.size();i++){
        insert(root, A[i]);
    }
    vector<string>ans;
    for(int i=0;i<A.size();i++){
        string str = shortprefix(root, A[i]);
        ans.push_back(str);
    }
    
    return ans;
}
