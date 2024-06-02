#include "Wx_StdTypes.h"
#include "Wx_Static_LinkedList.h"
#include "Wx_Static_Queue.h"
#include "Wx_Static_Stack.h"

#include <stdio.h>

#define SZ 10

int main(void) {
    WX_DEFINE_A_QUEUE(mylist);

    WX_QUEUE_CTOR(mylist);

    WX_U8 x[SZ] = {0};
    void* data = NULL;

    for(WX_U8 i = 0; i < SZ ; i++) {
        x[i] = i;
        WX_QUEUE_ENQUEUE(mylist, x[i]);
    }

    for(WX_U8 i = 0; i < SZ ; i++) {
        WX_QUEUE_DEQUEUE(mylist, data);
        printf("%d ", WX_EXTRACT_DATA_FROM_QUEUE(WX_U8, data));
    }
    
    printf("\n");
    return 0;
}