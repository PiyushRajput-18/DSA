class Solution {
public:
    int smallestNumber(int n, int t) {
        int result =n;
        for(int i=n;i<=100;i++){
              int digit =1;
              int temp=i;
              while(temp>0){
                digit = digit*(temp%10);
                temp=temp/10;
              }
              if(digit%t==0){
                result =i;
                break;
              }
        }
        return result;
    }
};