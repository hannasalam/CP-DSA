class Solution {
public:
    //if(total gas - total cost < 0 -> not possible
    //if we start from i and at j if total cost <0 means
    //even after getting extra gas we could not reach, so everything between i and j also won't work ottakk no
    // appo we do j+1 as new start
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
        }
        if(total<0) return -1;
        int curr = 0;
        int start = 0;
        //next station il chellmbo avde vare ethan ollath illenki curr<0
        // appo aa station ne new start akki nokkum avdenn ethuvonn
        for(int i=0;i<gas.size();i++){
            if(curr<0){
                curr = 0;
                start = i;
            }
            curr+= (gas[i]-cost[i]);
        }
        return start;
    }
};