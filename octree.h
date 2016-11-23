#include <iostream> // std::ostream
#include "vec3.h"

#define TREE_SIZE 8

struct octree{
  int data;
  float width;
  float height;
  float depth;
  vec3 position;
  octree * children[TREE_SIZE];
  octree(int layers, float _width, float _height, float _depth, vec3 & _position);
  octree(int _data, int layers, float _width, float _height, float _depth, vec3 & position);
  octree(octree & other);
  octree & operator=(octree & other);
  ~octree();
  void print(std::ostream & output);
  bool inside(const vec3 & quarry);
};
