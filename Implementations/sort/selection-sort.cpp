//sorta em O(n^2)

	for(int i=0; i<n; i++){
		menor=INF;
		for(int j=0; j<n; j++){
			if(marc[j]==0 && v[j]<menor){
				menor=v[j];
				idx=j;
			}
		}
		cout << menor << " ";
		marc[idx]=1;
	}
