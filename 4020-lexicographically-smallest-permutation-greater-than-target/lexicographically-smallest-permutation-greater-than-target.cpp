   //       unordered_map<char,int>mpp;
    //       int n = s.length();
    //       for(int i=0;i<n;i++){
    //         mpp[s[i]]=(int)s[i];
    //       }
    //     string result ="";
    //     for(int i=0;i<n;i++){
    //         int diff=INT_MAX;
    //         for(auto &it: mpp){
    //             if(it.second-(int)target[i]<diff){
    //                 result[i]=it.first;
    //             }
    //             it.second=INT_MAX;
    //         }
    //     }
    //   if(result<target){
    //     return "";
    //   }
    //   return result;
//     map<char,int>mpp;
//     int n = s.length();
//     for(int i=0;i<n;i++){
//         mpp[s[i]]++;
//     }
//     string result(n,'\0');
//     for(int j=n-1;j>=0;j--){

//     for(int i=0;i<n;i++){
     
//         int diff=INT_MAX;
//         for(auto &it:mpp){
//             if(it.first==target[i]&&(diff<(target[i]-it.first))){
//                 result[i]=it.first;
//                 diff=0;
//                 it.second--;
//             }
//             if(it.first>target[i] &&(diff<(it.first-target[i]))){
//                  result[i]=it.first;
//                 diff=it.first-target[i];
//                 it.second--;
//             }
    

            
//         }
//          auto it = mpp.find(ch);

// if(it != mpp.end()) {
//     it->second--;

//     if(it->second == 0) {
//         mpp.erase(it);
//     }
// }
     
//     }
    
//     }
//      if(result<target){
//         return "";
//       }

//       return result;
 
 class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        map<char,int> mpp;

        int n = s.length();

        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }

        string result = "";
        int j = -1;

        // Target ko maximum possible prefix tak match karo
        for(int i=0;i<n;i++){

            if(mpp[target[i]] > 0){

                mpp[target[i]]--;
                result += target[i];

            }
            else{

                // Current position par target[i] available nahi hai.
                // Isi position par pehle greater character try karenge.
                j = i;
                break;
            }
        }

        // Agar pura target match ho gaya,
        // to last position se backtrack karna padega.
        if(j == -1){
            j = n - 1;
        }

        bool get = false;

        for(;j>=0;j--){

            // Agar j already matched position hai,
            // uska character wapas available karo.
            if(j < result.length()){
                mpp[target[j]]++;
            }

            for(auto &it : mpp){

                if(it.first > target[j] && it.second > 0){

                    // j se pehle ka prefix same rahega.
                    result.resize(j);

                    // Current position par greater character.
                    result += it.first;

                    it.second--;

                    get = true;
                    break;
                }
            }

            if(get){
                break;
            }
        }

        if(!get){
            return "";
        }

        // Remaining characters smallest order mein add karo.
        for(auto &it : mpp){

            while(it.second > 0){

                result += it.first;
                it.second--;
            }
        }

        return result;
    }
};