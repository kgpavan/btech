
void Residue::clear()
{
	base_type="";
	base="";
	residue_no="";
	chain_name=' ';
	Plane.clear();
	Atoms_rep.resize(0);
	Atoms_geo.resize(0);
	plane_d=0;
	centroid.clear();
	syn_anti=false;
}

bool Residue::initialise(string type,string Base,string residue,char chain, vector <class atom> A)
{	//initialising the residue with all details
	class atom temp;
	vector<class Point> Rep_coords;	
	float center_x=0,center_y=0,center_z=0;
	base_type=type;
	base=Base;
	string name;
	residue_no=residue;
	chain_name=chain;
	Rep_coords.resize(0);
	for(int i=0;i<A.size();i++)
	{
		temp.clear();
		temp=A[i];
		name=temp.get_name();  //dividing the atoms into two lists
		if(name.compare("C1*")==0 or name.compare("C1'")==0 or name.compare("P")==0 or name.compare("C4*")==0 or name.compare("C4'")==0 or name.compare("O4*")==0 or name.compare("O4'")==0 or name.compare("C2*")==0 or name.compare("C2'")==0 or name.compare("C3*")==0 or name.compare("C3'")==0 or name.compare("O1P")==0 or name.compare("O2P")==0 or name.compare("O5*")==0 or name.compare("O5'")==0 or name.compare("C4")==0) 
		{
			Atoms_geo.push_back(temp);
		}
		else if(name.compare("C2")==0 and base_type.compare("A")!=0)
			Atoms_geo.push_back(temp);
		else
			Atoms_rep.push_back(temp);
	}
	if(Atoms_rep.size()!=4)	 //if atoms not present, base not to be considered
	{
		cout << residue << " " << chain << endl;
		return false;
	}
	else
	{
		Calc_centroid_plane(); 
		Calc_syn_anti();
		Calc_center_of_mass(); 
		return true;
	}
}

void Residue::Calc_centroid_plane()  //calcuting equation of plane and coordinates of centroid
{
        class Vector vector1;
        class Vector vector2;

        vector1=Atoms_rep[1].get_coords() - Atoms_rep[0].get_coords();//defining two vectors with 3 points on the plane
        vector2=Atoms_rep[2].get_coords() - Atoms_rep[0].get_coords();

        Plane=vector1.cross_product(vector2);//taking cross product of two vectors

        //calculating the d value as normal dot product with point
        plane_d=-1*(Plane.dot_product(Atoms_rep[0].get_coords()));
	
	//Calculating centroid	
	float x=0,y=0,z=0;
	for(int i=0;i<4;i++)
	{
		x+=(Atoms_rep[i].get_coords()).get_x();
		y+=(Atoms_rep[i].get_coords()).get_y();
		z+=(Atoms_rep[i].get_coords()).get_z();
	}
	x/=4;
	y/=4;
	z/=4;
	centroid.initialise(x,y,z);
	centroid=centroid.projection(Plane,plane_d); //taking projection of centroid about the plane of the atom
}

void Residue::Calc_syn_anti() //calculating the nagle Kai
{
	class Point p1,p2,p3,p4,temp;
        double cos_angle;
	p1.clear();
	temp.clear();
	p2.clear();
	p3.clear();
	p4.clear();
	p1=get_atom_by_name("O4*",false); //taking the atoms used for the kai angle
	if(p1==temp)
		p1=get_atom_by_name("O4'",false);
	p2=get_atom_by_name("C1*",false);
	if(p2==temp)
		p2=get_atom_by_name("C1'",false);

	if(base_type.compare("A")==0 or base_type.compare("G")==0)
	{
		p3=get_atom_by_name("N9",true);
		p4=get_atom_by_name("C4",false);
	}
	else if(base_type.compare("U")==0 or base_type.compare("C")==0 or base_type.compare("T")==0)
	{
		p3=get_atom_by_name("N1",true);
		p4=get_atom_by_name("C2",false);
	}

	if(p1==temp or p2==temp or p3==temp or p4==temp)
		syn_anti=true; //returning angle as 0 if some atoms missing
        cos_angle=torsion_angle(p1,p2,p3,p4);
        if((cos_angle>=0 and cos_angle<90) or (cos_angle>=-90 and cos_angle<0))
                syn_anti=true; //true if syn
        else
                syn_anti=false;
}

