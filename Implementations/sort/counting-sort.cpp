// Time Complexity: O(n)

	for(int i=0; i<n; i++){
		freq[v[i]].push_back(v[i]);
	}
	for(int i=0; i<MAXN; i++){
		if(freq[i].size()>0){
			for(auto x : freq[i]) cout << x << " ";
		}
	}
