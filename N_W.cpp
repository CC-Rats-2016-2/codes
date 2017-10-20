#include<bits/stdc++.h>
using namespace::std;

const int d = -1;
const int nel = 0;
const int yes = 1;
const int N = 20;


int n,m;
int v[N][N];
int direction[N][N];
string a,b;

int max(int a, int b, int c){ return max(a,max(b,c));}

int val(char x, char y){
	return x==y?yes:nel;
}

int main(){
	cin >> a >> b;
	cout << a << endl << b << endl;
	n = a.size();
	m = b.size();
	for(int i=0; i<n; i++) v[i][0] = d*i;
	for(int j=0; j<m; j++) v[0][j] = d*j;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			int c1 = v[i-1][j-1] + val(a[i-1],b[j-1]);
			int c2 = v[i-1][j] + d;
			int c3 = v[i][j-1] + d;
			if(max(c1,c2,c3) == c1){
				v[i][j] = c1;
				direction[i][j] = 1;
			}
			else if(max(c1,c2,c3) == c2){
				v[i][j] = c2;
				direction[i][j] = 2;
			}
			else{
				v[i][j] = c3;
				direction[i][j] = 3;
			}
		}
	}
	cout << "MAXIMO SCORE: " << v[n][m] << endl;
	puts("VALORES EN EL CAMINO");
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			cout << v[i][j] << " ";
		}
		puts("");
	}
	int i = n, j = m;
	string A = "";
	string B = "";
	while(i!=0 and j!=0){
		int score = v[i][j];
		int scoreD = v[i-1][j-1];
		int scoreU = v[i-1][j];
		int scoreL = v[i][j-1];
		if(score == scoreD + val(a[i-1],b[j-1])){
			A = a[i-1] + A;
			B = b[j-1] + B;
			i-=1;
			j-=1;
		}
		else if(score == scoreU + d){
			A = a[i-1] + A;
			B = '-' + B;
			i -= 1;
		}
		else{
			A = '-' + A;
			B = b[j-1] + B;
			j -=1;
		}
	}
	while(i > 0){
		A = a[i--] + A;
		B = '-' + B; 
	}
	while(j > 0){
		B = b[j--] + B;
		A = '-' + A;
	}
	cout << A << endl;
	cout << B << endl;
	return 0;
}