void Residue::Calc_center_of_mass()
{
	class atom a;
	float x=0,y=0,z=0;
	float sum=0;
	a.clear();
	class Point p1,temp;
	p1.clear();
	temp.clear();
	 //calculating center of mass of phosphate
	p1=get_atom_by_name("P",false);
	if(!(p1==temp))
	{
		x+=(31*p1.get_x());
		y+=(31*p1.get_y());
		z+=(31*p1.get_z());
		sum+=31;
	}
	p1=get_atom_by_name("O1P",false);
	if(!(p1==temp))
	{
		x+=(16*p1.get_x());
		y+=(16*p1.get_y());
		z+=(16*p1.get_z());
		sum+=16;
	}
	p1=get_atom_by_name("O2P",false);
	if(!(p1==temp))
	{
		x+=(16*p1.get_x());
		y+=(16*p1.get_y());
		z+=(16*p1.get_z());
		sum+=16;
	}
	p1=get_atom_by_name("O5*",false);
	if(p1==temp)
		p1=get_atom_by_name("O5'",false);
	if(!(p1==temp))
	{
		x+=(16*p1.get_x());
		y+=(16*p1.get_y());
		z+=(16*p1.get_z());
		sum+=16;
	}
	x/=sum;
	y/=sum;
	z/=sum;
	a.initialise("Center_P",x,y,z);
	Atoms_geo.push_back(a);

	a.clear();
	x=y=z=sum=0;
	//calculating center of mass of sugar
	p1=get_atom_by_name("C1*",false);
	if(p1==temp)
		p1=get_atom_by_name("C1'",false);
	if(!(p1==temp))
	{
		x+=(12*p1.get_x());
		y+=(12*p1.get_y());
		z+=(12*p1.get_z());
		sum+=12;
	}
	p1=get_atom_by_name("C2*",false);
	if(p1==temp)
		p1=get_atom_by_name("C2'",false);
	if(!(p1==temp))
	{
		x+=(12*p1.get_x());
		y+=(12*p1.get_y());
		z+=(12*p1.get_z());
		sum+=12;
	}
	p1=get_atom_by_name("C3*",false);
	if(p1==temp)
		p1=get_atom_by_name("C3'",false);
	if(!(p1==temp))
	{
		x+=(12*p1.get_x());
		y+=(12*p1.get_y());
		z+=(12*p1.get_z());
		sum+=12;
	}
	p1=get_atom_by_name("C4*",false);
	if(p1==temp)
		p1=get_atom_by_name("C4'",false);
	if(!(p1==temp))
	{
		x+=(12*p1.get_x());
		y+=(12*p1.get_y());
		z+=(12*p1.get_z());
		sum+=12;
	}
	p1=get_atom_by_name("O4*",false);
	if(p1==temp)
		p1=get_atom_by_name("O4'",false);
	if(!(p1==temp))
	{
		x+=(16*p1.get_x());
		y+=(16*p1.get_y());
		z+=(16*p1.get_z());
		sum+=16;
	}
	x/=sum;
	y/=sum;
	z/=sum;
	a.initialise("Center_S",x,y,z);
	Atoms_geo.push_back(a);
}
	 
string Residue::get_base_type() //returning the values of various attributes of the residue
{
	return base_type;
}

string Residue::get_base()
{
	return base;
}

string Residue::get_residueno()
{
	return residue_no;
}

char Residue::get_chain()
{
	return chain_name;
}

class Vector Residue::get_plane()
{
	return Plane;
}

float Residue::get_plane_d()
{
	return plane_d;
}	
class Point Residue::get_centroid()
{
	return centroid;
}

bool Residue::get_syn_anti()
{
	return syn_anti;
}

class Point Residue::get_atom_by_name(string atom_name,bool geo_rep)//finding the coords of a specific atom
{
	class Point temp,temp1;
	temp.clear();
	temp1.clear();
	//geo_rep will be true if rep has to be searched and false if geo has to be searched
	if(geo_rep)
	{
		for(int i=0;i<Atoms_rep.size();i++)
		{
			temp1=Atoms_rep[i].get_coords(atom_name);
			if(!(temp1==temp))
				return temp1;
		}
		return temp;
	}		
	else
	{
		for(int i=0;i<Atoms_geo.size();i++)
		{
			temp1=Atoms_geo[i].get_coords(atom_name);
			if(!(temp1==temp))
				return temp1;
		}
		return temp;
	}
}

bool Residue::inside_cylinder(class Residue R,float h,float r)
{
	class Point center_r=R.get_centroid(); //Getting coordinates of centroid and PLane and plane_d of given base
	class Vector plane_r=R.get_plane();
	float plane_d_r=R.get_plane_d();
	bool flag=false;	

	class Point temp,temp1;
	float dist_from_plane=0,dist_from_normal=0;
	float d;

	for(int i=0;i<4;i++)
	{
		temp.clear();
		temp1.clear();
		temp=Atoms_rep[i].get_coords(); //getting coordinates of the atom
		dist_from_plane=fabs(plane_r.dot_product(temp)+plane_d_r);
		if(dist_from_plane<=h/2) //if distance from plane is less than height
		{
			d=-1*(plane_r.dot_product(temp));
			temp1=center_r.projection(plane_r,d);
			dist_from_normal=temp.distance(temp1); //calculating distance from normal
			if(dist_from_normal<=r) //if less than radius
				flag=true;
			else
				flag=false;
		}
		else
			flag=false;
		if(flag) //if one atom falls inside, then do not chk other atoms
			break;
	}
	return flag; //return the value of flag
}

