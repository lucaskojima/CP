// Time Complexity: O(2^n)

void hanoi(int n, int ini, int fim){
	if(n==0) return;
	
	int k=6-ini-fim;
	hanoi(n-1, ini, k);
	cout << ini << " " << fim << '\n';
	hanoi(n-1, k, fim);
}
