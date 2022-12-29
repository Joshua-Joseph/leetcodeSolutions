class Process
{
public:
    int x;
    int y;
    int z;
   Process(int x, int y, int z)
   {
      this->x = x;
      this->y = y;
      this->z = z;
   }
};

// PQ min heap on the basis of arrival time
class myComparator
{
public:
    int operator() (Process* p1, Process* p2)
    {
        return p1->x > p2->x;
    }
};


// PQ min heap on the basis of burst time. If burst time equal then smallest index first
class myComparator2
{
public:
    int operator() (Process* p1, Process* p2)
    {
        if(p1->y == p2->y){
            return p1->z > p2->z;
        }
        return p1->y > p2->y;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> order; // store our answer
        // first min heap PQ on the basis of AT
        priority_queue <Process*, vector<Process*>, myComparator > pq;
        // second min heap PQ on the basis of BT
        priority_queue <Process*, vector<Process*>, myComparator2 > pq2;
        for(int i=0; i<tasks.size(); i++){
            pq.push(new Process(tasks[i][0], tasks[i][1], i));
        }
        long long int t=pq.top()->x;
        while(!pq.empty()){
            // insert all processes which are currently available into PQ2
            while(!pq.empty() and pq.top()->x <= t){
                pq2.push(pq.top());
                pq.pop();
            }
            // execute a single process currently at top and move forward
            if(!pq2.empty()){
                order.push_back(pq2.top()->z);
                t+=pq2.top()->y;
                pq2.pop();
            }
            else{
                t=pq.top()->x;
            }
        }
        while(!pq2.empty()){
            order.push_back(pq2.top()->z);
            t+=pq2.top()->y;
            pq2.pop();
        }
        return order;
    }
};
