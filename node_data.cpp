#include "node_data.h"

node_data::node_data(){
  width = 0.0f;
  height = 0.0f;
  depth = 0.0f;
}

node_data::node_data(const vec3 & _position, float _width, float _height, float _depth){
  position = _position;
  width = _width;
  height = _height;
  depth = _depth;
}

node_data::node_data(const vec3 & _position, float _width, float _height, float _depth, int i){
  int a = (i&0b100)?1:-1;
  int b = (i&0b10)?1:-1;
  int c = (i&0b1)?1:-1;
  vec3 displacement(_width * a / 2.0f, _height * b / 2.0f, _depth * c / 2.0f);
  vec3 new_pos(displacement);
  new_pos = new_pos + _position;
  node_data(new_pos, _width, _height, _depth);
}

node_data::node_data(const node_data & other){
  position = other.position;
  width = other.width;
  height = other.height;
  depth = other.depth;
}

node_data::node_data(const node_data & other, int i){
  node_data(other.position, other.width, other.height, other.depth, i);
}

node_data node_data::operator=(const node_data & other){
  node_data temp(other);
  return temp;
}

node_data::~node_data(){

}

void node_data::print(std::ostream & output){
  output << "x: " << position.x << " y: " << position.y << " z: " << position.z << std::endl;
}

bool node_data::inside(const vec3 & quarry){
  vec3 displaced_min(-width, -height, -depth);
  displaced_min = displaced_min + position;
  bool greater_than_x = quarry.x > displaced_min.x;
  bool greater_than_y = quarry.y > displaced_min.y;
  bool greater_than_z = quarry.z > displaced_min.z;
  vec3 displaced_max(width, height, depth);
  displaced_max = displaced_max + position;
  bool less_than_x = quarry.x < displaced_max.x;
  bool less_than_y = quarry.y < displaced_max.y;
  bool less_than_z = quarry.z < displaced_max.z;

  return greater_than_x && greater_than_y && greater_than_z && less_than_x && less_than_y && less_than_z;
}
