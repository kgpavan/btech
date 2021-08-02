
void model::get_input_from_file(char * filename) 
{
	bool to_include=false;
	class Residue temp;
	float x=0,y=0,z=0;
	vector <class atom> Atoms;
	class atom temp1;
	string base,base_type,residue,atom_name;
	string junk;
	char chain;

	//initialising the attributes of the model
	model_no=0;
	no_of_bases=0;
	Bases.resize(0);	

	ifstream file;
	file.open(filename);
	file >> junk; //Resding MODEL
	file >> model_no; //Reading molde number
	file >> junk; //Reading --------
	while(1)
	{
		temp.clear();
		file >> junk; //Reading BaseNum
		if(junk[0]=='=') //End of file
			break;
		file >> residue; //Reading residue number
		file >> junk >> chain; //Reading Chain: and chain name
		file >> junk >> base_type; //Reading BaseType and base type
		file >> junk >> base; //Reading Base and base
		file >> junk; //Reading ATOM or ----- for finishing
		Atoms.resize(0);
		while(junk[0]!='-')
		{
			temp1.clear();
			file >> atom_name >> x >> y >> z; //Reading the atomname and coordinates
			temp1.initialise(atom_name,x,y,z);
			Atoms.push_back(temp1);
			file >> junk; //Reading ATOM or -------
		}
		to_include=temp.initialise(base_type,base,residue,chain,Atoms);
		if(to_include)
			Bases.push_back(temp);
	}
	no_of_bases=Bases.size();
	//print();
	file.close();
}

bool model::duplicates(map <int,vector<int> > &dup,int i,int j)//detecting duplicates of base pairs
{
	int base1,base2;
	vector <int> ::iterator beg,end,temp;
	map<int , vector<int> > ::iterator begin;
	if(i<j) //putting the smaller residue number base as the key
	{
		base1=i;
		base2=j;
	}
	else
	{
		base1=j;
		base2=i;
	}
	begin=dup.find(base1); //finding whether smaller base already involved in some base pairs or not
	if(begin!=dup.end())
	{
		temp=find(dup[base1].begin(),dup[base1].end(),base2);
		if(temp==dup[base1].end())
		{
			dup[base1].push_back(base2); //adding this base pair if not detected
			return false;
		}
		else
			return true; 
	}
	else 
	{
		dup[base1].push_back(base2);
		return false;
	}
}

void model::calculate_omega_angles(int i,int j,double &eta,double &theta,double &omega_dist,double &omega1,double &omega2)
{
	class Point p1,p2,p3,p4,p5,p6,temp;
	temp.clear();
	p2.clear();
	p3.clear();
	p2=Bases[i].get_atom_by_name("C4*",false); //for center of mass Center_P and Center_S
	if(p2==temp)
		p2=Bases[i].get_atom_by_name("C4'",false);
	p3=Bases[j].get_atom_by_name("C4*",false); //calculating distance between C4* atoms of the two base
	if(p3==temp)
		p3=Bases[j].get_atom_by_name("C4'",false);
	omega_dist=p2.distance(p3);

	
	p1.clear();  //This code calculates torsion angle without takibg center of mass concept
	p4.clear();
	p5.clear();
	p6.clear();
	p1=Bases[i].get_atom_by_name("P",false); //getting coordinates of P atoms
	p4=Bases[j].get_atom_by_name("P",false);

	if(i!=(no_of_bases-1) and Bases[i].get_chain()==Bases[i+1].get_chain())
		p5=Bases[i+1].get_atom_by_name("P",false);
	if(j!=(no_of_bases-1) and Bases[j].get_chain()==Bases[j+1].get_chain())
		p6=Bases[j+1].get_atom_by_name("P",false);

	if(p1==temp or p2==temp or p3==temp or p4==temp) //if atoms missing
		eta=0.0;
	else
		eta=torsion_angle(p1,p2,p3,p4);

	if(p5==temp or p2==temp or p3==temp or p6==temp)
		theta=0.0;
	else
		theta=torsion_angle(p5,p2,p3,p6);

	if(p1==temp or p2==temp or p3==temp or p6==temp)
		omega1=0.0;
	else
		omega1=torsion_angle(p1,p2,p3,p6);

	if(p5==temp or p2==temp or p3==temp or p4==temp)
		omega2=0.0;
	else
		omega2=torsion_angle(p5,p2,p3,p4);
}

