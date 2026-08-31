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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int count1=0;
//         int count2=0;
//         ListNode* head1 = l1;
//         ListNode* head2 = l2;
//         while(head1!=nullptr){
//             count1++;
//             head1=head1->next;
//         }
//           while(head2!=nullptr){
//             count2++;
//             head2=head2->next;
//         }
//    int diff=0;
//    if(count1>count2){
//        diff= count1-count2;
//        ListNode * result = l1;
//        while(diff!=0){
//         ListNode* newNode = new ListNode(value);
//         newNode->next = result;
//          result = newNode;
//          diff--;
//        }
//        int carry =0;
//        while(l2!=nullptr){ 
//            int sum= l1->val+l2->val+carry;
//            int val= sum%10;
//            carry=sum/10;
//               ListNode* newNode = new ListNode(val);
//                  newNode->next = result;
//                 result = newNode;
//                 l1=l1->next;
//                 l2=l2->next;
//        }
//    }
        
        stack<int>st1;
        stack<int>st2;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
         int carry=0;
        while(head1!=nullptr){
            st1.push(head1->val);
            head1=head1->next;
        }
         while(head2!=nullptr){
            st2.push(head2->val);
            head2=head2->next;
        }
         ListNode* result = nullptr;
       
        while(!st1.empty()&&!st2.empty()){
        int sum = st1.top()+st2.top()+carry;
        int val = sum%10;
     carry= sum/10;
       

      ListNode* newNode = new ListNode(val);
      newNode->next = result;
     result = newNode;
     st1.pop();
     st2.pop();
        }
     while(!st1.empty()){
         int sum = st1.top()+carry;
           int val = sum%10;
          carry= sum/10;
         ListNode* newNode = new ListNode(val);
         newNode->next = result;
        result = newNode;
         st1.pop();
       
     }
       while(!st2.empty()){
         int sum =st2.top()+carry;
          int val = sum%10;
         carry= sum/10;
         ListNode* newNode = new ListNode(val);
         newNode->next = result;
        result = newNode;
         st2.pop();
       
     }
     if(carry!=0){
        ListNode* newNode = new ListNode(carry);
         newNode->next = result;
        result = newNode;
     }

     return result;
     
    }
};