class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
      vector<int>store(12,0);
      store[0]=31;
      store[1]=28;
      store[2]=31;
      store[3]=30;
      store[4]=31;
      store[5]=30;
      store[6]=31;
      store[7]=31;
      store[8]=30;
      store[9]=31;
      store[10]=30;
      store[11]=31;
       int month1 = stoi(arriveAlice.substr(0, 2));  // 8
int day1 = stoi(arriveAlice.substr(3, 2));    // 15
int arrive1 = 0;
for(int i=0;i<month1-1;i++){
    arrive1+=store[i];
}
arrive1+=day1;

int month2 = stoi(leaveAlice.substr(0, 2));  // 8
int day2 = stoi(leaveAlice.substr(3, 2));    // 15
int leave1 =0;
for(int i=0;i<month2-1;i++){
    leave1+=store[i];
}
leave1+=day2;

int month3 = stoi(arriveBob.substr(0, 2));  // 8
int day3 = stoi(arriveBob.substr(3, 2));    // 15
  int arrive2 = 0;
for(int i=0;i<month3-1;i++){
    arrive2+=store[i];
}
arrive2+=day3;

int month4 = stoi(leaveBob.substr(0, 2));  // 8
int day4 = stoi(leaveBob.substr(3, 2));    // 15
int leave2 =0;
for(int i=0;i<month4-1;i++){
    leave2+=store[i];
}
leave2+=day4;

int start = max(arrive1,arrive2);
int end = min(leave1,leave2);

if(end-start+1>0){
    return (end-start+1);
}
return 0;
    }
};