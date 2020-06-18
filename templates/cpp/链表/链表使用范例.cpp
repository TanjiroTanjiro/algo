//By: Luogu@wangdemao(308854)
#include <iostream>
#include "Á´±í.hpp"

using namespace std;
using namespace wangdemao;

int main()
{
	int n,m,p=0;
	
	cin>>n>>m;
	
	LinkedList<int> q(n);
	
	int cnt=1;
	
	while(!q.empty())
	{
		cnt++;
		p++;
		p%=q.size();
		if(cnt==m)
		{
			int t=p;
			cout<<q[p+1]<<" ";
			q.remove(t+1);
			cnt=1;	
		}
	}
	
	return 0;
}
