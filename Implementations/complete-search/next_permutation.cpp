bool next_permutation(string &s){
	if(s.size()==0 || s.size()==1) return false;
	
	for(int i=s.size()-2, ii=s.size()-1; i>=0; i--, ii--){
		if(s[i]<s[ii]){
			int j=s.size()-1;
			while(!(s[i]<s[j])) j--;
			swap(s[i], s[j]);
			reverse(s.begin()+ii, s.end());
			return true;
		}
		if(i==0){
			reverse(s.begin(), s.end());
			return false;
		}
	}
}
