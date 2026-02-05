class node{
    public:
    int data;
    int i;
    int j;

    node(int data,int row,int col){
        this->data = data;
        i=row;
        j=col;
    }
};

class compare{
    public:
    bool operator()(node* a,node *b){
        return a->data>b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*,vector<node*>,compare> minheap;

        int n = nums.size();
        int currMax = INT_MIN;

        for(int i=0;i<n;i++){
            node* temp = new node(nums[i][0],i,0);
            currMax = max(currMax,nums[i][0]);
            minheap.push(temp);
        }

        pair <int,int> ans = make_pair(-100001,100001);

        while(1){
            node* a = minheap.top();
           
            minheap.pop();

            if(currMax-a->data<ans.second-ans.first){
                ans.first = a->data;
                ans.second = currMax;
            }


            int row = a->i;
            int col = a->j;

            if(col<nums[row].size()-1){
                node* t = new node(nums[row][a->j+1],row,col+1);
                minheap.push(t);
                currMax = max(currMax, t->data);
            }
            
            else{
                break;
            }
            
        }

        vector <int> answ(2);
        answ[0] = ans.first;
        answ[1] = ans.second;

        return answ;
    }
};
