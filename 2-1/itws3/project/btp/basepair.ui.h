/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

#include<iostream>
#include<fstream>
#include<qfiledialog.h>
#include<qcanvas.h>
#include<qpixmap.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<math.h>
#include<qstringlist.h>
#include<qcombobox.h>
#include<qpainter.h>
#include<qsqldatabase.h>
#include</usr/include/mysql/mysql.h>
#include"declaration.h"
#include"model.cpp"
#include"point.cpp"
#include"vector.cpp"
#include"atom.cpp"
#include"Residue.cpp"
#include<qregion.h>
using namespace std;

QStringList pdb_files;
int x_range1=0,x_range2=360,y_range1=0,y_range2=360;
int mag=1,dimen=60;
int prev_x_1=0,prev_x_2=360,prev_y_1=0,prev_y_2=360;
int newx=0,newy=0;
	
void MainForm::ResetValues()
{
	InputHeight->setText("");
	InputRadius->setText("");
}


void MainForm::SubmitValues()
{
	static int count=0;
	float height=0,radius=0;
        class model temp;
	MYSQL *connection,mysql;
	char filename[50],command[100];
	int value=0;
	ifstream fp;
	height=atof(InputHeight->text());
	radius=atof(InputRadius->text());
	count++;
	cout << height << " " << radius << endl;
        temp.get_input_from_file("model_1.out");
        temp.Get_base_pairs("output_model_1.txt",height,radius);

	sprintf(command,"perl BPF_pre.pl output_model_1.txt %d.txt",count);
	sprintf(filename,"B%d.txt",count);
	value=system(command);
	sprintf(command,"rm -f output_model_1.txt");
	value=system(command);
	mysql_init(&mysql);
	char query[200];
	char residue1[20],residue2[20],base1[20],base2[20],orient[20];
	char edge1,edge2,chain1[3],chain2[3];
	char junk[20];
	float omega_eta,omega_theta,omega_dist,omega1,omega2;
	char Omega_eta[20],Omega_theta[20],Omega1[20],Omega2[20];
	connection=mysql_real_connect(&mysql,"localhost",0,0,"RRBPF",0,0,0);
	if(connection==NULL)
		cout << "hi" << endl;
	fp.open(filename);
	int state;
	char name[30];
	strcpy(name,pdb_files[count-1]);
	
	while(!fp.eof())
	{
		fp >> base1 >> base2 >> edge1 >> edge2 >> orient >> chain1 >>  residue1 >> junk >> residue2 >>  chain2 >> Omega_eta >> Omega_theta >> omega_dist >> Omega1 >> Omega2;
		if(strcmp(Omega_eta,"nan")==0)
			omega_eta=0.0;
		else
			omega_eta=atof(Omega_eta);
		if(strcmp(Omega_theta,"nan")==0)
			omega_theta=0.0;
		else
			omega_theta=atof(Omega_theta);
		if(strcmp(Omega1,"nan")==0)
			omega1=0.0;
		else
			omega1=atof(Omega1);
		if(strcmp(Omega2,"nan")==0)
			omega2=0.0;
		else
			omega2=atof(Omega2);
		sprintf(query,"insert into base_pairs values ('%s','%s','%s','%s','%s','%s','%s','%c','%c','%s',%f,%f,%f,%f,%f);",name,chain1,residue1,base1,base2,residue2,chain2,edge1,edge2,orient,omega_eta,omega_theta,omega_dist,omega1,omega2);
		state=mysql_query(connection,query);
	}
	mysql_close(connection);
}


void MainForm::BrowseFile()
{
	const char *v;
	int value=0;
	char command[400];
	char *pdb;
	char filename[200];
        QFileDialog *fd = new QFileDialog ( this , "file dialog" , TRUE);
        fd->setMode( QFileDialog::ExistingFile);
        fd->setFilter( "PDB files (*.pdb)" );
        fd->setViewMode( QFileDialog::List );

        QString s;
        if(fd->exec() == QDialog::Accepted )
                s = fd->selectedFile();   // accepting the file name entered by the user
        if(!s.isNull())
        {
                v=s.ascii();   // converting the file name entered from Qstring into the char string
                strcpy(filename,v);
                cout << filename << endl;
        }
	sprintf(command,"perl extract_coord_new.pl %s",filename);
	value=system(command);
	int i=0,k=0;
	for(i=strlen(filename)-1;filename[i]!='/';i--);
	i++;
	pdb=&filename[i];
	pdb_files.append(pdb);
	ListBox->clear();
	ListBox->insertStringList(pdb_files);
}


