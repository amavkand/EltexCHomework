#include <stdio.h>

int main() {
  int N;

  printf("1.Введите размер матрицы: ");
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", i * N + j + 1);
    }
    printf("\n");
  }
  printf("2.Введите размер маccива: ");
  scanf("%d", &N);
  int a[N];
  for (int i = 0; i<N; i++){
  	scanf("%d", &a[i]);
  }
  
  for(int i = 0; i< N/2; i++){
  	int temp = a[i];
  	a[i] = a[N-1-i];
  	a[N-1-i] = temp;
  }
  
  for (int i = 0; i<N; i++){
  	printf("%d ",a[i]);
  }
  
  printf("\n");
  
  printf("3.Введите размер матрицы: ");
  scanf("%d", &N);
  int M[N][N];
  for (int i = 0; i<N; i++){
  	for (int j = 0; j<N;j++){
  		if(i+j >=N-1) M[i][j] = 1;
  		else M[i][j] = 0;
  	}
  }
  for (int i = 0; i<N; i++){
  	for (int j = 0; j<N;j++){
		printf("%d ", M[i][j]);
  	}
  	printf("\n");
  }
  
  printf("\n");
  
  printf("4.Введите размер матрицы: ");
  scanf("%d", &N);
  int K[N][N];
  
  int number = 1;
  int top = 0, bottom = N - 1, left = 0, right = N - 1;

  while (number <= N * N) {

    for (int i = left; i <= right; i++) {
      K[top][i] = number++;
    }
    top++;

    for (int i = top; i <= bottom; i++) {
      K[i][right] = number++;
    }
    right--;

    if (top <= bottom && left <= right) {
      for (int i = right; i >= left; i--) {
        K[bottom][i] = number++;
      }
      bottom--;
    }

    if (top <= bottom && left <= right) {
      for (int i = bottom; i >= top; i--) {
        K[i][left] = number++;
      }
      left++;
    }
  }
    for (int i = 0; i<N; i++){
  	for (int j = 0; j<N;j++){
		printf("%d ", K[i][j]);
  	}
  	printf("\n");
  }
}
