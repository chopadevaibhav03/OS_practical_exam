// Q.1 Write a C program to accept the number of process and resources and find the need matrix content and display it.

#include <stdio.h>

int main() {
   int p, r;
   printf("Enter the number of processes: ");
   scanf("%d", &p);
   printf("Enter the number of resources: ");
   scanf("%d", &r);

   int need[p][r];

   printf("\nThe need matrix is: \n");
   for (int i = 0; i < p; i++) {
      for (int j = 0; j < r; j++) {
         need[i][j] = i + j;  // compute element of need matrix
         printf("%d ", need[i][j]);
      }
      printf("\n");
   }

   return 0;
}