void MainForm::Plot_clicked()
{
	MYSQL * connection,mysql;
	int state;
	mysql_init(&mysql);
	connection=mysql_real_connect(&mysql,"localhost",0,0,"RRBPF",0,0,0);
	char query[300]="";
	char temp_query[300]="";
	QString pdb,base1,base2,edge1,edge2,orient;
	base1=Base1->currentText();
	base2=Base2->currentText();
	edge1=Edge1->currentText();
	edge2=Edge2->currentText();
	orient=Orientation->currentText();
	pdb=ListBox->currentText();
	char PDB[20],BASE1[20],BASE2[20],EDGE1[20],EDGE2[20],ORIENT[20];
	strcpy(PDB,pdb);
	strcpy(ORIENT,orient);
	sprintf(query,"DROP view temp_result;");
	state=mysql_query(connection,query);
	strcpy(query,"");
	sprintf(query,"CREATE or replace VIEW temp_result as Select * from base_pairs WHERE PDB_name='%s'",PDB);
	if(base1.compare("--Select--")!=0)
	{
		strcpy(BASE1,base1);
		strcpy(BASE2,base2);
		sprintf(temp_query,"%s AND ((Base1='%s' AND Base2='%s') OR (Base1='%s' AND Base2='%s'))",query,BASE1,BASE2,BASE2,BASE1);
		strcpy(query,temp_query);
	}
	if(edge1.compare("--Select--")!=0)
	{
		strcpy(EDGE1,edge1);
		strcpy(EDGE2,edge2);
		sprintf(temp_query,"%s AND ((Edge1='%s' AND Edge2='%s') OR (Edge1='%s' AND Edge2='%s'))",query,EDGE1,EDGE2,EDGE2,EDGE1);
		strcpy(query,temp_query);
	}
	if(orient.compare("---Select---")!=0)
	{
		strcpy(ORIENT,orient);
		sprintf(temp_query,"%s AND Orient='%s'",query,ORIENT);
		strcpy(query,temp_query);
	}
	sprintf(temp_query,"%s;",query);
	strcpy(query,temp_query);
	cout << query << endl;
	state=mysql_query(connection,query);
	mysql_close(connection);			
	cout << state << endl;
	Plot_graph();
}


void MainForm::Reset2_clicked()
{
	Xaxis->setCurrentItem(0);
	Yaxis->setCurrentItem(0);
	Base1->setCurrentItem(0);
	Base2->setCurrentItem(0);
	Edge1->setCurrentItem(0);
	Edge2->setCurrentItem(0);
	Orientation->setCurrentItem(0);
}

void MainForm::init()
{
	QRegion reg(500,50,400,400);
	repaint(reg);
	QPainter p(this);
	p.setPen(Qt::blue);
	p.drawRect(580,60,360,360);
       	p.drawLine(640,60,640,420); 
	p.drawLine(700,60,700,420); 
	p.drawLine(760,60,760,420); 
	p.drawLine(820,60,820,420); 
	p.drawLine(880,60,880,420); 
	p.drawLine(580,120,940,120); 
	p.drawLine(580,180,940,180); 
	p.drawLine(580,240,940,240); 
	p.drawLine(580,300,940,300); 
	p.drawLine(580,360,940,360); 
}


