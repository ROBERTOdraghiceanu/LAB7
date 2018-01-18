#include <stdio.h>

#include <stdlib.h>



typedef struct node

{

    int info;

    struct node * next;

};



int i;



int main()

{

    struct node * chestie = ( struct node *) malloc( sizeof( struct node) );

    chestie -> next = NULL;



    struct node * head = chestie;



    for( i = 0 ; i < 10 ; i++ )

    {

        struct node * newEl = ( struct node *) malloc( sizeof( struct node) );

        newEl -> next = NULL;

        newEl -> info = rand() % 101;



        chestie -> next = newEl;

        chestie = newEl;

    }



    chestie = head;

    printf( "\nThe list look like: ");

    while( chestie -> next )

    {

        chestie = chestie -> next;

        printf( "\n%d", chestie -> info );

    }



    struct node * chestieCopie = ( struct node *) malloc( sizeof( struct node) );

    chestieCopie -> info = chestie -> info;

    chestieCopie -> next = NULL;



    struct node * head2 = chestieCopie;



    chestie = head;



    while( chestie -> next )

    {

        chestie = chestie -> next;



        struct node * newEl = ( struct node *) malloc( sizeof( struct node) );

        newEl -> info = chestie -> info;



        newEl -> next = chestieCopie;

        chestieCopie = newEl;

    }



    printf( "\nAnd the copy-list look: ");

    while( chestieCopie -> next )

    {

        printf( "\n%d", chestieCopie -> info );

        chestieCopie = chestieCopie -> next;

    }



    while( head -> next )

    {

        chestie = head -> next;

        free( head );

        head = chestie;

    }



    while( head2 -> next )

    {

        chestie = head2 -> next;

        free( head2 );

        head2 = chestie;

    }





    return 0;

}
