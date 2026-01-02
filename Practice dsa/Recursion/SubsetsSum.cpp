
void solve(int index,int currSum,vector<int>& num,vector<int>& output){
	if(index==num.size()){
		output.push_back(currSum);
		return;
	}
	solve(index+1,currSum+num[index],num,output);
	solve(index+1,currSum,num,output);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> output;
	solve(0,0,num,output);
	sort(output.begin(),output.end());
	return output;	
}