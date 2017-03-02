#include<iostream>
using namespace std;

class matrix
{
	private:
	int a[20][20],row,col;
	
	
	public:
	matrix(){};
	matrix(int a,int b)
	{
		row=a;col=b;
	}
	void read_matrix();
	matrix operator+(matrix m2);
	matrix operator-(matrix m2);
	int operator==(matrix m2);
	friend ostream& operator<<(ostream&,const matrix&);
	
};

void matrix::read_matrix()
{
	cout<<"enter the matrix elemnts:\n";
	for(int i=0;i<row;i++)
	for(int j=0;j<col;j++)
	cin>>a[i][j];
}


int matrix::operator==(matrix m2)
{
	if(row==m2.row && col==m2.col)
	return 1;
	else
	return 0;
}

matrix matrix::operator+(matrix m2)
{
	matrix m3(row,col);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			m3.a[i][j]=a[i][j]+m2.a[i][j];
	
	return m3;
}

matrix matrix::operator-(matrix m2)
{
	matrix m3(row,col);
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			m3.a[i][j] = a[i][j] - m2.a[i][j];
		}
	}
	
	
	
	return m3;
}

ostream& operator<<(ostream& out, const matrix &m)
{
	for(int i=0;i<m.row;i++)
	{
		for(int j=0;j<m.col;j++)
		out<<m.a[i][j]<<"\t";
		out<<endl;
	}
	return out;
}
int main(void)
{
	int m,n,p,q,x;
	
	cout<<"enter the order of the matrix 1:\n"<<endl;
	cin>>m>>n;
	matrix m1(m,n);
	
	
	cout<<"enter the order of matrix 2:\n";
	cin>>p>>q;
	
	matrix m2(p,q);
	
	if(m1==m2)
	{
		m1.read_matrix();
		m2.read_matrix();
		
		matrix m3=m1+m2;
		cout<<"sum is:"<<endl;
		cout<<m3<<endl;
		
		matrix m4;
		m4=m1-m2;
		cout<<"difference is:"<<endl;
		cout<<m4<<endl;
	}
	else
	cout<<"matrices cannot be added/subtracted"<<endl;
	
	return 0;
	
}
