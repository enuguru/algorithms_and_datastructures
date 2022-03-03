
#include "stdio.h"

	void towers(int,char,char,char);

	void towers(int n,char frompeg,char topeg,char auxpeg)
	{ /* If only 1 disk, make the move and return */
	  if(n==1)
	  { 
              printf("\nMove disk 1 from peg %c to peg %c",frompeg,topeg);
	      return;
	  }
	  /* Move top n-1 disks from A to B, using C as auxiliary */
	  towers(n-1,frompeg,auxpeg,topeg);
	  /* Move remaining disks from A to C */
	  printf("\nMove disk %d from peg %c to peg %c",n,frompeg,topeg);
	  /* Move n-1 disks from B to C using A as auxiliary */
	  towers(n-1,auxpeg,topeg,frompeg);
	}
        main()
	{ 
         int n;
	  printf("Enter the number of disks : ");
	  scanf("%d",&n);
	  printf("The Tower of Hanoi involves the moves :\n\n");
	  towers(n,'A','C','B');
	  return 0;
	}
