class Solution {
public:
    map<string, vector<string>> G;
    map<string, bool> visited;
    queue<string> Q;

    
    bool check(string a, string b){
        int count = 0;
        for(int i=0; i<b.size(); i++){
            if(a[i] != b[i]) count++;
            if(count>1) break;
        }
        if(count==1) return true;
        else return false;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int answer = 1;
        string word, compareWord;
        for(int i=0; i<wordList.size(); i++){
            word = wordList[i];
            
            for(int j=i+1; j<wordList.size(); j++){
                compareWord = wordList[j];
                if(check(word, compareWord)){
                    G[word].push_back(compareWord);
                    G[compareWord].push_back(word);
                }
            }
        }
        
        for(int i=0; i<wordList.size(); i++){
            if(check(beginWord, wordList[i])){
                G[beginWord].push_back(wordList[i]);
                G[wordList[i]].push_back(beginWord);
            }
        }
        
        
        Q.push(beginWord);
        while(!Q.empty()){
            int size = Q.size();
            for(int j=0; j<size; j++){
                
                word = Q.front(); Q.pop();
            
                for(int i=0; i<G[word].size(); i++){
                    compareWord = G[word][i];
                    if(visited[compareWord]== false){
                        visited[compareWord] = true;
                        Q.push(compareWord);
                    }
                }
            }
            answer++;
            if(visited[endWord]==true) break;
        }
        
        if(visited[endWord]==false) return 0;
        return answer;
        
    }
};