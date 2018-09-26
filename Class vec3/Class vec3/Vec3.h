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

	vec3 normalize() const {
		(Type)modul = sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
		return (this->x / modul, this->y / modul, this->z / modul);
	}
	vec3 zero() {
		this->x = (Type)0;
		this->y = (Type)0;
		this->z = (Type)0;
		return *this;
	}
	bool is_zero(const) {
		return(this->x == (Type)0 && this->y == (Type)0 && this->z == (Type)0);
	}
	vec3 distance_to(const vec3& vector) const{
		return (Type) (sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z)));
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
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
		return *this;
	}
	vec3 operator ==(const vec3& vector) {
		return (this->x == vector.x && this->y == vector.y && this->z == vector.z);
	}
	vec3 distance_to_square(const vec3& vector) const {
		return (Type)((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z))*((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
	}

};


#endif // !VEC3


