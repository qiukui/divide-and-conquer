#include<iostream>
#include<assert.h>

using namespace std;

double x_power_n_rec(int x,int n)    //函数x_power_n_rec递归的求解x的n次方
{
	assert(n>=0);
	if(n==0)
		return 1;
	else
		return x*x_power_n_rec(x,n-1);
}
double x_power_n_dc(int x,int n)  //函数x_power_n_dc用分治法求解x的n次方
{
	int k=n/2;
	double t;
	if(n==0) return 1;
	if(n%2==0){
		t=x_power_n_dc(x,k);
		return t*t;
	}
	else{
	    t=x_power_n_dc(x,k);
		return x*t*t;
	}
}

int bisearch(int a[],int l,int r,int t)      //函数bisearch(a,l,r,t)二分查找t在数组a的l到r区间
{
	int m=(l+r)/2;
	if(l>r) return 0;
	if(a[m]==t) return 1;
	else if(a[m]>t) return bisearch(a,l,m-1,t);
	else return bisearch(a,m+1,r,t);
}

int fibo(int n) //函数fibo 正序求解斐波那契的第n项
{
    int f1=1;
    int f2=1;
	int i=1;
	int s=0;
	assert(n>=1);
	if(n==1 || n==2)
		return 1;
	while(i<n-2){
	   s=f2;
	   f2=f1+f2;
	   f1=s;
	   i++;
	   
	}
	s=f1+f2;
	return s;

}
void print_arr(int a[][2])
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void compute(int a[][2],int n)
{
	int b[2][2]={{0,0},{0,0}};
	int i,j,k;
	static const int c[2][2]={{1,1},{1,0}};
	if(n==1)
	{
	//	print_arr(a);
		return;
	}
	if(n%2==0)
	{
		compute(a,n/2);
	//	print_arr(a);
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				for(k=0;k<2;k++)
				  b[i][j]+=a[i][k]*a[k][j];

		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				a[i][j]=b[i][j];
			
	}
	else{
	   compute(a,n/2);
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				for(k=0;k<2;k++)
					b[i][j]+=a[i][k]*a[k][j];
			
			
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				a[i][j]=0;
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				for(k=0;k<2;k++)
				  a[i][j]+=b[i][k]*c[k][j];
		//			print_arr(a);
	}
}
/*
|f(n+1)   f(n) |   | 1  1 |n
|              | = |      | 
|f(n)   f(n-1) |   | 1  0 |
*/

int fibo_dc(int n)  //分治法求解斐波那契第n项，
{
	int a[2][2]={{1,1},{1,0}};

	compute(a,n);

	return a[1][0];
}
int main()
{
	int x,n;
	cin>>x>>n;
	cout<<"x_power_n_rec("<<x<<","<<n<<"):  "<<x_power_n_rec(x,n)<<endl;
    cout<<"x_power_n_dc("<<x<<","<<n<<"):  "<<x_power_n_dc(x,n)<<endl;

	int a[5]={3,4,6,7,8};
	cout<<"bisearch(a,0,4,3): "<<bisearch(a,0,4,3)<<endl;

	cout<<"first 13 fibo: "<<endl;
	cout<<"  produced by fibo(n): "<<endl<<"  ";
    for(int i=1;i<13;i++)
	  cout<<fibo(i)<<" ";

	cout<<endl;
	cout<<"  produced by fibo_dc(n): "<<endl<<"  ";
    for(i=1;i<13;i++)
	  cout<<fibo_dc(i)<<" ";
	cout<<endl;
	return 0;
}