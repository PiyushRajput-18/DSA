/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first =INT_MAX;
        int last =INT_MIN;
        int mindist = INT_MAX;
        vector<int>result(2,-1);
        ListNode* prev= head;
        ListNode * curr=prev->next;
       
        ListNode * Next = nullptr;
        if(curr!=nullptr){
            Next=curr->next;
        }
        int critical =0;
        int lastpos = INT_MAX;
       int count=1;
        while(Next!=nullptr){
           count++;
            if(((prev->val<curr->val)&&(curr->val>Next->val))){
                if(first>count){
                   first=count;
                }
               if(last<count){
                last=count;
               }
               
                if(lastpos!=INT_MAX){
                    if((count-lastpos)<mindist){
                        mindist = count-lastpos;
                    }
                }
                lastpos = count;
                critical++;
            }
            else if(((prev->val>curr->val)&&(curr->val<Next->val))){
                  if(first>count){
                   first=count;
                }
               if(last<count){
                last=count;
               }
                    
                      if(lastpos!=INT_MAX){
                    if((count-lastpos)<mindist){
                        mindist = count-lastpos;
                    }
                }
                lastpos=count;
                critical++;
            }
                prev= curr;
                curr= Next;
                Next=Next->next;
        }
        if(critical>=2){
        if(first!=INT_MAX){
            result[1]=(last-first);
        }
        if(mindist!=INT_MAX){
        result[0]=mindist;
        }
        }
        return result;

    }
};