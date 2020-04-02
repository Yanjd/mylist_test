#include<stdlib.h>
#include<iostream>


using namespace std;

template<typename T>
class DCLink;

template<typename T>
class DCLinkNode{
    friend class DCLink<T>;
    public:
        DCLinkNode(T x=0){
            prev=next=NULL;
            data=x;
        }
        ~DCLinkNode(){

        }
    private:
        T data;
        DCLinkNode *prev;
        DCLinkNode *next;   
};


template<typename T>
class DCLink
{
private:
    /* data */
    DCLinkNode<T> *first;
    DCLinkNode<T> *last;
    size_t size;
private:
    bool insert_pos();
public:
    DCLink(){
        DCLinkNode<T> *s=new DCLinkNode<T>;
        first=last=s;
        s->prev=last;
        s->next=first;
        size=0;  
    }
    ~DCLink(){

    }
public:
    bool push_back(const T &);
    void show() const;
    bool push_front(const T &);
    void clear() noexcept;
    //bool insert_val();
    bool pop_back();

};
template<typename T>
bool DCLink<T>::push_back(const T&x){
    DCLinkNode<T> *s=new DCLinkNode<T>(x);
    if(s==NULL){
        return false;
    }
    s->next=first;
    s->prev=last;
    last->next=s;
    first->prev=s;
    last=s;
    size++;
    return true;
}

template<typename T>
void DCLink<T>::show() const{
    DCLinkNode<T> *p=first->next;
    while(p!=first){
        cout<<p->data<<"-->>";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

template<typename T>
bool DCLink<T>::push_front(const T&x){
    DCLinkNode<T> *s=new DCLinkNode<T>(x);
    if(s==NULL){
        return false;
    }
    s->next=first->next;
    s->prev=first;
    first->next->prev=s;
    first->next=s;
    size++;
    return true;
}

template<typename T>
bool DCLink<T>::pop_back(){
    if(size==0){
        return false;
    }
    DCLinkNode<T> *temp=last;
    first->prev=last->prev;
    last->prev->next=first;
    last=last->prev;
    size--;
    delete temp;
    return true;
}

template<typename T>
void DCLink<T>::clear()noexcept{
    while (size)
    {
        pop_back();
    }
    
}