void Residue::find_edge_of_base(class Point P_center,char & edge)
{
	class Vector unit,temp;
        class Point center_1,center_2;
	class Point atoms[4];
        unit.clear();
        temp.clear();
        unit.initialise(1/sqrt(3),1/sqrt(3),1/sqrt(3));
        float Matrix2[4][4]={0},Matrix[4][4]={0};

        center_2=P_center.projection(Plane,plane_d); //projection of base two centroid
	for(int i=0;i<4;i++) //making a copy of cooords of atoms because atoms coords need to be changed
		atoms[i]=Atoms_rep[i].get_coords();
        atoms[3]=atoms[3].projection(Plane,plane_d); //projection of fourth atom on the plane
	
        Matrix2[0][3]=-1*centroid.get_x();
        Matrix2[1][3]=-1*centroid.get_y(); //translation
        Matrix2[2][3]=-1*centroid.get_z();
        Matrix2[3][3]=Matrix2[0][0]=Matrix2[1][1]=Matrix2[2][2]=1;

        temp=Plane.cross_product(unit);

        Matrix[0][0]=unit.get_x();
        Matrix[0][1]=unit.get_y(); //rotation
        Matrix[0][2]=unit.get_z();
        Matrix[1][0]=temp.get_x();
        Matrix[1][1]=temp.get_y();
        Matrix[1][2]=temp.get_z();
        Matrix[2][0]=Plane.get_x();
        Matrix[2][1]=Plane.get_y();
        Matrix[2][2]=Plane.get_z();
        Matrix[3][3]=1;

        multiply(Matrix,Matrix2); //calculating transformation matrix for aligning this plane along x-y plane

        center_1=centroid.multiply(Matrix);
        center_2=center_2.multiply(Matrix);//taking all to two dimensions

        for(int i=0;i<4;i++)
                atoms[i]=atoms[i].multiply(Matrix);

        for(int i=0;i<4;i++)
        {
                //if line segments intersect then that is the edge
                if(intersect(center_1,center_2,atoms[i],atoms[(i+1)%4]))
                {
                        find_edge_of_line(i,(i+1)%4,edge);
                        break;
                }
        }
}

void Residue::find_edge_of_line(int index1,int index2,char &edge)
{
        int temp;
        if(index1>index2)
        {
                temp=index1;
                index1=index2;
                index2=temp;
        }
	string name1,name2;
	name1=Atoms_rep[index1].get_name();
	name2=Atoms_rep[index2].get_name();
         //deciding the edge typebases on th base type and label of the atoms
        if(base_type.compare("A")==0)
        {
                if(name1.compare("N9")==0  and name2.compare("N7")==0)
                        edge='C';
                else if(name1.compare("N7")==0 and name2.compare("N6")==0)
                        edge='H';
                else if(name1.compare("N6")==0 and name2.compare("C2")==0)
                        edge='W';
                else if(name1.compare("N9")==0 and name2.compare("C2")==0)
                        edge='S';
        }
        else if(base_type.compare("G")==0)
        {
                if(name1.compare("N9")==0 and name2.compare("N7")==0)
                        edge='C';
                else if(name1.compare("N7")==0 and name2.compare("O6")==0)
                        edge='H';
                else if(name1.compare("O6")==0 and name2.compare("N2")==0)
                        edge='W';
                else if(name1.compare("N9")==0 and name2.compare("N2")==0)
                        edge='S';
        }
        else if(base_type.compare("C")==0)
        {
                if(name1.compare("N1")==0 and name2.compare("O2")==0)
                        edge='S';
                else if(name1.compare("O2")==0 and name2.compare("N4")==0)
                        edge='W';
                else if(name1.compare("N4")==0 and name2.compare("C6")==0)
                        edge='H';
                else if(name1.compare("N1")==0 and name2.compare("C6")==0)
                        edge='C';
        }
        else if(base_type.compare("U")==0)
        {
                if(name1.compare("N1")==0 and name2.compare("O2")==0)
                        edge='S';
                else if(name1.compare("O2")==0 and name2.compare("O4")==0)
                        edge='W';
                else if(name1.compare("O4")==0 and name2.compare("C6")==0)
                        edge='H';
                else if(name1.compare("N1")==0 and name2.compare("C6")==0)
                        edge='C';
        }
	else if(base_type.compare("T")==0)
        {
                if(name1.compare("N1")==0 and name2.compare("O2")==0)
                        edge='S';
                else if(name1.compare("O2")==0 and name2.compare("O4")==0)
                        edge='W';
                else if(name1.compare("O4")==0 and name2.compare("C6")==0)
                        edge='H';
                else if(name1.compare("N1")==0 and name2.compare("C6")==0)
                        edge='C';
        }
}

void Residue::print()
{
	for(int j=0;j<Atoms_rep.size();j++)
	{
		cout << "ATOM\t" << Atoms_rep[j].get_name() << "\t" << (Atoms_rep[j].get_coords()).get_x() << "\t" << (Atoms_rep[j].get_coords()).get_y() << "\t" << (Atoms_rep[j].get_coords()).get_z() << endl;
	}
	for(int j=0;j<Atoms_geo.size();j++)
	{
		cout << "ATOM\t" << Atoms_geo[j].get_name() << "\t" << (Atoms_geo[j].get_coords()).get_x() << "\t" << (Atoms_geo[j].get_coords()).get_y() << "\t" << (Atoms_geo[j].get_coords()).get_z() << endl;
	}
}
