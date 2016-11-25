#include <iostream> // std::ostream
#include "node_data.h"

#define TREE_SIZE 8

struct octree{
  node_data data;
  octree * children[TREE_SIZE];
  octree();
  octree(int layers, const node_data & _data);
  octree(octree & other);
  octree & operator=(octree & other);
  ~octree();
  void print(std::ostream & other);
};
