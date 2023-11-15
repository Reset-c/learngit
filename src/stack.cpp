#include<iostream>
#include"../include/stack.h"

ArrStack::ArrStack()
{
    this->size=0;
}

ArrStack::~ArrStack(){};

 bool ArrStack::push(int n)
{
    if(this->is_full()) return false;
    (this->arr_data)[this->get_size()]=n;
    this->size++;
    return true;
}

bool ArrStack::pop(int &n)
{
    if(this->is_empty()) return false;
    n=this->arr_data[this->get_size()-1];
    this->size--;
    return true;

}
bool ArrStack::is_empty() const
{
    if(this->get_size()==0) return true;
    return false;
}
bool ArrStack::is_full() const
{
    if(this->get_size()==ARR_MAX) return true;
    return false;
}
int ArrStack::get_size() const
{
    return this->size;
}
ArrStack &ArrStack::operator+(int n)
{
    this->push(n);
    return *this;
}

ArrStack &ArrStack::operator-(int &n)
{
    this->pop(n);
    return *this;
}

std::ostream &operator<<(std::ostream &os,const ArrStack &stk)
{
    int n=0;
    ArrStack stk_clone=stk;
    while(!stk_clone.is_empty())
    {
        stk_clone.pop(n);
        os<<n<<' ';
    }
    std::cout<<std::endl;
    return os;
}

void ArrStack::print() const
{
    int n=0;
    ArrStack stk_clone=*this;
    while (!stk_clone.is_empty())
    {
        stk_clone.pop(n);
        std::cout<<n<<' ';
    } 
    std::cout<<std::endl;
}

ListStack::ListStack(){}

ListStack::~ListStack(){}

void ListStack::Init()
{
    list.Init();
}

void ListStack::Init(int nums[],int len)
{
    Init();
    for(int i=0;i<len;i++,nums++)
    {
        list.my_push_back(*(nums));
    }
}

bool ListStack::push(Typename_t input)
{
    list.my_push_back(input);
    return true;
}

bool ListStack::pop(Typename_t &output)
{
    if(is_empty()) return false;
    list.my_pop_back(output);
    return true;
}

bool ListStack::is_empty()
{
    if(list.IsEmpty()) return true;
    return false;
}

int ListStack::get_size()
{
    return list.GetLength();
}

void ListStack::print()
{
    list.TravelLinkList();
}

ListStack &ListStack::operator+(Typename_t input)
{
    list.my_push_back(input);
    return *this;
}

ListStack &ListStack::operator-(Typename_t &output)
{
    list.my_pop_back(output);
    return *this;
}

std::ostream &operator<<(std::ostream &os,ListStack &liststk)
{
    int n=0;
    ListStack liststk_clone=liststk;
    while(!liststk.is_empty())
    {
        liststk_clone.pop(n);
        os<<n<<' ';
    }
    return os;
}