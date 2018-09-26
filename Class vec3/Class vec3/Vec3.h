#ifndef VEC3
#define VEC3
#include <math.h>

template <class TYPE>

class vec3 {

private:
	TYPE x, y, z;

public:
	vec3() {}
	vec3(const vec3& vector) :x(vector.x), y(vector.y), z(vector.z) {}
	vec3(const TYPE& x, const TYPE& y, const TYPE& z) :x(x), y(y), z(z) {}

	vec3 normalize() const {
		(TYPE)modul = sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
		return (this->x / modul, this->y / modul, this->z / modul);
	}
	vec3 zero() {
		this->x = (TYPE)0;
		this->y = (TYPE)0;
		this->z = (TYPE)0;
		return *this;
	}
	bool is_zero(const) {
		return(this->x == (TYPE)0 && this->y == (TYPE)0 && this->z == (TYPE)0);
	}
	float distance_to(const vec3& vector) const{
		return (sqrtf((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z)));
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
	float distance_to_squared(const vec3& vector) const {
		return ((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z))*((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
	}

};


#endif // !VEC3


