#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
  public:
  Queue();
  /* implement copy constructor, assignment, destructor if needed */
  void createEmptyQueue(Queue *q);
  void enqueue(float value);
  float dequeue();

  private:
  /* declare your data */
  struct QueueNode;
  struct Queue;
};


#endif
