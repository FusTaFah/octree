#include "vec3.h"
#include <iostream>

struct node_data{
  float width;
  float height;
  float depth;
  vec3 position;

  node_data();
  node_data(const vec3 & _position, float _width, float _height, float _depth);
  node_data(const vec3 & _position, float _width, float _height, float _depth, int i);
  node_data(const node_data & other);
  node_data(const node_data & other, int i);
  node_data operator=(const node_data & other);
  ~node_data();
  void print(std::ostream & output);
  bool inside(const vec3 & quarry);
};
