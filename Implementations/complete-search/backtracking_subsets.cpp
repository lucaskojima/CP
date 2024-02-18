void bt(int idx, vector<int>sub={}){
	if(idx==n){
		return;
	}
	
	sub.push_back(v[idx]);
	bt(idx+1, sub);
	sub.pop_back();
	bt(idx+1, sub);
}
