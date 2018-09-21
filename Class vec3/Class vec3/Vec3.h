#ifndef VEC3
#define VEC3
#include <math.h>

template <class Type>

class vec3 {

private:
	Type x, y, z;

public:
	vec3() {}
	vec3(const vec3& vector) :x(x), y(y), z(z) {}

	vec3(const Type& x, const Type& y, const Type& z) :x(x), y(y), z(z) {}

	vec3 normalize(const vec3& vector) const {
		modul = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
		return (vector.x / modul, vector.y / modul, vector.z / modul);
	}
	vec3 zero() {
		return(x = 0, y = 0, z = 0);
	}
	bool is_zero(const) {
		return(this->x == 0 && this->y == 0 && this->z == 0);
	}
	vec3 distance_to(const vec3& vector) const{
		return (sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2)));
	}
	vec3 operator +(const vec3& vector) const{
		return(this->x + vector.x, this->y + vector.y, this->z + vector.z);
	}
	vec3 operator -(const vec3& vector) const{
		return(this->x - vector.x, this->y - vector.y, this->z - vector.z);
	}
	vec3 operator +=(const vec3& vector) {
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
		return *this;
	}
	vec3 operator -=(const vec3& vector) {
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
		return *this;
	}
	vec3 operator =(const vec3& vector) {
		return(this->x = vector.x, this->y = vector.y, this->z = vector.z);
	}
	vec3 operator ==(const vec3& vector) {
		return (x == vector.x && y == vector.y && z == vector.z);
	}

};


#endif // !VEC3


