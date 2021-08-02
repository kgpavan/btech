/*Kambhampati Ganesh Pavan Kumar 200701036*/
/*MY shell works well if the spaces between the auguements is only on and while redirecting the there shouldn.t be any space between the command and file name and */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<crypt.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<malloc.h>
#include<string.h>
int main(int argc ,char *argv[])
{
	char **com;
	char a[1000],b[1000];
	char cmd[1000][1000];
		char *css=(char *)malloc(sizeof(char)*1000);
		char *css1=(char *)malloc(sizeof(char)*1000);
	//printf("%s\n",c);
	//printf("%s\n",c);
	int i,j,his=0,his1,k,m,n,o,p,l,q,z,su,y,ff,re1,re2,re3,re4,gr,le,cdi,cdm,app1,app2,app3,app4,cdex,cdt,cdtt;
	while(1)
	{
		gr=0;
		le=0;
		int cd=0,doll=0;
		int cdex=0,fla=0,flag=0;
		cdt=0;
		com=(char **)malloc(sizeof(char *)*1000);
		for(y=0;y<1000;y++)
		{
			com[y]=(char *)malloc(sizeof(char)*1000);
		}
		printf("]$");
		gets(a);
		char *dollar,*pola;
		dollar=(char *)malloc(sizeof(char)*1000);
		pola=(char *)malloc(sizeof(char)*1000);
		char *c;
		char *tild;
		c=(char *)malloc(sizeof(char)*1000);

		tild=(char *)malloc(sizeof(char)*1000);
		c=getenv("HOME");
		strcpy(tild,c);
		//printf("%s\n\n\n",c);
		if(strcmp(a,"exit")==0)
		{
			break;
		}
		strcpy(cmd[his++],a);
		if(strcmp("history",a)==0)
		{
			for(his1=0;his1<his;his1++)
			{
				printf("%s\n",cmd[his1]);
			}
		}
		k=0;q=0;p=0,app4=0;
		char fi[1000];
		char patc[1000];
		ff=0;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='\0')
				break;
			if(a[0]=='$')
			{
				doll=1;
				break;
			}
			if(strcmp("cd",a)==0&&a[3]!='-')
			{
				cdex=1;
				break;
			}
			if(a[0]=='c'&&a[1]=='d'&&a[3]=='~')
			{
				cdt=1;
				fla=1;
			//	printf("enterd the tilde\n");
				break;
			}
			if(a[i]=='c'&&a[i+1]=='d'&&fla!=1&&a[i+3]!='-')
			{
				cd=1;
				flag=1;
				break;
			}

			/*if(a[0]=='c'&&a[1]=='d'&&a[3]=='-'&&flag!=1)
			{
				printf("%s\n",css);
				strcpy(css1,css);
				getcwd(css,1000);
				chdir(css1);
			}*/
			if(a[i]=='>'&&a[i+1]=='>')
			{
				ff=i+2;
				app4=1;
				break;
			}

			if(a[i]=='>')
			{
				//printf("%c\n",a[i]);
				ff=i+1;
				gr=1;
				break;
			}
			if(a[i]=='<')
			{
				//printf("%c\n",a[i]);
				ff=i+1;
				le=1;
				break;
			}

			if(a[i]==' ')
			{
				q=q+1;
				p=0;
			}
			else
			{
				com[q][p]=a[i];
				p++;
			}
		}
		for(re1=ff,re3=0;re1<strlen(a);re1++,re3++)
		{
			fi[re3]=a[re1];
		}
		fi[re3]='\0';
		com[q+1]=NULL;

			/*if(a[0]=='c'&&a[1]=='d'&&a[3]=='-')
			{
				printf("gfjw\n");
				printf("%s\n",css);
				getcwd(css1,1000);
				chdir(css);
				strcpy(css,css1);
			}*/
			/*if(a[0]=='c'&&a[1]=='d'&&a[3]=='-'&&flag!=1)
			{
				printf("%s\n",css);
				strcpy(css1,css);
				getcwd(css,1000);
				chdir(css1);
			}*/
			/*if(a[0]=='c'&&a[1]=='d'&&a[3]=='-'&&flag!=1)
			{
				printf("%s\n",css);
				strcpy(css1,css);
				getcwd(css,1000);
				chdir(css1);
			}*/
			//if(cmd[0]=="cd'"&&a[1]=='d'&&a[3]=='-'&&flag!=1)
			//printf("%s\n",cmd[0]);
			//printf("%s\n",cmd[1]);
			if(strcmp(com[0],"cd")==0&&strcmp(com[1],"-")==0)
			{
				//printf("bjb\n");
				printf("%s\n",css);
				strcpy(css1,css);
				getcwd(css,1000);
				chdir(css1);
			}
			if(doll==1)
			{
				int suse,buse;
				//printf("pavan\n");
				for(suse=1,buse=0;suse<strlen(a);suse++,buse++)
				{
					dollar[buse]=a[suse];
				}
				dollar[buse]='\0';
				//printf("%s\n",dollar);
				pola=getenv(dollar);
				printf("%s\n",pola);
			}
		if(cdex==1)
		{
			//printf("kasikikk\n");
			getcwd(css,1000);
			//printf("%s\n",css);
			chdir(c);
			//exit(0);
		}
		if(cd==1)
		{
			//printf("........\n");
			for(cdi=3,cdm=0;cdi<strlen(a);cdi++,cdm++)
			{
				patc[cdm]=a[cdi];
			}
			patc[cdm]='\0';
			getcwd(css,1000);
		//	printf("%s\n",css);
			chdir(patc);
			//exit(0);
		}
		if(cdt==1)
		{
			//printf("~~~~\n");
			for(cdi=4,cdm=0;cdi<strlen(a);cdi++,cdm++)
			{
				patc[cdm]=a[cdi];
			}
			patc[cdm]='\0';
			//printf("%s %s\n",patc,c);
			strcat(tild,patc);
			getcwd(css,1000);

		//	printf("%s\n",css);
			chdir(tild);
		}
		if(fork()>0)
		{
			int z;
			wait(&z);
		}
		else
		{
			/*if(cdex==1)
				chdir(c);
			     if(cd==1)
			     {
				     for(cdi=3,cdm=0;cdi<strlen(a);cdi++,cdm++)
				     {
					     patc[cdm]=a[cdi];
				     }
				     patc[cdm]='\0';
				     chdir(patc);
			     }*/

			if(gr==1)
			{
				FILE *fil=fopen(fi,"w");
				fclose(fil);
				int fd=open(fi,O_WRONLY|O_CREAT);
				dup2(fd,STDOUT_FILENO);
			}
			if(le==1)
			{
				int fj=open(fi,O_RDONLY);
				dup2(fj,STDIN_FILENO);
			}
			if(app4==1)
			{
				int fsl=open(fi,O_APPEND|O_WRONLY);
				dup2(fsl,STDOUT_FILENO);
			}
			p=execvp(com[0],com);
			if(p==-1)
				exit(-1);
		}
	}
}
