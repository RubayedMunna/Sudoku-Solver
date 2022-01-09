#include<iostream>
using namespace std;
#define N 9
#define Unassigned 0   
void printGrid(int ara[N][N])
{
	
	for(int i=0;i<N;i++)
	{
		if(i==0||i==3||i==6)
		{
			cout<<"-------------------------------"<<endl;
		}
		for(int j=0;j<N;j++)
		{
			if(j==0||j==3||j==6)
			{
				cout<<"|";
			}
			cout<<" "<<ara[i][j]<<" ";
			if(j==8)
			{
				cout<<"|";
			}
		}
		cout<<endl;
		if(i==8)
		{
			cout<<"-------------------------------"<<endl;
		}
		
	}
	
}                                                
bool UsedInBox(int ara[N][N],int boxStartRow,int boxStartCol,int num)
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			if(ara[row+boxStartRow][col+boxStartCol]==num)
			{
				return true;
			}
		}
	}
	return false;
}                                                                    
bool UsedInCol(int ara[N][N],int col,int num)                          
{
	for(int row=0;row<N;row++)
	{
		if(ara[row][col]==num)
		{
			return true;
		}
	}
	return false;
}                                                                     
bool UsedInRow(int ara[N][N],int row,int num)                          
{
	for(int col=0;col<N;col++)
	{
		if(ara[row][col]==num)
		{
			return true;
		}
	}
	return false;
}                                                                     
bool isSafe(int ara[N][N],int row,int col,int num)
{
	return !UsedInRow(ara,row,num)&&!UsedInCol(ara,col,num)&&!UsedInBox(ara,row-row%3,col-col%3,num)&&ara[row][col]==Unassigned;
	
}                                                                     
bool FindUnassignedLocation(int ara[N][N],int& row,int& col)           
{
	for(row=0;row<N;row++)
	{
		for(col=0;col<N;col++)
		{
			if(ara[row][col]==Unassigned)
			{
				return true;
			}
		}
	}
	return false;
}                                                                     
bool SolveSudoku(int ara[N][N])
{
	int row,col;
	if(!FindUnassignedLocation(ara,row,col))
	{
		return true;
	}
	for(int num=1;num<=9;num++)
	{
		if(isSafe(ara,row,col,num))
		{
			ara[row][col]=num;
			if(SolveSudoku(ara))
			{
				return true;
			}
			ara[row][col]=Unassigned;
		}
	}
	return false;
}
int main()
{
	freopen("in.txt","r",stdin);
	int ara[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>ara[i][j];
		}
	}
	cout<<"The Given Sudoku Is: "<<endl;
	printGrid(ara);
	cout<<endl<<endl;
	if(SolveSudoku(ara)==true)
	{
		cout<<"The Solution for The Given Sudoku: "<<endl<<endl;
		printGrid(ara);
		cout<<"Sudoku Solved!"<<endl;
	}
	else
	{
		cout<<"No Solution Exist!!"<<endl;
	}
	return 0;
}
