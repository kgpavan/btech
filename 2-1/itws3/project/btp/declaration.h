#include<iostream>
#include<string>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<fstream>
#include<map>
#define PI 3.14157
using namespace std;
double torsion_angle(class Point p1, class Point p2, class Point p3, class Point p4);
void multiply(float Matrix1[][4], float Matrix2[][4]); //multiplying two matrices
bool intersect(class Point p1,class Point p2,class Point p3,class Point p4);

class Point
{
    private:
	float x_coord,y_coord,z_coord;
    public:
	Point(){}
	void initialise(float,float,float);
	void operator=(class Point);
	bool operator==(class Point);
	void clear(void);
	float get_x();
	float get_y();
	float get_z();
	class Vector operator-(class Point); 
	class Point projection(class Vector,float);
	float distance(class Point);
	class Point multiply(float Matrix[][4]);
	
};

class Vector
{
   private:
	float x_comp,y_comp,z_comp;
   public:
	Vector(){};
	void initialise(float,float,float);
	void operator=(class Vector);	
	void clear(void);
	class Vector cross_product(class Vector);
	float dot_product(class Point);
	float dot_product(class Vector);
	float get_x();
	float get_y();
	float get_z();
};	
	
class atom
{
   private:
	string name;
	class Point Coords;
   public:
	atom(){};
	void initialise(string,class Point);
	void initialise(string,float,float,float);
	void clear();
	void operator=(class atom);
	string get_name();
	class Point get_coords();
	class Point get_coords(string); 
};	

class Residue
{
   private:
	string base_type;
	string base;
	string residue_no;
	char chain_name;
	class Vector Plane;
	float plane_d;
	class Point centroid;
	vector <class atom> Atoms_rep; //atoms used to represent a base
	vector <class atom> Atoms_geo; //atoms used for calculation
	bool syn_anti; //will be true if nucleotide is syn
   public:
	Residue(){};
	/*{
		base_type="";
		base="";
		residue_no="";
		chain_name=' ';
		plane_d=0;
		syn_anti=true;
	}*/	
	void clear();
	class Point get_atom_by_name(string,bool); //true if search on Atoms_rep and false if search on Atoms_geo	
	void Calc_centroid_plane();
	void Calc_syn_anti();
	bool initialise(string,string,string,char,vector <class atom>);
 	string get_base_type();
	string get_base();
	string get_residueno();
	class Vector get_plane();
	float get_plane_d();
	char get_chain();
	class Point get_centroid();
	bool get_syn_anti();
	bool inside_cylinder(class Residue,float,float);	
	void find_edge_of_base(class Point,char&);
	void find_edge_of_line(int,int,char&);
	void print();
	void Calc_center_of_mass();
};		

class model
{
    private:	
	int model_no;
	long int no_of_bases;
	vector<struct Residue> Bases;
   public:
	model()
	{
		model_no=0;
		no_of_bases=0;
	}
	void get_input_from_file(char *);
	void Get_base_pairs(char *,float,float);
	bool duplicates(map <int,vector<int> > &dup,int,int);
	void calculate_omega_angles(int,int,double &,double &,double &,double &,double &);
	void details_of_base_pair(char *,int,int,double,double,double,double,double);
	bool find_orientation(int,int);
	void print();
};

double torsion_angle(class Point p1, class Point p2, class Point p3, class Point p4)
{
        double cos_angle=0,sin_angle=0,tan_angle=0;
        class Vector v1,v2,v3,v4,cross,cross1;
        v1=p1-p2; //finding out the vectors a and b
        v2=p3-p2;
        v3=v1.cross_product(v2); //cross product of a and b
        v1.clear();
        v2.clear();
        v1=p2-p3; //finding vectors -b and c
        v2=p4-p3;
        v4=v1.cross_product(v2);//cross product of -b and c
        cos_angle=acos(v3.dot_product(v4));
        cos_angle/=PI; //magnitude of the angle
        cos_angle*=180;
        cross.clear();
        cross=v4.cross_product(v3);
        sin_angle=cross.dot_product(v1); //cross product of cross products
        if(sin_angle>=0) //deciding sign of the angle
                return cos_angle;
        else
                return -1*cos_angle;
}
void multiply(float Matrix1[][4], float Matrix2[][4]) //multiplying two matrices
{
        float Matrix[4][4]={0};
        for(int i=0;i<4;i++)
        {
                for(int j=0;j<4;j++)
                {
                        for(int k=0;k<4;k++)
                        {
                                Matrix[i][j]+=Matrix1[i][k]*Matrix2[k][j];
                        }
                }
        }
        for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                        Matrix1[i][j]=Matrix[i][j];

}

bool intersect(class Point p1,class Point p2,class Point p3,class Point p4)
{
        float t=0,k=0,a=0,b=0,c=0,d=0,e=0,f=0,D=0,Dx=0,Dy=0;
        a=p2.get_x() - p1.get_x();
        b=p3.get_x() - p4.get_x();
        e=p3.get_x() - p1.get_x();  //intersection of two line segments using Cramer's rule
        c=p2.get_y() - p1.get_y();
        d=p3.get_y() - p4.get_y();
        f=p3.get_y() - p1.get_y();


        t=(e*d - b*f)/(a*d - b*c);
        k=(a*f - e*c)/(a*d - b*c);
        if(t>=0 and t<=1 and k>=0 and k<=1)
                return true;
        else
                return false;
}

