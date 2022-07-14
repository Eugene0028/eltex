#include <stdio.h>
#define N 5

void first_ex()
{
	int a[N][N], c = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			a[i][j] = c++;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}


void second_ex()
{
	int a[N];
	for (int i = 1; i <= N; i++){
		scanf("%d", &a[N-i]);
	}	
	for (int i = 0; i < N; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n\n");
}

void third_ex()
{
	int a[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i+j > N/2)
			{
				a[i][j] = 0;
			}
			if (i+j <= N/2+1)
			{
				a[i][j] = 1;
			}
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}



void fourth_ex() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[50][50];
    int i = 0, j = -1, count = 0;
    while (count < n*m) {
        while (j < m - 1 && !a[i][j+1])
            a[i][++j] = ++count;    // right
        while (i < n - 1 && !a[i+1][j])
            a[++i][j] = ++count;    // down
        while (j > 0 && !a[i][j-1])
            a[i][--j] = ++count;    // left
        while (i > 0 && !a[i-1][j])
            a[--i][j] = ++count;    // up
    }
            
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}


int main(){
	printf("first_ex\n");
	first_ex();
	printf("second_ex\n");
	second_ex();
	printf("third_ex\n");
	third_ex();
	printf("fourth_ex\n");
	fourth_ex();
	return 0;
}

