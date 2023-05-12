#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <timer.h>

#include "queue.hh"

//#define DEBUG

int main(int argc, char* argv[]){

    int n = -1;
    int t = -1;

    if(argc == 3){
        n = atoi (argv[1]);
        t = atoi (argv[2]);
        assert(n > 0);
        assert(t > 0);
    }
    else{
        fprintf(stderr, "usage: %s <n> <t>\n", argv[0]);
        fprintf(stderr, "where <n> is the length of the queue\n");
        fprintf(stderr, "and <t> is the number of the dequeue/enqueue operation pairs\n");
        return -1;
    }

    struct stopwatch_t* timer = stopwatch_create();
    assert(timer);

    Queue queue;

    queue.CreateQueue(n+1);

    srand(time(0));

    for(int i = 0; i < n; i++){
        float a = (float) (rand()) / (float) (RAND_MAX / 50.0);
        queue.enqueue(a);
    }

#ifdef DEBUG
    queue.printQueue();
#endif
    
    stopwatch_start(timer);
    for(int i = 0; i < t; i++){
        float j;

        j = queue.dequeue();
        assert(j >= 0.0);

        queue.enqueue(j);
    }
    long double t_exe = stopwatch_stop(timer);
    printf("Average time: %Lg\n", t_exe/t);
    queue.deleteQueue();

    return 0;
}