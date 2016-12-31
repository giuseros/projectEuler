#include <iostream>
#define N 100

using namespace std;

using long_t = long long;

long_t choose[N+1][N+1];
long_t count(0);

void init()
{
	for (int i = 0;i <=N;i++){
		for (int j = 0;j<=N;j++){
			choose[i][j] = 0;
		}
	}
	for (int i = 0; i<=N;i++){
		choose[0][i] = 1;
		choose[i][0] = 1;
	}

	for (int i = 1; i<=N; i++){
		for (int j = 1; j<=N-i;j++){
			if (choose[i-1][j] == -1 || choose[i][j-1] == -1){
				choose[i][j] = -1;
			} else {
				choose[i][j] = choose[i-1][j] + choose[i][j-1];
				if (choose[i][j] > 1e6){
					choose[i][j] = -1;
				}
			}
		}
	}
}

int main()
{
	init();
	int count(0);

	for (int i = 0;i<=N;i++){
		for (int j = 0;j<=N;j++){
			if (choose[i][j] == -1) count++;
		}
	}
	cout<<count<<endl;
}
