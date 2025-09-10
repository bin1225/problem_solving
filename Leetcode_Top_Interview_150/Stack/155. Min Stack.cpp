/*
    time: 10min 
    success: true 
    note: stack의 자료형을 pair로 하거나 st을 두개 이용해서 하나는 최소 값을 유지하는 용도로 
    코드를 작성하는 게 더 깔끔하다.

*/
#include<bits/stdc++.h>
using namespace std;


class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
    }
    
    void push(int val) {
        int min_val;
        if(!st.empty()) min_val = min(st.top().second, val);
        else min_val = val;
        st.push({val,min_val});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};



// Mysolution

// class MinStack {
// public:
//     int min_num;
//     unordered_map<int,int> count;
//     unordered_map<int,int> next_min;
//     stack<int> st;
//     MinStack() {
//         min_num = INT_MAX;
//     }
    
//     void push(int val) {
//         st.push(val);
//         count[val]++;
//         if(min_num>val) {
//             next_min[val] = min_num;
//             min_num = val;
//         }
//     }
    
//     void pop() {
//         int num = st.top();
//         count[num]--;
//         if(num == min_num && count[num] <= 0) {
//             min_num = next_min[num];
//         }
//         st.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return min_num;
//     }
// };
