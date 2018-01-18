#include <stdio.h>

#include <stdlib.h>



typedef struct whatever

{

    char no;

    struct whatever * next;

};



typedef struct whatever2

{

    char no2;

    struct whatever2 * next;

};



void concatenate ( struct whatever * p , struct whatever2 * head2 );



int i;



int main()

{

    struct whatever * p = ( struct whatever *) malloc( sizeof( struct whatever) );

    struct whatever2 * p2 = ( struct whatever2 *) malloc( sizeof( struct whatever2) );



    p -> next = NULL;

    p2 -> next = NULL;



    struct whatever * head = p;

    struct whatever2 * head2 = p2;



    for ( i = 0 ; i < 3 ; i++ )

    {

        struct whatever * newEl = ( struct whatever *) malloc( sizeof( struct whatever) );

        newEl -> no = rand() % 26 + 97;

        newEl -> next = NULL;

        p -> next = newEl;

        p = newEl;



        struct whatever2 * newEl2 = ( struct whatever2 *) malloc( sizeof( struct whatever2) );

        newEl2 -> no2 = rand() % 20 + 97;

        newEl2 -> next = NULL;

        p2 -> next = newEl2;

        p2 = newEl2;

    }



    p = head;

    printf ( "\n The elements of the first list are : ");

    while( p -> next )

    {

        p = p -> next;

        printf ( "\n %c ", p -> no);

    }



    p2 = head2;

    printf ( "\n The elements of the second list are : ");

    while( p2 -> next )

    {

        p2 = p2 -> next;

        printf ( "\n %c ", p2 -> no2);

    }



    concatenate (  p , head2 );



    printf ( "\n The elements of the first list, now, are : ");



    p = head;



    while ( p -> next )

    {

        p = p -> next;

        printf ( "\n %c ", p -> no);

    }



    while ( head -> next )

    {

        p = head -> next;

        free( head );

        head = p;

    }

    return 0;

}



void concatenate ( struct whatever * p , struct whatever2 * head2 )

{

    p -> next = head2 -> next;

}