void model::Get_base_pairs (char * file,float height,float radius)
{
	map <int ,vector <int> > dup_record;
	int baseno1,baseno2;
	double omega_eta,omega_theta,omega_distance,omega1,omega2;
	bool potential_base_pair=false;
	for(int j=0;j<no_of_bases;j++) //for each base checking with other bse for proximity 
	{
		omega_eta=0;
		omega_theta=0;
		omega_distance=0;
		omega1=0;
		omega2=0;
		for(int k=0;k<no_of_bases;k++)
		{
			if(k==j) //neglecting same atoms
				continue;
			potential_base_pair=Bases[k].inside_cylinder(Bases[j],height,radius); //will tell whether any atoms of k lie inside cylinder of j
			if(potential_base_pair) //if they are pairing, then find details
			{
				if(duplicates(dup_record,j,k))
					continue;	
				calculate_omega_angles(j,k,omega_eta,omega_theta,omega_distance,omega1,omega2);	
				details_of_base_pair(file,j,k,omega_eta,omega_theta,omega_distance,omega1,omega2);
			}
		}
	}
}	

void model::details_of_base_pair(char * file,int i,int j,double omega_eta,double omega_theta,double omega_distance,double omega1,double omega2)
{
	bool cis_trans;
	char edge1='d',edge2='d';
	ofstream outputfile;
	bool flag=false;
	//calculating the distnace between the fouratoms of each base pair	
	
	Bases[i].find_edge_of_base(Bases[j].get_centroid(),edge1);//finding the inetracting edge for each base
	Bases[j].find_edge_of_base(Bases[i].get_centroid(),edge2);
	if(edge1=='d' or edge2=='d' or edge1=='C' or edge2=='C')
		return;

	cis_trans=find_orientation(i,j);

	outputfile.open(file,ios::app);	
	outputfile << "Base1: ResidueNo: " << Bases[i].get_residueno() << " Chain: " << Bases[i].get_chain() << " Type: " << Bases[i].get_base_type() << " Egde: " << edge1 << " About Kai bond: ";
	if(Bases[i].get_syn_anti())
		outputfile << "Syn" << endl;
	else
		outputfile << "Anti" << endl;

	outputfile << "Base2: ResidueNo: " << Bases[j].get_residueno() << " Chain: " << Bases[j].get_chain() << " Type: " << Bases[j].get_base_type() << " Egde: " << edge2 << " About Kai bond; ";
	if(Bases[j].get_syn_anti())
		outputfile << "Syn" << endl;
	else
		outputfile << "Anti" << endl;
	outputfile << "Orientation: ";
	if(cis_trans)
		outputfile << "Cis\n";
	else
		outputfile << "Trans\n";
	outputfile << "Omega eta: " << omega_eta << " Omega theta: " << omega_theta << " Omega Distance: " << omega_distance << endl;
	outputfile << "Omega 1: " << omega1 << " Omega 2: " << omega2 << endl;
	outputfile << endl;
	outputfile.close();
}

bool model::find_orientation(int i,int j)
{
	class Point p1,p2,p3,p4,temp;
	float costheta=0;
	p1.clear();
	p2.clear();
	p3.clear();
	p4.clear();
	temp.clear();

	p1=Bases[i].get_atom_by_name("C1*",false); //taking coordintes of C1* of both bases
	if(p1==temp)
		p1=Bases[i].get_atom_by_name("C1'",false);
	p4=Bases[j].get_atom_by_name("C1*",false);
	if(p4==temp)
		p4=Bases[j].get_atom_by_name("C1'",false);

	//Depending upon value of base_type taking N9 or N1
	if((Bases[i].get_base_type()).compare("A")==0 or (Bases[i].get_base_type()).compare("G")==0)
		p2=Bases[i].get_atom_by_name("N9",true);
	else
		p2=Bases[i].get_atom_by_name("N1",true);

	if((Bases[j].get_base_type()).compare("A")==0 or (Bases[j].get_base_type()).compare("G")==0)
		p3=Bases[j].get_atom_by_name("N9",true);
	else
		p3=Bases[j].get_atom_by_name("N1",true);

	if(p1==temp or p2==temp or p3==temp or p4==temp) //if atoms are missing
		costheta=0.0;
	else
		costheta=torsion_angle(p1,p2,p3,p4);
		
	if((costheta>=0 and costheta<90) or (costheta>-90 and costheta<0))
		return true; 
	else
		 return false;
}	

void model::print()
{
	cout << "MODEL " << model_no << endl << "-----------" << endl;
	for(int i=0;i<no_of_bases;i++)
	{
		cout << "BaseNum:  " << Bases[i].get_residueno() << endl;
		cout << "Chain: " << Bases[i].get_chain() << endl;
		cout << "BaseType: " << Bases[i].get_base_type() << endl;
		cout << "Base:   " << Bases[i].get_base() << endl;
		Bases[i].print();	
		cout << "-----------" << endl;
	}
	cout << "==============================================================" << endl;
}		
