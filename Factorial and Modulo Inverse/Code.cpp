const int N = 300005;
const int MOD = 1e9 + 7;
const int inf = 1e18 + 1;
/***************************code begins here*****************************/
int fact[N],inv[N];
int power(int x, unsigned int y) {  
    int res = 1;
    x = x % MOD;
    if (x == 0) return 0;
  
    while (y > 0) { 
        if (y & 1)  
            res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;  
    }  
    return res;  
}
int modInv(int a){return power(a,MOD-2);}
void pre(){
	fact[0]=1;
	for(int i=1;i<N;i++){
		fact[i]=fact[i-1]*i;
		if(fact[i]>=MOD)
			fact[i]%=MOD;
	}
	inv[0]=1;
	for(int i=1;i<N;i++)
		inv[i]=modInv(fact[i]);
}
int ncr(int n,int r){
	if(n<r||n<0||r<0) return 0;
	int b=inv[n-r], c=inv[r], a=fact[n]*b;
	if(a>=MOD) a%=MOD; a*=c;
	if(a>=MOD) a%=MOD;
	return a;
}

// First call the pre() function and then call the ncr() function.