class Solution {
public:
bool solve(string &a , string &b, int n ){
   int k=0;
    int l=n-1;
      while(k < l && a[k] == b[l]) {
    k++;
    l--;
}
int x = k;
int y= l;
while(x<y&&a[x]==a[y]){
    x++;
    y--;
}
if(x>=y){
    return true;
}
int u = k;
int v= l;
while(u<v&&b[u]==b[v]){
    u++;
    v--;
}
if(u>=v){
    return true;
}

return false;
}
    bool checkPalindromeFormation(string a, string b) {
       int n = a.length();
  if(solve(a,b,n)){
    return true;
  }
   if(solve(b,a,n)){
    return true;
   }
return false;
    }
};