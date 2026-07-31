class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // int n = positions.size();
        // for(int i=0;i<n;i++){
        //     if(directions[i]=='R'){
        //         continue;
        //     }else{
        //         healths[i]=-healths[i];
        //     }
        // }
        // vector<pair<int,int>>v;
        // for(int i=0;i<n;i++){
        //     v.push_back({positions[i],healths[i]});

        // }
        // sort(v.begin(),v.end());
        // stack<int>st;
        // vector<int>result;
        // st.push(v[0].second);
        // for(int i=1;i<n;i++){
        //      if(st.empty()){
        //         st.push(v[i].second);
        //      }
        //     if(st.top()<0){
        //         result.push_back(v[i].second);
        //     }
        //     else{
        //         if(v[i].second>0){
        //          result.push_back(v[i].second);
        //         }else{
        //             while(!st.empty()&&-(v[i].second)>st.top()){
        //                 st.pop();
        //                 result.push_back((v[i].second)-1);
        //                 st.push(-(v[i].second)-1);
        //             }
        //             while(!st.empty()&&st.top()>-(v[i].second)){
        //                   int temp = st.top();  
        //                 result.push_back(st.top()-1);
        //                 st.pop();
        //                 st.push(temp-1);
        //             }
        //         }
        //     }
        // }
        // return result;

    //     int n = positions.size();
    //      for(int i=0;i<n;i++){
    //         if(directions[i]=='R'){
    //             continue;
    //         }else{
    //             healths[i]=-healths[i];
    //         }
    //     }
    //     vector<pair<int,int>>v;
    //     for(int i=0;i<n;i++){
    //         v.push_back({positions[i],healths[i]});

    //     }
    //     sort(v.begin(),v.end());
    //     stack<int>st;
    //     int k=0;
    //     while(k<n&&v[k].second<0){
    //         st.push(v[k].second);
    //         k++;
    //     }
    //    for(int i=k;i<n;i++){
    //     if(st.empty()||v[i].second>0){
    //        st.push(v[i].second);
    //     }
    //     else{
    //          while(!st.empty()&&st.top()>-(v[i].second)){
    //             int temp = st.top()-1;
    //             st.pop();
    //             st.push(temp);
    //          }  
    //          while(!st.empty()&&st.top()<-(v[i].second)){
    //             st.pop();
    //             st.push(-(-(v[i].second)-1));
    //          }
    //        }
           
    //    }
    //    vector<int>result;
    //    while(!st.empty()){
    //     if(st.top()<0){
    //         result.push_back(-st.top());
    //     }
    //     result.push_back(st.top());
    //     st.pop();
    //    }
    //    return result;


    struct Robot {
        int pos;
        int health;
        char dir;
        int idx;
    };
        int n = positions.size();

        vector<Robot> robots;

        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end(), [](Robot &a, Robot &b) {
            return a.pos < b.pos;
        });

        stack<int> st;  

        for (int i = 0; i < n; i++) {

            if (robots[i].dir == 'R') {
                st.push(i);
            }
            else {

                while (!st.empty() && robots[i].health > 0) {

                    if (robots[st.top()].health < robots[i].health) {

                        robots[i].health--;
                        robots[st.top()].health = 0;
                        st.pop();
                    }
                    else if (robots[st.top()].health > robots[i].health) {

                        robots[st.top()].health--;
                        robots[i].health = 0;
                    }
                    else {

                        robots[st.top()].health = 0;
                        robots[i].health = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<pair<int,int>> alive;

        for (auto &r : robots) {
            if (r.health > 0) {
                alive.push_back({r.idx, r.health});
            }
        }

        sort(alive.begin(), alive.end());

        vector<int> ans;

        for (auto &p : alive) {
            ans.push_back(p.second);
        }

        return ans;
    
    }
};