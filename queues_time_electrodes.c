#include <stdio.h>
#include <stdlib.h>

struct queueNode{

    char data;
    struct queueNode *nextPtr;
};/* end struct queueNode struct */

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

/* I am going to open a prototype of a function*/

void printQueue( QueueNodePtr currrentPtr );
int isEmpty ( QueueNodePtr headPtr );
char dequeue ( QueueNodePtr *headPtr, QueueNodePtr *tailPtr );
void enqueue ( QueueNodePtr *headPtr, QueueNodePtr *tailPtr,
              char value );
void instructions ( void );

 int main()
{
   QueueNodePtr headPtr = NULL;
   QueueNodePtr tailPtr = NULL;
   int choice;
   char item;

   instructions(); /* display menu */
   printf(" What do you want to put?");

   scanf("%d", &choice );

   /* while user does not enter 3 spikes*/
   while ( choice != 3 ){

     switch ( choice ){
         /* enqueue value */
        case 1:
           printf(" please, enter a characte: " );
           scanf("\n%c", &item );
           enqueue( &headPtr, &tailPtr, item );
           printQueue( headPtr );
           break;

           /*dequeue value*/
           case 2:

             if (!isEmpty ( headPtr ) ){
               item = dequeue (&headPtr, &tailPtr );
               printf("%c has been dequeue. \n", item );
             }

             printQueue ( headPtr );
             break;

             default:
                printf( "Invalid choice.\n\n" );
                instructions();
                break;
     }/* end switch*/

     printf("? ");
     scanf("%d", &choice );
   }/*end while*/

   printf( "End of run. \n" );

   return 0;

} /* end main */

/* this is for displaying the program instructions to user*/

void instruction ( void )
{
   printf(" Enter your choice: \n"
          " 1 to add an item  to the queue\n"
          " 2 to remove an item from the queue\n"
          " 3 to end\n" );

}/* end of function instructions*/

/* there is a lot I need to do in this program:
*1: to express the fucntion enqueue
*2: to express the function to dequeue
*3: allocate memory to data being inserted.
*4: have to specify what to do when the qnode is empty */

void enqueue (
  QueueNodePtr
  *headPtr,
  QueueNodePtr
  *tailPtr,
  char value /* this the arguments this function needs to take*/
)
{
   QueueNodePtr newPtr; /* pointer to new node*/
   newPtr = malloc( sizeof (QueueNode ) );

   if( newPtr != NULL){ /* these are expresions to ask if theris fee space*/
     newPtr->data = value;
     newPtr->nextPtr =NULL;

   /* if there is empty space: insert node at the head FIFO*/
   if ( isEmpty( *headPtr ) ){
     *headPtr = newPtr;
   }/* end if*/
   else {
     ( *tailPtr )->nextPtr = newPtr;
    }
      *tailPtr = newPtr;

   }/* end if */
    else {
      printf("%c not inserted. No memory available. \n ", value );
    }
}/* end of function enqueue*/


/* This is the function to remove from queue */

char dequeue ( QueueNodePtr *headPtr , QueueNodePtr *tailPtr )
{
   char value;  /* node value */
   QueueNodePtr tempPtr;

   value =( *headPtr )->data;
   tempPtr = *headPtr;
   *headPtr = (*headPtr )->nextPtr;

   /* if the queue is empty*/
   if ( *headPtr == NULL ){
     *tailPtr = NULL;
   }/* end if */

   free( tempPtr );

   return value;

 } /* end function dequeue */

/* return 1 if the list is empty, 0 otherwise */

int isEmpty ( QueueNodePtr headPtr )
{
  return headPtr == NULL;
} /* this func is for empty*/

/* let's print the queue */
void printQueue ( QueueNodePtr currentPtr )
{

   if ( currentPtr == NULL )
   {
     printf( "Queue is empty.\n\n");
   }
   else {
     printf("The queue is:\n");
     /* While not end of queue */
     while( currentPtr != NULL){
       printf("%c --> ", currentPtr--> data );
       currentPtr = currentPtr->nextPtr;
     }

     printf("NULL\n\n" );
   }/* end else*/

}/* end of function enqueue*/
