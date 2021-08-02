
void Point::initialise(float x,float y,float z) //initialising the point with three coordinates
{
	x_coord=x;
	y_coord=y;
	z_coord=z;
}

void Point::operator=(class Point P) //initialising the Point with another point
{
	x_coord=P.get_x();
	y_coord=P.get_y();
	z_coord=P.get_z();
}

bool Point::operator==(class Point P) //comparing two points
{
	if(x_coord==P.get_x() and y_coord==P.get_y() and  z_coord==P.get_z())
		return true;
	else
		return false;
}

void Point::clear(void)  //clearing the coordinates
{
	x_coord=y_coord=z_coord=0;
}

float Point::get_x() //returning the three coordinates of the point
{
	return x_coord;
}

float Point::get_y()
{
	return y_coord;
}

float Point::get_z()
{
	return z_coord;
}

class Vector Point::operator-(class Point P) // returning a unit vector which
{                                            // is defined by two points
	class Vector temp;
	float x=0,y=0,z=0;
	float mod=0;
	x=x_coord - P.get_x();
	y=y_coord - P.get_y();
	z=z_coord - P.get_z();
	mod=sqrt(x*x+y*y+z*z);
	x/=mod;
	y/=mod;
	z/=mod;
	temp.initialise(x,y,z);
	return temp;
}

class Point Point::projection(class Vector V,float D) //taking the projection of point P
{	                                              // on the plane defined by V.components  and  and  D	
	float m;
	class Point temp;
	float x=0,y=0,z=0;
	m=-1*(V.dot_product(*this) + D);
	x=V.get_x()*m + x_coord;
	y=V.get_y()*m + y_coord;
	z=V.get_z()*m + z_coord;
	temp.initialise(x,y,z);
	return temp;
}

float Point::distance(class Point P) //distance between two points
{
	float x=0,y=0,z=0;
	x=x_coord-P.get_x();
	y=y_coord-P.get_y();
	z=z_coord-P.get_z();
	return sqrt(x*x + y*y + z*z);
}

class Point Point::multiply(float Matrix[4][4]) //transforming the given point by the transformation matrix
{
	class Point temp;
	float point[4];
	float result[4]={0};
	point[0]=x_coord;
	point[1]=y_coord;
	point[2]=z_coord;
	point[3]=1;
	for(int i=0;i<4;i++)
	{
		for(int k=0;k<4;k++)
			result[i]+=Matrix[i][k]*point[k];
	}
	temp.initialise(result[0]/result[3],result[1]/result[3],result[2]/result[3]);
	return temp;
}	