void MainForm::mousePressEvent( QMouseEvent *e )
{
	int x=double(e->x());
	int y=double(e->y());
	int cordx=0,cordy=0;
	int x_coord=0,y_coord=0;
	char info[200];

	if(x>=580 and x<=940 and y>=60 and y<=420)
	{
		cordx=((x-580))/mag+x_range1;
		cordy=((420-y))/mag+y_range1;
		if(Getinfo->isChecked())
		{
			bool flag=false;
			float x_all,y_all;
			MYSQL_RES *result;
			MYSQL_ROW row;
			MYSQL * connection,mysql;
			int state;
			mysql_init(&mysql);
			connection=mysql_real_connect(&mysql,"localhost",0,0,"RRBPF",0,0,0);
			char query[200];
			if(cordx>180)
				x_coord=cordx-360;
			else 
				x_coord=cordx;
			if(cordy>180)
				y_coord=cordy-360;
			else 
				y_coord=cordy;
			sprintf(query,"select * from temp_result;");
			state=mysql_query(connection,query);
			QString xaxis;
			xaxis=Xaxis->currentText();
			if(xaxis.compare("Omega eta")==0)
				flag=true;
			else
				flag=false;
			result=mysql_store_result(connection);
			while((row=mysql_fetch_row(result))!=NULL)
			{
				if(flag)
				{
					x_all=atof(row[10]);	
					y_all=atof(row[11]);
				}
				else
				{
					x_all=atof(row[13]);
					y_all=atof(row[14]);
				}
				if(fabs(x_coord-x_all)<=2 and fabs(y_coord-y_all)<=2)
				{
					sprintf(info,"%s %s %s %s %s %s %s %s %s %s\n",row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8],row[9]);
					if(flag)
					{
						sprintf(info,"%s X axis(Omega eta): %s\n Y axis(Omega theta): %s",info,row[10],row[11]);
					}
					else 
					{
						sprintf(info,"%s X axis(Omega 1): %s\n Y axis(Omega 2): %s",info,row[13],row[14]);
					}
					InfoBox->setText(info);
					break;	
				}
			}
			mysql_free_result(result);
			mysql_close(connection);			
			Plot_graph();
		}
		else if(Zoomin->isChecked())
		{
			mag*=2;/*zoom in two times*/
			if(mag>4)
			{
				mag/=2;/*no zoom in allowed after four times*/
				Plot_graph();
				return;
			}
			prev_x_1=x_range1;
			prev_y_1=y_range1;
			prev_x_2=x_range2;
			prev_y_2=y_range2;/*setting the new range of the graph and storing the previous value for zoom out*/
			for(int i=x_range1;i<=x_range2;i=i+dimen)
			{
				if(cordx-i<dimen)
				{
					newx=i;
					break;/*zooming the three by three square grids near the point clicked on the graph*/
				}
			}
			for(int i=y_range1;i<=y_range2;i=i+dimen)
			{
				if(cordy-i<dimen)
				{
					newy=i;
					break;
				}
			}
			if(newx-dimen<x_range1)
			{
				x_range1=newx;
			}
			else
			{
				if(newx+dimen<x_range2)
					x_range1=newx-dimen;
				else
					x_range1=newx-2*dimen;
			}
			if(newy-dimen<y_range1)
			{
				y_range1=newy;
			}
			else
			{
				if(newy+dimen<y_range2)
					y_range1=newy-dimen;
				else
					y_range1=newy-2*dimen;
			}
			dimen=60/(mag);/*calculating gap between two lines on the graph*/
			x_range2=x_range1+6*dimen;
			y_range2=y_range1+6*dimen;
			Plot_graph();
		}
		else if(Zoomout->isChecked())
		{
			mag/=2;
			if(mag<=1)/*if the graph returns to normal dimen*/
			{
				mag=1;
				dimen=60/mag;
				x_range1=0;
				x_range2=360;
				y_range1=0;
				y_range2=360;
				Plot_graph();
				return;
			}
			dimen=60/mag;
			x_range1=prev_x_1;
			x_range2=prev_x_2;/*setting the ranges to the previous values stored while zooming in*/
			y_range1=prev_y_1;
			y_range2=prev_y_2;
			Plot_graph();
		}	
	}
}

void MainForm::Plot_graph()
{
	QString xaxis,yaxis;
	xaxis=Xaxis->currentText();
	yaxis=Yaxis->currentText();
	char value_x[20],value_y[20];
	if(xaxis.compare("Omega eta")==0)
	{
		strcpy(value_x,"Omega_eta");
		strcpy(value_y,"Omega_theta");
	}
	else if(xaxis.compare("Omega 1")==0)
	{
		strcpy(value_x,"Omega1");
		strcpy(value_y,"Omega2");
	}

	MYSQL_RES *result;
	MYSQL_ROW row;
	MYSQL * connection,mysql;
	int state;
	mysql_init(&mysql);
	connection=mysql_real_connect(&mysql,"localhost",0,0,"RRBPF",0,0,0);
	char query[200],label[10];
	
	sprintf(query,"Select %s,%s from temp_result;",value_x,value_y);
	state=mysql_query(connection,query);
	result=mysql_store_result(connection);
	QRegion reg(550,50,420,420);
	repaint(reg);
	QPainter p(this);
	p.setPen(Qt::blue);
	p.drawRect(580,60,360,360);
       
	p.drawLine(640,60,640,420); 
	p.drawLine(700,60,700,420); 
	p.drawLine(760,60,760,420); 
	p.drawLine(820,60,820,420); 
	p.drawLine(880,60,880,420); 

	p.drawLine(580,120,940,120); 
	p.drawLine(580,180,940,180); 
	p.drawLine(580,240,940,240); 
	p.drawLine(580,300,940,300); 
	p.drawLine(580,360,940,360);

	for(int i=0;i<7;i++)
	{
		sprintf(label,"%d",x_range1+i*dimen);
		p.drawText(580+i*60,440,label);
	}
	for(int i=0;i<7;i++)
	{
		sprintf(label,"%d",y_range1+i*dimen);
		p.drawText(550,420-i*60,label);
	}
	
	int x,y,l,m;
	while((row=mysql_fetch_row(result))!=NULL)
	{
		x=atoi(row[0]);
		y=atoi(row[1]);
		if(x!=0 and y!=0)
		{
			if(x<0)
				x+=360;
			if(y<0)
				y+=360;
			if(x>=x_range1 and x<=x_range2 and y>=y_range1 and y<=y_range2)
			{
				l=(x-x_range1)*mag;
				/*calculating the points where to plot*/
				m=(y-y_range1)*mag;
				if(580+l<=940 && 580+l>=580 && 420-m>=60 && 420-m<=420 )
					p.drawEllipse(580+l,420-m,2*mag, 2*mag);
			}
		}
	}	
	mysql_free_result(result);
	mysql_close(connection);			
}
