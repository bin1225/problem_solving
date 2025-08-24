#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> answer;
        vector<string> v;
        string s;
        int tmp = 0;
        for(string w: words) {
            
            if(v.size()==1 && v.size() + tmp + w.size() > maxWidth) {
                s = v[0];
                for(int i=s.size(); i<maxWidth; i++) {
                    s+=" ";
                }
                answer.push_back(s);
                v.clear(); tmp = 0;
                v.push_back(w);
            }
            else if(v.size() + tmp + w.size() > maxWidth) {
                int total_blank = maxWidth - tmp;
                int blank_size = total_blank/(v.size()-1);
                int blank_left = total_blank%(v.size()-1);
                string b;
                for(int i=0; i<blank_size; i++) b+=" ";
                vector<string> blanks((v.size()-1), b);
                for(int i=0; i<blank_left; i++) blanks[i] +=" ";
                s = "";
                for(int i=0; i<blanks.size(); i++) {
                    s+=v[i] + blanks[i];
                }
                if(v.size() > blanks.size()) s+=v.back();
                answer.push_back(s);
                v.clear(); tmp = 0;
                v.push_back(w);
            }
            else {
                v.push_back(w);
            }
            tmp+=w.size();
        }

        s = "";
        for(int i=0; i<v.size(); i++) {
            s+=v[i];
            if(i!=v.size()-1) s+=" ";
        }
        for(int i=s.size(); i<maxWidth; i++) {
            s+=" ";
        }
        answer.push_back(s);
        return answer;
    }
};