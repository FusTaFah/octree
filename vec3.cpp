#include "vec3.h"

vec3::vec3(){
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
}

vec3::vec3(float _x, float _y, float _z){
  x = _x;
  y = _y;
  z = _z;
}

vec3::vec3(const vec3 & other){
  x = other.x;
  y = other.y;
  z = other.z;
}

vec3 vec3::operator=(const vec3 & other){
  x = other.x;
  y = other.y;
  z = other.z;
  return *this;
}

vec3::~vec3(){

}

vec3 vec3::operator+(const vec3 & other){
  float new_x = x + other.x;
  float new_y = y + other.y;
  float new_z = z + other.z;
  vec3 temp(x, y, z);
  return temp;
}

vec3 vec3::operator-(const vec3 & other){
  float new_x = x - other.x;
  float new_y = y - other.y;
  float new_z = z - other.z;
  vec3 temp(x, y, z);
  return temp;
}
