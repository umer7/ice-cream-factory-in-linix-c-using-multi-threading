#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h> 
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Semaphore */

sem_t mutex;
int counter;
void *handler ( void *ptr) ;
void *handler1 ( void *ptr) ;
void *handler2 ( void *ptr) ;
void *handler3 ( void *ptr) ;
void *handler4 ( void *ptr) ;
void *handler5 ( void *ptr) ;
void *handler6 ( void *ptr) ;
void *handler7 ( void *ptr) ;
void *handler8 ( void *ptr) ;
void *handler9 ( void *ptr) ;


int main ()
{
  key_t shm_key = 6166529;
  const int shm_size = 2048;

  int shm_id;
  char* shmaddr, *ptr;
  char* shared_memory[10];
  int *p;

  /* Allocate a shared memory segment. */
  shm_id = shmget (shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);

  /* Attach the shared memory segment. */
  shmaddr = (char*) shmat (shm_id, 0, 0);

  printf ("shared memory attached at address %p\n", shmaddr);

  /* Start to read data. */
  p = (int *)shmaddr;
  ptr = shmaddr + sizeof (int) * 10;
  shared_memory[0] = ptr;
  ptr += *p++;
  shared_memory[1] = ptr;
  ptr += *p++;
  shared_memory[2] = ptr;
  ptr += *p++;
  shared_memory[3] = ptr;
  ptr += *p++;
  shared_memory[4] = ptr;
  ptr += *p++;
  shared_memory[5] = ptr;
  ptr += *p++;
  shared_memory[6] = ptr;
  ptr += *p++;
  shared_memory[7] = ptr;
  ptr += *p++;
  shared_memory[8] = ptr;
  ptr += *p++;
  shared_memory[9] = ptr;


counter = 0 ;

 int i[10];

    pthread_t thread_a;
    pthread_t thread_b;
    pthread_t thread_c;
    pthread_t thread_d;
    pthread_t thread_e;
    
    pthread_t thread_f;
    pthread_t thread_g;
    pthread_t thread_h;
    pthread_t thread_i;
    pthread_t thread_j;
    
    i[0] = 0; /* argument to threads */
    i[1] = 1;
    i[2] = 2;
    i[3] = 3;
    i[4] = 4;
    i[5] = 5; /* argument to threads */
    i[6] = 6;
    i[7] = 7;
    i[8] = 8;
    i[9] = 9;
    
    sem_init(&mutex, 0, 1);      /* initialize mutex to 1 - binary semaphore */
      
    int n ;                           /* second param = 0 - semaphore is local */
                                 
    /* Note: you can check if thread has been successfully created by checking return value of

     pthread_create */ 
 
int mythread;
 printf("enter number of counters you want\n");
scanf("%d",&mythread);
 


switch (mythread)
{ 
case 1: 
    n=0;
    pthread_create (&thread_a, NULL, (void *) &handler,shared_memory[n]); 
   pthread_join(thread_a, NULL);
   
 break;


case 2: 
     n=0;
    pthread_create (&thread_a, NULL, (void *) &handler,shared_memory[n]);
    n=1;
    pthread_create (&thread_b, NULL, (void *) &handler1,shared_memory[n]);
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
   
    break;



case 3: 
    n=0;
    pthread_create (&thread_a, NULL, (void *) &handler,shared_memory[n]);
    n=1;
    pthread_create (&thread_b, NULL, (void *) &handler1,shared_memory[n]);
    n=2;
    pthread_create (&thread_c, NULL, (void *) &handler2,shared_memory[n]);
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);
   

  break;

case 4: 
    n=0;
    pthread_create (&thread_a, NULL, (void *) &handler,shared_memory[n]);
    n=1;
    pthread_create (&thread_b, NULL, (void *) &handler1,shared_memory[n]);
    n=2;
    pthread_create (&thread_c, NULL, (void *) &handler2,shared_memory[n]);
    n=3;    
    pthread_create (&thread_d, NULL, (void *) &handler3,shared_memory[n]);
   
   pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);
    pthread_join(thread_d, NULL);
  
    break;

