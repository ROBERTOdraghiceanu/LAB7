#include <stdio.h>

#include <stdlib.h>





typedef struct simplyList

{

    int info;

    struct simplyList * next;

};



typedef struct doubleList

{

    int no;

    struct doubleList * next;

    struct simplyList * prev;

};



typedef struct circularList

{

    int value;

    struct circularList * next;

};



int i;



int main()

{

    struct simplyList * one = (struct simplyList* ) malloc( sizeof( struct simplyList) );

    one -> next = NULL;

    struct simplyList * head1 = one;



    struct doubleList * two = (struct doubleList* ) malloc( sizeof( struct doubleList) );

    two -> prev = NULL;

    two -> next = NULL;

    struct doubleList * head2 = two;



    struct circularList * three = (struct circularList* ) malloc( sizeof( struct circularList) );

    three -> next = NULL;

    struct circularList * head3 = three;



    for( i = 0 ; i < 5 ; i++ )

    {

        struct simplyList * newE1 = (struct simplyList* ) malloc( sizeof( struct simplyList) );

        newE1 -> next = NULL;

        newE1 -> info = rand() % 30;



        one -> next = newE1;

        one = newE1;



        struct doubleList * newE2 = (struct doubleList* ) malloc( sizeof( struct doubleList) );

        newE2 -> prev = two;

        newE2 -> next = NULL;

        newE2 -> no = rand() % 50;



        two -> next = newE2;

        two = newE2;



        struct circularList * newE3 = (struct circularList* ) malloc( sizeof( struct circularList) );

        newE3 -> next = NULL;

        newE3 -> value = rand() % 40;



        three -> next = newE3;

        three = newE3;

    }



    three -> next = head3 -> next;



    one = head1;

    two = head2;



    printf( "\nThe simply linked list:" );

    while( one -> next )

    {

        one = one -> next;

        printf( "\n%d", one -> info );

    }



    printf( "\n\nThe double linked list:" );

    while( two -> next )

    {

        two = two -> next;

        printf( "\n%d", two -> no );

    }



    printf( "\nThe double linked list reverse:" );

    while( two -> prev )

    {

        printf( "\n%d", two -> no );

        two = two -> prev;

    }



    printf( "\n\nThe circular liked list:" );

    for( i=0 ; i < 17 ; i++ )

    {

        three = three -> next;

        printf( "\n%d", three -> value );

    }





    while( head1 -> next )

    {

        one = head1 -> next;

        free( head1 );

        head1 = one;

    }





    while( head3 -> next )

    {

        three = head3 -> next;

        free( head3 );

        head3 = three;

    }



    return 0;

}
