	vector<int>sorted;
	for(int i=0; i<n; i++){
		int menor=1e9, idx;
		for(int j=0; j<n; j++){
			if(marc[j]==0 && v[j]<menor){
				menor=v[j];
				idx=j;
			}
		}
		sorted.push_back(v[idx]);
		marc[idx]=1;
	}
