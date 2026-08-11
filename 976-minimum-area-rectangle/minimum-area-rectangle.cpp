class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
       set<pair<int,int>> st;
        int n = points.size();
        for (auto &p : points) {
           st.insert({p[0], p[1]});
        }
        int area =INT_MAX;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x1= points[i][0];
                int y1=points[i][1];
                int x2= points[j][0];
                int y2=points[j][1];
              if (x1 != x2 && y1 != y2 &&
                 st.count({x1, y2}) &&
             st.count({x2, y1})) {

        area = min(area,abs(x1 - x2) * abs(y1 - y2));
}
              
            }
        }
        if(area==INT_MAX){
            return 0;
        }
        return area;
    }
};