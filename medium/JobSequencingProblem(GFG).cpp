class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
        static bool compare(Job a, Job b)
        {
            return (a.profit > b.profit);//sort the job array in order of increasing profit
        }
        vector<int> JobScheduling(Job arr[], int n) 
        { 
            sort(arr,arr+n,compare);// sorting of array
            int slot[n];
            for(int i=0;i<n;i++){//initializing the slot array with -1
                slot[i]=-1;
                
            }
            int num=0,sum=0;
            for(int i=0;i<n;i++){
                for(int j=(arr[i].dead)-1;j>=0;j--){//find a slot until the index becomes 0
                    if(slot[j]==-1){//if slot found the no of job done increases by one and sum is increased by profit of the job
                        num++;
                        sum+=arr[i].profit;
                        slot[j]=1;//the job is placed and slot become filled
                        break;
                    }
                }
                }
                vector<int>res;
                res.push_back(num);
                res.push_back(sum);
                return res;
        } 
};