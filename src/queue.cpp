#include<iostream>
#include"../include/queue.h"

ArrQueue::ArrQueue()
{
    this->front=-1;
    this->end=-1;
    this->size=0;
}
ArrQueue::~ArrQueue(){}

bool ArrQueue::enqueue(int input)
{
    if(is_full()) return false;
    if(front==-1)
    {
        front++;
        end++;
        data[end]=input;
        size++;
        return true;
    }else
    {
        end=(end+1)%ARR_MAX;
        data[end]=input;
        size++;
        return true;
    }
}

bool ArrQueue::dequeue(int &output)
{
    if(is_empty()) return false;
    if(front==0&&end==0)
    {
        output=data[0];
        data[0]=0;
        front--;
        end--;
        size--;
        return true;
    }
    output=data[front];
    front=(front+1)%ARR_MAX;
    size--;
    return true;
}
bool ArrQueue::is_full()
{
    if(front-end==1) return true;
    return false;
}

bool ArrQueue::is_empty()
{
    if(front==end) return true;
    return false;
}

int ArrQueue::get_size()
{
    return size;
}

void ArrQueue::print()
{
    if(is_empty()) return;
    int temp=front;
    while(true)
    {
        std::cout<<data[temp]<<' '<<std::endl;
        if(temp==end)
        {
            std::cout<<std::endl;
            return;
        }
        temp=(temp+1)%ARR_MAX;
    }
}

ArrQueue &ArrQueue::operator+(int input)
{
    enqueue(input);
    return *this;
}

ArrQueue &ArrQueue::operator-(int &output)
{
    dequeue(output);
    return *this;
}

std::ostream &operator<<(std::ostream &os,const ArrQueue arrqueue)
{
    ArrQueue queue_clone=arrqueue;
    int temp=0;
    while(!queue_clone.is_empty())
    {
        queue_clone.dequeue(temp);
        std::cout<<temp<<' '<<std::endl;
    }
    std::cout<<std::endl;
    return os;
}