case 5: 
    n=0;
    pthread_create (&thread_a, NULL, (void *) &handler,shared_memory[n]);
    n=1;
    pthread_create (&thread_b, NULL, (void *) &handler1,shared_memory[n]);
    n=2;
    pthread_create (&thread_c, NULL, (void *) &handler2,shared_memory[n]);
    n=3;    
    pthread_create (&thread_d, NULL, (void *) &handler3,shared_memory[n]);
    n=4;    
    pthread_create (&thread_e, NULL, (void *) &handler4,shared_memory[n]);
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);
    pthread_join(thread_d, NULL);
    pthread_join(thread_e, NULL);
 //   
case 6: 
    
    n=0;
    pthread_create (&thread_a, NULL, (void *) &handler,shared_memory[n]);
    n=1;
    pthread_create (&thread_b, NULL, (void *) &handler1,shared_memory[n]);
    n=2;
    pthread_create (&thread_c, NULL, (void *) &handler2,shared_memory[n]);
    n=3;    
    pthread_create (&thread_d, NULL, (void *) &handler3,shared_memory[n]);
    n=4;    
    pthread_create (&thread_e, NULL, (void *) &handler4,shared_memory[n]);
    n=5;
    pthread_create (&thread_f, NULL, (void *) &handler5,shared_memory[n]);
   
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);
    pthread_join(thread_d, NULL);
    pthread_join(thread_e, NULL);
    pthread_join(thread_f, NULL);

 break;


case 7: 
    n=0;
    pthread_create (&thread_a, NULL, (void *) &handler,shared_memory[n]);
    n=1;
    pthread_create (&thread_b, NULL, (void *) &handler1,shared_memory[n]);
    n=2;
    pthread_create (&thread_c, NULL, (void *) &handler2,shared_memory[n]);
    n=3;    
    pthread_create (&thread_d, NULL, (void *) &handler3,shared_memory[n]);
    n=4;    
    pthread_create (&thread_e, NULL, (void *) &handler4,shared_memory[n]);
    n=5;
    pthread_create (&thread_f, NULL, (void *) &handler5,shared_memory[n]);
    n=6;
    pthread_create (&thread_g, NULL, (void *) &handler6,shared_memory[n]);
  

    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);
    pthread_join(thread_d, NULL);
    pthread_join(thread_e, NULL);
    pthread_join(thread_f, NULL);
    pthread_join(thread_g, NULL);
    
   
    break;



case 8: 
    n=0;
    pthread_create (&thread_a, NULL, (void *) &handler,shared_memory[n]);
    n=1;
    pthread_create (&thread_b, NULL, (void *) &handler1,shared_memory[n]);
    n=2;
    pthread_create (&thread_c, NULL, (void *) &handler2,shared_memory[n]);
    n=3;    
    pthread_create (&thread_d, NULL, (void *) &handler3,shared_memory[n]);
    n=4;    
    pthread_create (&thread_e, NULL, (void *) &handler4,shared_memory[n]);
    n=5;
    pthread_create (&thread_f, NULL, (void *) &handler5,shared_memory[n]);
    n=6;
    pthread_create (&thread_g, NULL, (void *) &handler6,shared_memory[n]);
    n=7;
    pthread_create (&thread_h, NULL, (void *) &handler7,shared_memory[n]);
   

    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);
    pthread_join(thread_d, NULL);
    pthread_join(thread_e, NULL);
    pthread_join(thread_f, NULL);
    pthread_join(thread_g, NULL);
    pthread_join(thread_h, NULL);
  
   

  break;

case 9: 
    n=0;
    pthread_create (&thread_a, NULL, (void *) &handler,shared_memory[n]);
    n=1;
    pthread_create (&thread_b, NULL, (void *) &handler1,shared_memory[n]);
    n=2;
    pthread_create (&thread_c, NULL, (void *) &handler2,shared_memory[n]);
    n=3;    
    pthread_create (&thread_d, NULL, (void *) &handler3,shared_memory[n]);
    n=4;    
    pthread_create (&thread_e, NULL, (void *) &handler4,shared_memory[n]);
    n=5;
    pthread_create (&thread_f, NULL, (void *) &handler5,shared_memory[n]);
    n=6;
    pthread_create (&thread_g, NULL, (void *) &handler6,shared_memory[n]);
    n=7;
    pthread_create (&thread_h, NULL, (void *) &handler7,shared_memory[n]);
    n=8;    
    pthread_create (&thread_i, NULL, (void *) &handler8,shared_memory[n]);
  

    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);
    pthread_join(thread_d, NULL);
    pthread_join(thread_e, NULL);
    pthread_join(thread_f, NULL);
    pthread_join(thread_g, NULL);
    pthread_join(thread_h, NULL);
    pthread_join(thread_i, NULL);

    break;

