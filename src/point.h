#ifndef POINT_H
#define POINT_H
#include <cmath>
/**********************************************************/
class Point
{
	public:
	float x;
	float y;
	float z;
	Point();
	Point(float a, float b, float c);
	
	Point operator+(const Point& right);
	Point operator*(const float& scale);
	
	static Point scale(const float &scale, const Point &p);
	static Point add(const Point& p1, const Point& p2); 
	static float dot(const Point &left, const Point &right);
	static float distance(const Point &p1, const Point &p2);

	
	static Point cross(const Point &left, const Point &right);
	
	
	void normalize(void);

	
	static float angle(const Point &left, const Point &right);
	static float magnitude(const Point &vec);

	void set(float a, float b, float c);
};

Point operator+(float x, const Point &p);

//METHODS

Point::Point(){
	set(0,0,0);
}

Point::Point(float a, float b, float c){
	set(a,b,c);
}

void Point::set(float a, float b, float c){
	x = a; y = b; z = c;
}


float Point::dot(const Point &left, const Point &right){
	float dot;

	dot = (left.x * right.x) + (left.y * right.y) + (left.z * right.z);

	return dot;
}

float Point::distance(const Point &p1, const Point &p2){
	float dist = (
		(p2.x - p1.x) * (p2.x - p1.x)  +
		(p2.y - p1.y) * (p2.y - p1.y) +
		(p2.z - p1.z) * (p2.z - p1.z)
	);

	dist = sqrt(dist);
	return dist;

}


Point Point::add(const Point& p1, const Point &p2){
	return Point(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}

Point Point::operator+(const Point& right){
	Point point(x,y,z);

	return Point::add(point, right);
}


Point Point::scale(const float& f, const Point& p){
	return Point(p.x * f, p.y *f, p.z * f);
}

Point Point::operator*(const float& scale){
	Point point(x,y,z); 
	return Point::scale(scale,point);
}

Point operator*(const float &scale, const Point &p){
	return Point::scale(scale,p);
}



Point Point::cross(const Point &left, const Point &right){
	float x, y, z;

	x = (left.y * right.z) - (left.z * right.y);
	y = (left.z * right.x) - (left.x * right.z);
	z = (left.x * right.y) - (left.y * right.x);

	return Point(x,y,z);
}

void Point::normalize(void){
	Point p(x,y,z);
	Point origin;

	float length = Point::distance(origin,p);
	x = x / length;
	y = y / length;
	z = z / length;


}

float Point::angle(const Point &left, const Point &right){
	float dotp = dot(left,right);

	float leftmag = magnitude(left);
	float rightmag = magnitude(right);
	float cos = dotp / (leftmag * rightmag);
	float theta = acos(cos);

	if(theta < 0){
		theta = - theta;
	}

	theta = theta * 180.0/M_PI;
	return theta;
}

float Point::magnitude(const Point &vec){
	float length = vec.x * vec.x + (vec.y * vec.y) + (vec.z * vec.z);
	length = sqrt(length);

	return length;

}



#endif
