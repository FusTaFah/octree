#include <iostream>

struct vec3{
  float x;
  float y;
  float z;
  vec3();
  vec3(float _x, float _y, float _z);
  vec3(const vec3 & other);
  vec3 operator=(const vec3 & other);
  ~vec3();
  vec3 operator+(const vec3 & other);
  vec3 operator-(const vec3 & other);
};
