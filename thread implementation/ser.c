#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main ()
{

 

  key_t shm_key = 6166529;
  const int shm_size = 2048;

  int a ;
  int shm_id;
  char* shmaddr, *ptr;
  int next[10];

   

  /* Allocate a shared memory segment. */
  shm_id = shmget (shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);

  /* Attach the shared memory segment. */

 shmaddr = (char*) shmat (shm_id, 0, 0);

  printf ("shared memory attached at address %p\n", shmaddr);

  /* Start to write data. */
  ptr = shmaddr + sizeof (next);
  next[0] = sprintf (ptr,"Cone") + 1;
  ptr += next[0];
  next[1] = sprintf (ptr,"Cream") + 1;
  ptr += next[1];
  next[2] = sprintf (ptr,"Choclolate ") + 1;
  ptr += next[2];
  next[3] = sprintf (ptr,"Mango Flavour") + 1;
  ptr += next[3];
  next[4] = sprintf (ptr,"Stawbery Flavour") + 1;
  ptr += next[4];
  next[5] = sprintf (ptr,"Vanila Flavour") + 1;
  ptr += next[5];
  next[6] = sprintf (ptr,"Kulfa Flavour") + 1;
  ptr += next[6];
  next[7] = sprintf (ptr,"Extra Topping") + 1;
  ptr += next[7];
  next[8] = sprintf (ptr,"Special Flavoured Cream") + 1;
  ptr += next[8];
  next[9] = sprintf (ptr,"Packaging and Serving") + 1;
  ptr += next[9];

  memcpy(shmaddr, &next, sizeof (next));
  

  /*calling the other process*/

 
  system("./cli");

  /* Detach the shared memory segment. */
  shmdt (shmaddr);
  /* Deallocate the shared memory segment.*/
  shmctl (shm_id, IPC_RMID, 0);

  return 0;
}


