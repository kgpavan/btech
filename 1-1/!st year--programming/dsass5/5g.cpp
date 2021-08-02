#include<iostream>
#include<queue>
using namespace std;
struct bomberman
{
	int x;
	int y;
	int bomb;
	int time;
	char ch;
};
typedef struct bomberman bomber;
main()
{
	int no_of_inputs,i,h;
	cin>>no_of_inputs;
	for(h=0;h<no_of_inputs;h++)
	{
		int r,col,bb,t,b,i,j,k;
		//scanf("%d %d %d",&r,&col,&bb);
		cin>>r>>col>>bb;
		char c[r][col];
		int arr[r][col];
		queue<bomberman> q;
		bomber temp;
		for(j=0;j<r;j++)
			for(k=0;k<col;k++)
			{	
				cin>>c[j][k];
				arr[j][k]=5555;
				if(c[j][k]=='B')
				{
					temp.x=j;
					temp.y=k;
				}
			}
		arr[temp.x][temp.y]=0;
		//scanf(" %c",&c[j][k]);
		temp.bomb=bb;
		temp.time=0;
		temp.ch=c[temp.x][temp.y];
	//	printf("%c",temp.ch);
		q.push(temp);
		int flag=0;
		int min=9999;
		int max=0;
		while(!q.empty())
		{
		//	printf("WTF-----\n");
			bomber temp1;
			temp1=q.front();
			q.pop();
			b=temp1.bomb;
			t=temp1.time;
			i=temp1.x;
			j=temp1.y;
			//printf("curr char uis %c\n",temp1.ch);
			//cout<<i<<" "<<j<<endl;
			if(temp1.ch=='E')
			{
				if(t<min)
				{	min=t;
				}
				      
			}
			else
			{
				if(j-1>=0)
				{
					flag=0;
					bomber temp2;
					if(c[i][j-1]!='#')
					{
						flag=1;
						temp2.x=i;
						temp2.y=j-1;
						temp2.bomb=b;
						temp2.time=t+1;
						temp2.ch=c[i][j-1];
					}
					else if(b>0)
					{
						flag=1;
						temp2.x=i;
						temp2.y=j-1;
						temp2.bomb=b-1;
						temp2.time=t+3;
						temp2.ch=c[i][j-1];
					}
					/*else if(c[i][j-1]=='B')
					{
						temp2.x=i;
						temp2.y=j-1;
						temp2.bomb=b;
						temp2.time=t+1;
						temp2.ch=c[i][j-1];
					}
					else if(c[i][j-1]=='E')
					{
					r
						temp2.x=i;
						temp2.y=j-1;
						temp2.bomb=b;
						temp2.time=t+1;
						temp2.ch=c[i][j-1];
					}*/

					if((arr[i][j-1]>=temp2.time)&&(flag==1))
					{
						arr[i][j-1]=temp2.time;
						q.push(temp2);
					}


				}
				if(i-1>=0)
				{
					flag=0;
					bomber temp3;
					if(c[i-1][j]!='#')
					{
						flag=1;
						temp3.x=i-1;
						temp3.y=j;
						temp3.bomb=b;
						temp3.time=t+1;
						temp3.ch=c[i-1][j];
					}
					else if(b>0)
					{
						flag=1;
						temp3.x=i-1;
						temp3.y=j;
						temp3.bomb=b-1;
						temp3.time=t+3;
						temp3.ch=c[i-1][j];
					}
					/*else if(c[i-1][j]=='E')
					{
						temp3.x=i-1;
						temp3.y=j;
						temp3.bomb=b;
						temp3.time=t+1;
						temp3.ch=c[i-1][j];
					}
					else if(c[i-1][j]=='B')
					{
						temp3.x=i-1;
						temp3.y=j;
						temp3.bomb=b;
						temp3.time=t+1;
						temp3.ch=c[i-1][j];
					}*/
					if((arr[i-1][j]>=temp3.time)&&(flag==1))
					{
						arr[i-1][j]=temp3.time;
						q.push(temp3);
					}
				}
				if(j+1<col)
				{
					flag=0;
					bomber temp4;
					if(c[i][j+1]!='#')
					{
						flag=1;
						temp4.x=i;
						temp4.y=j+1;
						temp4.bomb=b;
						temp4.time=t+1;
						temp4.ch=c[i][j+1];
					}
					else if( b>0)
					{
						flag=1;
						temp4.x=i;
						temp4.y=j+1;
						temp4.bomb=b-1;
						temp4.time=t+3;
						temp4.ch=c[i][j+1];
					}
					/*else if(c[i][j+1]=='B')
					{
						temp4.x=i;
						temp4.y=j+1;
						temp4.bomb=b;
						temp4.time=t+1;
						temp4.ch=c[i][j+1];
					}
					else if(c[i][j+1]=='E')
					{
						temp4.x=i;
						temp4.y=j+1;
						temp4.bomb=b;
						temp4.time=t+1;
						temp4.ch=c[i][j+1];
					}*/
					if((arr[i][j+1]>=temp4.time)&&(flag==1))
					{
						arr[i][j+1]=temp4.time;
						q.push(temp4);
					}
				}
				if(i+1<r)
				{
					flag=0;
					bomber temp5;
					if(c[i+1][j]!='#')
					{
						flag=1;
						temp5.x=i+1;
						temp5.y=j;
						temp5.bomb=b;
						temp5.time=t+1;
						temp5.ch=c[i+1][j];
					}
					else if(b>0)
					{
						flag=1;
						temp5.x=i+1;
						temp5.y=j;
						temp5.bomb=b-1;
						temp5.time=t+3;
						temp5.ch=c[i+1][j];
					}
					/*else if(c[i+1][j]=='E')
					{
						temp5.x=i+1;
						temp5.y=j;
						temp5.bomb=b;
						temp5.time=t+1;
						temp5.ch=c[i+1][j];
					}
					else if(c[i+1][j]=='B')
					{
						temp5.x=i+1;
						temp5.y=j;
						temp5.bomb=b;
						temp5.time=t+1;
						temp5.ch=c[i+1][j];
					}*/
					if((arr[i+1][j]>=temp5.time)&&(flag==1))
					{
						arr[i+1][j]=temp5.time;
						q.push(temp5);
					}
				}

			}
		}
		if(min==9999)
			printf("-1\n");
		else
			printf("%d\n",min);
	}

}
