#ifndef Template
#define Template
#include<math.h>

template <class Type>
class vec3 {
private:
	Type x, y, z;
public:
	vec3(){}
	vec3(const vec3& vec) {
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}
	vec3(const Type& x, const Type& y, const Type& z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	vec3 normalize(const vec3& vec) {
		vec3 r;
		modul = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2);
		r.x = vec.x / modul;
		r.y = vec.y / modul;
		r.z = vec.z / modul;
		return r;
	}
	vec3 zero() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	bool is_zero() {
		return(x == 0 && y == 0 && z == 0);
	}
	vec3 distance_to(const vec3& vec) {
		vec3 r;
		r.x = x - vec.x;
		r.y = y - vec.y;
		r.z = z - vec.z;
		r = sqrt(pow(r.x,2)+ pow(r.y, 2)+pow(r.z, 2));
		return r;
	}
	vec3 operator +(const vec3& vec) {
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


#endif // !Template

