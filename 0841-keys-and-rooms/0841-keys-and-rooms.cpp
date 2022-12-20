class Solution {
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,-1);

        queue<vector<int>>q;
        q.push(rooms[0]);
        visited[0]=0;
        while(q.empty()==false)
        {
            vector<int>temp=q.front();
            q.pop();

            for(int i=0;i<temp.size();i++)
            {
                if(visited[temp[i]]==-1)
                {
                visited[temp[i]]=0;
                q.push(rooms[temp[i]]);
                }


            }
        }
        for(auto it:visited)
        {
        if(it==-1) 
        return false;
        }


        return true;

        
    
        
    }
};