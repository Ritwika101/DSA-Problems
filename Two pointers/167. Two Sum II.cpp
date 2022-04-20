vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        vector<int>v;
        while(i<j){
            if(target > numbers[i]+numbers[j])
                i++;
            else if(target< numbers[i]+numbers[j])
                j--;
            else{
                v.push_back(i+1);
                v.push_back(j+1);
                break;
            }
        }
        return v;
    }
