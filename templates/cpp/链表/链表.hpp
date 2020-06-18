#include <iostream>

#ifndef __wdm_LinkedList__
#define __wdm_LinkedList__

namespace wangdemao
{
	template<typename T>
	class LinkedList
	{
		private:
			struct Node
			{
				T data;
				Node* next;
			};
			Node* head;
			int size000;
			
		public:
			LinkedList(int n=0)
			{
				Node* head000=new Node;
				head000->next=nullptr;
				Node* tail=head000;
				//建立n个节点
				for(int i=1; i<=n; i++)
				{
					Node* p=new Node;
					p->next=nullptr;
					tail->next=p;
					tail=p;
				}
				size000=n;
				head=head000;
			}

			void output()
			{
				if(head == nullptr)
				{
					return ;
				}

				Node* p=head->next;
				while(p != nullptr)
				{
					std::cout<<p->data<<" ";
					p=p->next;
				}
				std::cout<<std::endl;
			}

			T find(int x)
			{
				if(head == nullptr)
				{
					return 0;
				}
				Node* p=head->next;
				while(p!=nullptr)
				{
					if(p->data==x)
					{
						return p->data;
					}
					p=p->next;
				}
			}

			T get(int n)
			{
				Node* p=head;
				for(int i=1; i<=n; i++)
				{
					if(p==nullptr)
					{
						return 0;
					}
					p=p->next;
				}
				return p->data;
			}

			T operator[](int n)
			{
				Node* p=head;
				for(int i=1; i<=n; i++)
				{
					if(p==nullptr)
					{
						return 0;
					}
					p=p->next;
				}
				return p->data;
			}

			void insert(int n,T x)
			{
				Node* p=get(n-1);
				if(p==nullptr)
					return nullptr;
				Node* q=new Node;
				q->data=x;
				q->next=p->next;
				p->next=q;
				size000++;
			}

			bool empty()
			{
				if(size000==0)
					return true;
				return false;
			}

			void remove(int n)
			{
				T p=get(n-1);
				if(p==nullptr || p->next==nullptr)
					return ;

				Node *q = p->next;
				p->next=q->next;
				size000--;
				delete q;
			}

			int length()
			{
				return size000;
			}

			int size()
			{
				return size000;
			}

			~LinkedList()
			{
				while(head!=nullptr)
				{
					Node* p=head;
					head=head->next;
					delete p;
				}
			}
	};
}

#endif
