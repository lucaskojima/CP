bool next_permutation(vector<int> &v){
	if(v.size()==0 || v.size()==1) return false;
	
	for(int i=v.size()-2, ii=v.size()-1; i>=0; i--, ii--){
		if(v[i]<v[ii]){
			int j=v.size()-1;
			while(!(v[i]<v[j])) j--;
			swap(v[i], v[j]);
			reverse(v.begin()+ii, v.end());
			return true;
		}
		if(i==0){
			reverse(v.begin(), v.end());
			return false;
		}
	}
}
