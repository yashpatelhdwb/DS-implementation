#include <stdio.h>

void towerOfHanoi(int n, char x, char y, char z){
    if (n == 1){
        printf("Move disk 1 from rod %c to rod %c\n", x, y);
        return;
    }
    towerOfHanoi(n-1,x,z,y);
    printf("Move disk %d from rod %c to rod %c\n", n, x, y);
    towerOfHanoi(n-1, z, y, x);
}
 
int main()
{
  int n,t;
  printf("Enter the number of inputs\n");
  scanf("%d",&t);
  printf("Input the number of pegs\n");
  while(t--){
    scanf("%d",&n);
  }
  towerOfHanoi(n, 'A', 'C', 'B');  
  return 0;
}
  