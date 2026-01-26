#include<stdio.h>
int main() {
        int a,b,c,largest;
        printf("Program to find the largest of 3 integers\n");
        printf("Enter three numbers: ");
        scanf("%d%d%d",&a,&b,&c);
        largest=a;
        if(b>largest) largest=b;
        if(c>largest) largest=c;
      printf("The largest out of the three is %d\n",largest);
}