case 10: 
    n=0;
    pthread_create (&thread_a, NULL, (void *) &handler,shared_memory[n]);
    n=1;
    pthread_create (&thread_b, NULL, (void *) &handler1,shared_memory[n]);
    n=2;
    pthread_create (&thread_c, NULL, (void *) &handler2,shared_memory[n]);
    n=3;    
    pthread_create (&thread_d, NULL, (void *) &handler3,shared_memory[n]);
    n=4;    
    pthread_create (&thread_e, NULL, (void *) &handler4,shared_memory[n]);
   
    n=5;
    pthread_create (&thread_f, NULL, (void *) &handler5,shared_memory[n]);
    n=6;
    pthread_create (&thread_g, NULL, (void *) &handler6,shared_memory[n]);
    n=7;
    pthread_create (&thread_h, NULL, (void *) &handler7,shared_memory[n]);
    n=8;    
    pthread_create (&thread_i, NULL, (void *) &handler8,shared_memory[n]);
    n=9;    
    pthread_create (&thread_j, NULL, (void *) &handler9,shared_memory[n]);
    
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);
    pthread_join(thread_d, NULL);
    pthread_join(thread_e, NULL);
    pthread_join(thread_f, NULL);
    pthread_join(thread_g, NULL);
    pthread_join(thread_h, NULL);
    pthread_join(thread_i, NULL);
    pthread_join(thread_j, NULL); 
    
break;


default:
    printf("error");
    
}


    
  // }
    sem_destroy(&mutex); /* destroy semaphore */
                   
    /* exit */   
    exit(0);
 

  /* Detach the shared memory segment. */
  shmdt (shmaddr);

}


void *handler (void *ptr)
{
    
    

    char *x = (char *) ptr  ;     


    sem_wait(&mutex);       /* down semaphore */
    
   printf("\norder of icecream arrived at COUNTER1 'CONE COUNTER' with delay of 5 seconds\n");
   printf("COUNTER1: Now in critical region...\n");
   printf("%s counter is processing\n",x) ;
   printf("ice-cream is in manufacturing process, wait please\n") ;
   sleep(5) ;
   printf("\n%s counter of icecream factory is passed Sir\n\n",x) ;
     
 /* END CRITICAL REGION */
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}


void *handler1 (void *ptr)
{
    
    

    char *x = (char *) ptr  ;     


    sem_wait(&mutex);       /* down semaphore */
    
   printf("\nicecream arrived at COUNTER2 'CREAM COUNTER' with delay of 5 seconds\n");
   printf("COUNTER2: Now in critical region...\n");
   printf("%s counter is processing\n",x) ;
   printf("ice-cream is in manufacturing process, wait please\n") ;
   sleep(5) ;
   printf("\n%s counter of icecream factory is passed Sir\n\n",x) ;
     
 /* END CRITICAL REGION */
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}


void *handler2 (void *ptr)
{
    
    

    char *x = (char *) ptr  ;     


    sem_wait(&mutex);       /* down semaphore */
    
   printf("\nicecream arrived at COUNTER3 'Chocolate COUNTER' with delay of 5 seconds\n");
   printf("COUNTER3: Now in critical region...\n");
   printf("%s counter is processing\n",x) ;
   printf("ice-cream is in manufacturing process, wait please\n") ;
   sleep(5) ;
   printf("\n%s counter of icecream factory is passed Sir\n\n",x) ;
     
 /* END CRITICAL REGION */
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}


