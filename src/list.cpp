#include"list.h"
#include<iostream>
LinkList::LinkList()
{
}
LinkList::~LinkList()
{
}
Node * LinkList::Init()
{
	head = new Node;
	head->data = NULL;
	head->next = NULL;
	head->pre = NULL;
	len=0;
	return head;
}

Node* LinkList::Init(int nums[],int len)
{
	Init();
	for(int i=0;i<len;nums++,i++)
	{
		my_push_back(*(nums));
	}
	return head;
}

Node* LinkList::GetNodeHead()
{
	return head;
}

void LinkList::InsertElemAtIndex_Behind(int pos,Typename_t input)
{
	if (pos < 0)
	{
		return;
	}
	else
	{
		int flag = 0;
		Node * p = new Node;
	
			p = head;
			while (p->next != NULL && flag != pos ) {
				flag++;
				p = p->next;
			}
			if (p->next ==NULL && flag < pos)
			{
				return;
			}
			else
			{
				if(p->next==NULL)
				{
					my_push_back(input);
				}else
				{
				Node* temp = new Node;
				temp->data=input;
				temp->next = p->next;
				(p->next)->pre=temp;
				p->next = temp;
				temp->pre=p;
				temp->data = input;
				len++;

				}
				return;
			}
	}
}

void LinkList::InsertElemAtIndex_Front(int pos,Typename_t input)
{
	if (pos <= 0)
	{
		std::cout<<"illegal position!"<<std::endl;
		return;
	}
	else
	{
		int flag = 0;
		Node * p = new Node;
	
			p = head;
			while (p->next != NULL && flag != pos ) {
				flag++;
				p = p->next;
			}
			if (p->next ==NULL && flag < pos)
			{
				return;
			}
			else
			{
				Node* temp = new Node;
				temp->data=input;
				temp->pre=p->pre;
				(p->pre)->next=temp;
				p->pre=temp;
				temp->next=p;
				len++;
				return;
			}
	}


}

void LinkList::my_push_back(Typename_t input)
{
	Node * p = new Node;
	p = head;
	while (true) 
	{
		if(p->next==NULL)
		{
			Node* temp=new Node;
			temp->data=input;
			p->next=temp;
			temp->pre=p;
			temp->next=NULL;
			len++;
			break;
		}
		p = p->next;
	}
}

void LinkList::my_pop_back(Typename_t &output)
{
	Node * p = new Node;
	p = head;
	while (true) 
	{
		if(p->next==NULL)
		{
			(p->pre)->next=NULL;
			output=p->data;
			delete p;
			len--;
			break;
		}
		p = p->next;
	}

}


Node* LinkList::GetElemByIndex(int a)
{
	Node* p = new Node;
	int flag = 0;
	if (head->next == NULL)
	{
		return head;
	}
	while (true)
	{
		flag++;
		if (flag == 1)
		{
			p = head->next;
		}
		else
		{
			p = p->next;
		}
		if (p->data == a)
		{
			return p;
		}
		if (p->next == NULL)
		{
			return head;
		}
	}
	return head;
}
void LinkList::TravelLinkList()
{
	int flag = 0;
	if (head->next == NULL)
	{
		return;
	}
	else
	{
		Node* p = new Node;
		while (true) {
			flag++;
			if (flag == 1)
			{
				p = head->next;
			}
			else
			{
				p = p->next;
			}
			std::cout << "Number" << flag << ":" << p->data << std::endl;
			if (p->next == NULL)
			{
				std::cout<<std::endl;
				return ;
			}
		}
	}
}
bool LinkList::IsEmpty()
{
	if (head->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void LinkList::ClearLinkList()
{
	Node* p = new Node;
	Node* q = new Node;
	p = head->next;
	while (p)
	{
		q = p->next;
		delete p;
		len--;
		p = q;
	}
	head->next = NULL;
}
void LinkList::DeleteElemAtIndex(int a)
{
	if (a < 0||IsEmpty())
	{
		return;
	}
	else
	{
		int flag = 0;
		Node* p = new Node;
		Node* pre = new Node;
		p = head;
		while (p->next != NULL && flag != a) {
			if (flag == a - 1)
			{
				pre = p;
			}
			flag++;
			p = p->next;
		}
		if (p->next == NULL && flag < a)
		{
			return;
		}
		else
		{
			pre->next = p->next;
			delete p;
			len--;
		}
	}
}
int LinkList::GetLength()
{
	// int flag = 0;
	// if (head->next == NULL)
	// {
	// 	return 0;
	// }
	// else
	// {
	// 	Node* p = new Node;
	// 	while (true) {
	// 		flag++;
	// 		if (flag == 1)
	// 		{
	// 			p = head->next;
	// 		}
	// 		else
	// 		{
	// 			p = p->next;
	// 		}
	// 		if (p->next == NULL)
	// 		{
	// 			return flag;
	// 		}
	// 	}
	// }
	return len;
}