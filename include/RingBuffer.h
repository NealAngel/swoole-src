#ifndef _SW_RINGBUFFER_H_
#define _SW_RINGBUFFER_H_

#define SW_BUFFER_LEN  10

typedef struct _swRingBuffer
{
	int head; /* 头部，出队列方向*/
	int tail; /* 尾部，入队列方向*/
	int tag; /* 为空还是为满的标志位*/
	int size; /* 队列总尺寸 */
	void *data[SW_BUFFER_LEN]; /* 队列空间 */
} swRingBuffer;

extern int swRingBuffer_init(swRingBuffer *);
extern int swRingBuffer_push(swRingBuffer *, void *);
extern int swRingBuffer_pop(swRingBuffer *, void **);

#define swRingBuffer_empty(q) ( (q->head == q->tail) && (q->tag == 0))
#define swRingBuffer_full(q) ( (q->head == q->tail) && (q->tag == 1))
#endif 