void *handler3 (void *ptr)
{
    
    

    char *x = (char *) ptr  ;     


    sem_wait(&mutex);       /* down semaphore */
    
   printf("\nicecream arrived at COUNTER4 'Mango COUNTER' with delay of 5 seconds\n");
   printf("COUNTER4: Now in critical region...\n");
   printf("%s counter is processing\n",x) ;
   printf("ice-cream is in manufacturing process, wait please\n") ;
   sleep(5) ;
   printf("\n%s counter of icecream factory is passed Sir\n\n",x) ;
     
 /* END CRITICAL REGION */
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}


void *handler4 (void *ptr)
{
    
    

    char *x = (char *) ptr  ;     


    sem_wait(&mutex);       /* down semaphore */
    
   printf("\nicecream arrived at COUNTER5 'Stawbery COUNTER' with delay of 5 seconds\n");
   printf("COUNTER5: Now in critical region...\n");
   printf("%s counter is processing\n",x) ;
   printf("ice-cream is in PACKAGING process, wait please\n") ;
   sleep(5) ;
   printf("\n%s counter of icecream factory is passed Sir\n\n",x) ;
   //printf("\n.....CONGRATULATION Sir, ICE-CREAM is ready.....\n\n") ; 
 /* END CRITICAL REGION */
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}

void *handler5 (void *ptr)
{
   
    

    char *x = (char *) ptr  ;     


    sem_wait(&mutex);       /* down semaphore */
    
   printf("\norder of icecream arrived at COUNTER6 'Vanila COUNTER' with delay of 5 seconds\n");
   printf("COUNTER6: Now in critical region...\n");
   printf("%s counter is processing\n",x) ;
   printf("ice-cream is in manufacturing process, wait please\n") ;
   sleep(5) ;
   printf("\n%s counter of icecream factory is passed Sir\n\n",x) ;
     
 /* END CRITICAL REGION */
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}


void *handler6 (void *ptr)
{
   
    

    char *x = (char *) ptr  ;     


    sem_wait(&mutex);       /* down semaphore */
    
   printf("\nicecream arrived at COUNTER7 'Kulfa COUNTER' with delay of 5 seconds\n");
   printf("COUNTER7: Now in critical region...\n");
   printf("%s counter is processing\n",x) ;
   printf("ice-cream is in manufacturing process, wait please\n") ;
   sleep(5) ;
   printf("\n%s counter of icecream factory is passed Sir\n\n",x) ;
     
 /* END CRITICAL REGION */
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}


void *handler7 (void *ptr)
{
   
    

    char *x = (char *) ptr  ;     


    sem_wait(&mutex);       /* down semaphore */
    
   printf("\nicecream arrived at COUNTER8 'EXTRA TOPPING COUNTER' with delay of 5 seconds\n");
   printf("COUNTER8: Now in critical region...\n");
   printf("%s counter is processing\n",x) ;
   printf("ice-cream is in manufacturing process, wait please\n") ;
   sleep(5) ;
   printf("\n%s counter of icecream factory is passed Sir\n\n",x) ;
     
 /* END CRITICAL REGION */
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}


void *handler8 (void *ptr)
{
    
    

    char *x = (char *) ptr  ;     


    sem_wait(&mutex);       /* down semaphore */
    
   printf("\nicecream arrived at COUNTER9 'SPECIAL FLAVOURED CREAM COUNTER' with delay of 5 seconds\n");
   printf("COUNTER9: Now in critical region...\n");
   printf("%s counter is processing\n",x) ;
   printf("ice-cream is in manufacturing process, wait please\n") ;
   sleep(5) ;
   printf("\n%s counter of icecream factory is passed Sir\n\n",x) ;
     
 /* END CRITICAL REGION */
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}


void *handler9 (void *ptr)
{
    
    

    char *x = (char *) ptr  ;     


    sem_wait(&mutex);       /* down semaphore */
    
   printf("\nicecream arrived at COUNTER10 'PACKAGING AND SERVING COUNTER' with delay of 5 seconds\n");
   printf("COUNTER10: Now in critical region...\n");
   printf("%s counter is processing\n",x) ;
   printf("ice-cream is in PACKAGING process, wait please\n") ;
   sleep(5) ;
   printf("\n%s counter of icecream factory is passed Sir\n\n",x) ;
   printf("\n.....CONGRATULATION Sir, ICE-CREAM is ready.....\n\n") ; 
 /* END CRITICAL REGION */
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}








