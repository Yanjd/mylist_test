class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        myfifo=new int[k];
        capacity=k;
        head=-1;
        tail=-1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;
        else if(tail==capacity-1){
            tail=0;
        }
        else if(isEmpty()){
            head=tail=0;
        }
        else{
            tail++;
        }
        myfifo[tail]=value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else if(head==tail)
            head=tail=-1;
        else if(head==capacity-1)
            head=0;    
        else{
            head++;
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
            return -1;
        else{
            return myfifo[head];
        }
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
            return -1;
        else
            return myfifo[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if((head==tail&&head==-1))
            return true;
        else
            return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if((head==tail+1)||(head==0&&tail==capacity-1))
            return true;
        else
            return false;
    }
private:
    int *myfifo; 
    size_t capacity;
    int head;
    int tail;
};
