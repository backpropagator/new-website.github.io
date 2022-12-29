#include<bits/stdc++.h>
using namespace std;
void built(int* tree,int* lazy,int* a,int start,int end,int index)
{
	if(start==end)
	{
		if(a[start]==1)
			tree[index]=1;
		else
			tree[index]=0;
		lazy[index]=2;
		return;
	}
	int mid=(start+end)/2;
	built(tree,lazy,a,start,mid,2*index);
	built(tree,lazy,a,mid+1,end,2*index+1);
	tree[index]=tree[2*index]+tree[2*index+1];
	lazy[index]=2;
}
void update(int* tree,int* lazy,int l,int r,int val,int start,int end,int index)

{
	if(start>r || end<l)
		return;
	if(start>=l && end<=r)
	{
		//cout<<index<<" "<<val<<" "<<start<<" "<<end<<" "<<tree[index]<<endl;
		if(val==1)
			tree[index]=(end+1)-start;
		else if(val==0)
			tree[index]=0;
		else
			tree[index]=(end+1)-(start+tree[index]);
		if(val==0 || val==1 ||(val==-1 && lazy[index]==2))
			lazy[index]=val;
		else if(lazy[index]==-1)
			lazy[index]=2;
		else
		{
			if(lazy[index]==0)
				lazy[index]=1;
			else if(lazy[index]==1)
				lazy[index]=0;
		}
		//cout<<index<<" "<<val<<" "<<start<<" "<<end<<" "<<tree[index]<<endl;
		return;
	}
	int mid=(start+end)/2;
	if(lazy[index]==1)
	{
		lazy[2*index]=1;
		lazy[2*index+1]=1;
		tree[2*index]=mid+1-start;
		tree[2*index+1]=end-mid;
		lazy[index]=2;
	}
	else if(lazy[index]==0)
	{
		lazy[2*index]=0;
		lazy[2*index+1]=0;
		tree[2*index]=0;
		tree[2*index+1]=0;
		lazy[index]=2;
	}
	else if(lazy[index]==-1)
	{
		if(lazy[2*index]==2)
			lazy[2*index]=-1;
		else if(lazy[2*index]==0)
			lazy[2*index]=1;
		else if(lazy[2*index]==1)
			lazy[2*index]=0;
		else if(lazy[2*index]==-1)
			lazy[2*index]=2;
		if(lazy[2*index+1]==2)
			lazy[2*index+1]=-1;
		else if(lazy[2*index+1]==0)
			lazy[2*index+1]=1;
		else if(lazy[2*index+1]==1)
			lazy[2*index+1]=0;
		else if(lazy[2*index+1]==-1)
			lazy[2*index+1]=2;
		tree[2*index]=mid+1-(tree[2*index]+start);
		tree[2*index+1]=end-(mid+tree[2*index+1]);
		lazy[index]=2;
	}
	update(tree,lazy,l,r,val,start,mid,2*index);
	update(tree,lazy,l,r,val,mid+1,end,2*index+1);
	tree[index]=tree[2*index]+tree[2*index+1];
}
int query(int* tree,int* lazy,int l,int r,int start,int end,int index)
{
	if(l>end || r<start)
		return 0;
	if(l<=start && r>=end)
		return tree[index];
	int mid=(start+end)/2;
	if(lazy[index]==1)
	{
		lazy[2*index]=1;
		lazy[2*index+1]=1;
		tree[2*index]=(mid+1)-start;
		tree[2*index+1]=end-mid;
		lazy[index]=2;
	}
	else if(lazy[index]==0)
	{
		lazy[2*index]=0;
		lazy[2*index+1]=0;
		tree[2*index]=0;
		tree[2*index+1]=0;
		lazy[index]=2;
	}
	else if(lazy[index]==-1)
	{
		if(lazy[2*index]==2)
			lazy[2*index]=-1;
		else if(lazy[2*index]==0)
			lazy[2*index]=1;
		else if(lazy[2*index]==1)
			lazy[2*index]=0;
		else if(lazy[2*index]==-1)
			lazy[2*index]=2;
		if(lazy[2*index+1]==2)
			lazy[2*index+1]=-1;
		else if(lazy[2*index+1]==0)
			lazy[2*index+1]=1;
		else if(lazy[2*index+1]==1)
			lazy[2*index+1]=0;
		else if(lazy[2*index+1]==-1)
			lazy[2*index+1]=2;
		tree[2*index]=(mid+1)-(start+tree[2*index]);
		tree[2*index+1]=(end-mid)-tree[2*index+1];
		lazy[index]=2;
	}
	int y=query(tree,lazy,l,r,start,mid,2*index);
	int z=query(tree,lazy,l,r,mid+1,end,2*index+1);
	//cout<<start<<" "<<end<<" "<<y<<" "<<z<<" "<<index<<endl;
	return y+z;
}
int main(int argc, char const *argv[])
{
	int t,T;
	cin>>T;
	for(int a0=1;a0<=T;a0++)
	{
		printf("Case %d:\n", a0);
		string s="";
		string r;
		int m;
		cin>>m;
		while(m--)
		{
			int t;
			cin>>t;
			cin>>r;
			while(t--)
			{
				s+=r;
			}
		}
		//cout<<s<<endl;
		int l=s.size();
		int a[l+1];
		for (int i = 0; i < l; ++i)
		{
			a[i+1]=s[i]-'0';
		}
		int tree[4*l];
		int lazy[4*l];
		built(tree,lazy,a,1,l,1);
		/*for(int i=1;i<=33;i++)
		{
			cout<<tree[i]<<endl;
		}*/
		int q;
		cin>>q;
		int count=1;
		lazy[0]=2;
		while(q--)
		{
			char ch;
			int c,v;
			cin>>ch>>c>>v;
			if(ch=='F')
			{
				update(tree,lazy,c+1,v+1,1,1,l,1);
			}
			else if(ch=='E')
				update(tree,lazy,c+1,v+1,0,1,l,1);
			else if(ch=='I')
				update(tree,lazy,c+1,v+1,-1,1,l,1);
			else
			{
				int result=query(tree,lazy,c+1,v+1,1,l,1);
				printf("Q%d: %d\n",count++,result );
			}
		}
	}
	return 0;
}

