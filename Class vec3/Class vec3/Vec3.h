#ifndef VEC3
#define VEC3
#include <math.h>

template <class Type>

class vec3 {

private:
	Type x, y, z;

public:
	vec3() {}
	vec3(const vec3& vec) :x(x), y(y), z(z) {}

	vec3(const Type& x, const Type& y, const Type& z) :x(x), y(y), z(z) {}

	vec3 normalize(const vec3& vec) const {
		modul = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
		return (vec.x / modul, vec.y / modul, vec.z / modul);
	}
	vec3 zero() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	bool is_zero(const) {
		return(this->x == 0 && this->y == 0 && this->z == 0);
	}
	vec3 distance_to(const vec3& vec) {
		return (sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2)));
	}
	vec3 operator +(const vec3& vec) {
		vec3 r;
		r.x = this->x + vec.x;
		r.y = this->y + vec.y;
		r.z = this->z + vec.z;
	}
	vec3 operator -(const vec3& vec) {
		vec3 r;
		r.x = this->x - vec.x;
		r.y = this->y - vec.y;
		r.z = this->z - vec.z;
	}
	vec3 operator +=(const vec3& vec) {
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;
	}
	vec3 operator -=(const vec3& vec) {
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;
	}
	vec3 operator ==(const vec3& vec) {
		return (x == vec.x && y == vec.y && z == vec.z);
	}
};


#endif // !VEC3


