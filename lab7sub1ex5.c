#include <stdio.h>

#include <stdlib.h>



typedef struct rando{

    int no;

    struct rando *next;

};



int i;

int sum = 0;



int main()

{

    struct rando * first = (struct rando *)malloc(sizeof(struct rando)) ;

    first -> next = NULL;



    struct rando * head = first;

    struct rando * newEl;



    for ( i = 0; i < 25 ; i++ )

    {

        newEl = (struct rando *)malloc(sizeof(struct rando));

        newEl -> no = rand() % 101;

        first -> next = newEl;

        newEl -> next = NULL;

        first = newEl;

    }



    printf ( "The numbers are : ");



    first = head;



    while ( first -> next )

    {

        first = first -> next;

        printf( "\n %d ", first -> no );

    }





    first = head;



    while ( first -> next )

    {

        first = first -> next;

        sum += first -> no;

    }



    printf ( "\nThe sum of the elements is : %d ", sum );



    printf ( "\nThe the floating-point average of the elements is : %.4f \n", (float) sum / 25 );



    while ( head -> next )

    {

        first = head -> next;

        free( head );

        head = first;

    }



    return 0;

}
