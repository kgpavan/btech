
void Vector::initialise(float x,float y,float z) //initialising three components of the vector
{
	x_comp=x;
	y_comp=y;
	z_comp=z;
}

void Vector::operator=(class Vector V) //setting vector equal to another vector
{
	x_comp=V.get_x();
	y_comp=V.get_y();
	z_comp=V.get_z();
}

void Vector::clear(void) //clearing the components of vector
{
	x_comp=y_comp=z_comp=0;
}

float Vector::get_x() //returning components of the vector
{
	return x_comp;
}

float Vector::get_y()
{
	return y_comp;
}

float Vector::get_z()
{
	return z_comp;
}

class Vector Vector::cross_product(class Vector V) // calculating the unit vector which 
{					   //is cross product of two vectors
	class Vector temp;
	float mod=0;
	float x=0,y=0,z=0;
	x=y_comp*V.get_z() - V.get_y()*z_comp;
	y=V.get_x()*z_comp - x_comp*V.get_z();
	z=x_comp*V.get_y() - V.get_x()*y_comp;
	mod=sqrt(x*x + y*y + z*z);
	x/=mod;
	y/=mod;
	z/=mod;
	temp.initialise(x,y,z);
	return temp;
}

float Vector::dot_product(class Point P) //dort product of vector with point p
{
	return x_comp*P.get_x() + y_comp*P.get_y() + z_comp*P.get_z();
}

float Vector::dot_product(class Vector V) //dot product of vector with another vector
{
	return x_comp*V.get_x() + y_comp*V.get_y() + z_comp*V.get_z();
}
