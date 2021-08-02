
void atom::initialise(string N, class Point P) //initialising the atom with anme and coordinates
{
	name=N;
	Coords=P;
}

void atom::initialise(string N,float x,float y,float z)
{
	name=N;
	Coords.initialise(x,y,z);
}

void atom::clear()
{
	name="";
	Coords.clear();
}
void atom::operator=(class atom A) //initialising atom as equal to another atom
{
	name=A.get_name();
	Coords=A.get_coords();
}

string atom::get_name()  //returning the name and the coordinates of the atom
{
	return name;
}

class Point atom::get_coords()
{
	return Coords;
}

class Point atom::get_coords(string N) //retruning the coordiantes of the atom only if names match.
{
	class Point temp;
	temp.clear();
	if(name.compare(N)==0)
		return Coords;
	else
		return temp;
}
