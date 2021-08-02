#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int x;
	int y;
	int bomb;
	int time;
	char ch;
};
typedef struct node bomber;
main()
{
	int no_of_inputs,i,h;
	scanf("%d",&no_of_inputs);
	for(h=0;h<no_of_inputs;h++)
	{
		int r,col,bb,t,b,i,j,k;
		scanf("%d %d %d",&r,&col,&bb);
		char c[r][col];
		queue<node> q;
		for(j=0;j<r;j++)
			for(k=0;k<col;k++)
				scanf(" %c",&c[j][k]);
		int flag=0;
		for(j=0;j<r;j++)
		{
			for(int k=0;k<col;k++)
			{
				if(c[j][k]=='B')
				{
					bomber temp;
					temp.x=j;
					temp.y=k;
					temp.bomb=bb;
					temp.time=0;
					temp.ch=c[j][k];
					q.push(temp);
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		int min=999999;
		int max=0;
		int arr[r][col];
		for(i=0;i<r;i++)
			for(j=0;j<col;j++)
				arr[i][j]=5555;
		while(!q.empty())
		{
			bomber temp1;
			temp1=q.front();
			q.pop();
			b=temp1.bomb;
			t=temp1.time;
			i=temp1.x;
			j=temp1.y;
			//	printf("%c ",temp1.ch);
			//	break;
			if(temp1.ch=='E')
			{
				if(temp1.time<min)
					min=temp1.time;
			}
			if(j-1>=0)
			{
				bomber temp2;
				if(c[i][j-1]=='.')
				{
					temp2.x=i;
					temp2.y=j-1;
					temp2.bomb=b;
					temp2.time=t+1;
					temp2.ch=c[i][j-1];
					if(arr[i][j-1]>temp2.time)
					{
						arr[i][j-1]=temp2.time;
						q.push(temp2);
					}
				}
				else if(c[i][j-1]=='#')
				{
					temp2.x=i;
					temp2.y=j-1;
					temp2.bomb=b-1;
					temp2.time=t+3;
					temp2.ch=c[i][j-1];
					if(arr[i][j-1]>temp2.time)
					{
						arr[i][j-1]=temp2.time;
						q.push(temp2);
					}
				}
				else if(c[i][j-1]=='B')
				{
					temp2.x=i;
					temp2.y=j-1;
					temp2.bomb=b;
					temp2.time=t+1;
					temp2.ch=c[i][j-1];
					if(arr[i][j-1]>temp2.time)
					{
						arr[i][j-1]=temp2.time;
						q.push(temp2);
					}
				}
				else if(c[i][j-1]=='E')
				{
					temp2.x=i;
					temp2.y=j-1;
					temp2.bomb=b;
					temp2.time=t+1;
					temp2.ch=c[i][j-1];
					if(arr[i][j-1]>temp2.time)
					{
						arr[i][j-1]=temp2.time;
						q.push(temp2);
					}
				}


			}
			if(i-1>=0)
			{
				bomber temp3;
				if(c[i-1][j]=='.')
				{
					temp3.x=i-1;
					temp3.y=j;
					temp3.bomb=b;
					temp3.time=t+1;
					temp3.ch=c[i-1][j];
					if(arr[i-1][j]>temp3.time)
					{
						arr[i-1][j]=temp3.time;
						q.push(temp3);
					}
				}
				else if(c[i-1][j]=='#')
				{
					temp3.x=i-1;
					temp3.y=j;
					temp3.bomb=b-1;
					temp3.time=t+3;
					temp3.ch=c[i-1][j];
					if(arr[i-1][j]>temp3.time)
					{
						arr[i-1][j]=temp3.time;
						q.push(temp3);
					}
				}
				else if(c[i-1][j]=='E')
				{
					temp3.x=i-1;
					temp3.y=j;
					temp3.bomb=b;
					temp3.time=t+1;
					temp3.ch=c[i-1][j];
					if(arr[i-1][j]>temp3.time)
					{
						arr[i-1][j]=temp3.time;
						q.push(temp3);
					}
				}
				else if(c[i-1][j]=='B')
				{
					temp3.x=i-1;
					temp3.y=j;
					temp3.bomb=b;
					temp3.time=t+1;
					temp3.ch=c[i-1][j];
					if(arr[i-1][j]>temp3.time)
					{
						arr[i-1][j]=temp3.time;
						q.push(temp3);
					}
				}
			}
			if(j+1<col)
			{
				bomber temp4;
				if(c[i][j+1]=='.')
				{
					temp4.x=i;
					temp4.y=j+1;
					temp4.bomb=b;
					temp4.time=t+1;
					temp4.ch=c[i][j+1];
					if(arr[i][j+1]>temp4.time)
					{
						arr[i][j+1]=temp4.time;
						q.push(temp4);
					}
				}
				else if(c[i][j+1]=='#')
				{
					temp4.x=i;
					temp4.y=j+1;
					temp4.bomb=b-1;
					temp4.time=t+3;
					temp4.ch=c[i][j+1];
					if(arr[i][j+1]>temp4.time)
					{
						arr[i][j+1]=temp4.time;
						q.push(temp4);
					}
				}
				else if(c[i][j+1]=='B')
				{
					temp4.x=i;
					temp4.y=j+1;
					temp4.bomb=b;
					temp4.time=t+1;
					temp4.ch=c[i][j+1];
					if(arr[i][j+1]>temp4.time)
					{
						arr[i][j+1]=temp4.time;
						q.push(temp4);
					}
				}
				else if(c[i][j+1]=='E')
				{
					temp4.x=i;
					temp4.y=j+1;
					temp4.bomb=b;
					temp4.time=t+1;
					temp4.ch=c[i][j+1];
					if(arr[i][j+1]>temp4.time)
					{
						arr[i][j+1]=temp4.time;
						q.push(temp4);
					}
				}
			}
			if(i+1<r)
			{
				bomber temp5;
				if(c[i+1][j]=='.')
				{
					temp5.x=i+1;
					temp5.y=j;
					temp5.bomb=b;
					temp5.time=t+1;
					temp5.ch=c[i+1][j];
					if(arr[i+1][j]>temp5.time)
					{
						arr[i+1][j]=temp5.time;
						q.push(temp5);
					}
				}
				else if(c[i+1][j]=='#')
				{
					temp5.x=i+1;
					temp5.y=j;
					temp5.bomb=b-1;
					temp5.time=t+3;
					temp5.ch=c[i+1][j];
					if(arr[i+1][j]>temp5.time)
					{
						arr[i+1][j]=temp5.time;
						q.push(temp5);
					}
				}
				else if(c[i+1][j]=='E')
				{
					temp5.x=i+1;
					temp5.y=j;
					temp5.bomb=b;
					temp5.time=t+1;
					temp5.ch=c[i+1][j];
					if(arr[i+1][j]>temp5.time)
					{
						arr[i+1][j]=temp5.time;
						q.push(temp5);
					}
				}
				else if(c[i+1][j]=='B')
				{
					temp5.x=i+1;
					temp5.y=j;
					temp5.bomb=b;
					temp5.time=t+1;
					temp5.ch=c[i+1][j];
					if(arr[i+1][j]>temp5.time)
					{
						arr[i+1][j]=temp5.time;
						q.push(temp5);
					}
				}
			}

			//			max=(temp1.time + 3);
		}
		printf("%d\n",min);
	}

}







