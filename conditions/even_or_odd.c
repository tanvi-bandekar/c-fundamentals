#include<stdio.h>
int main() {
      int n;
      printf("Program to identify even/odd number\n");
      printf("Enter the number: ");
      scanf("%d",&n);
      if(n%2==0)
      {
        printf("The number entered is even\n");
      }
      else
      {
        printf("The number entered is odd\n");
      }
      return 0;
}
