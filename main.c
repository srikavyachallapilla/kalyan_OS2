#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main (int argc, char *argv[])
{

  int n;
  int num;
  printf ("Enter the number \n");

  if (argc == 1)
    {
      fprintf (stderr, "please enter the input\n");
      return -1;
    }

  n = atoi (argv[1]);
  num = n + 3;

  if (n < 1)
    {
      fprintf (stderr, "Input must be a positive integer.\n");
      return -1;
    }

  pid_t pid, pid1;
  
  pid = fork ();
 
  pid1 = fork ();

  if (pid < 0)
    {
      fprintf (stderr, "Fork Failed\n");
      return 1;
    }

  else if (pid == 0)
    {

      printf (" From Child1 n=%d, ", n);
      while (n > 1)
	{
	  if (n % 2 == 0)
	    {
	      n = n / 2;
	      printf ("From Child1 n=%d, ", n);
	    }
	  else
	    {
	      wait(0);
	    }


	}
      

    }
    printf("\n");
    





  if (pid1 < 0)
    {
      fprintf (stderr, "Fork Failed\n");
      return 1;
    }

  else if (pid1 == 0)
    {
      printf (" From Child2 n=%d, ", num);
      while (num > 1)
	{
	  if (num % 2 == 1)
	    {
	      num = num * 3 + 1;
	      printf ("From Child2 n=%d, ", num);
	    }
	  else
	    {
	      sleep(1);
	      wait(0);
	    }

	}
      




    }
 
}
