#include "octree.h"

octree::octree(int layers, float _width, float _height, float _depth, vec3 & _position){
  data = 0;
  width = _width;
  height = _height;
  depth = _depth;
  position = _position;
  if(layers > 0){
    for(int i = 0b0; i < TREE_SIZE; i++){
      int a = (i&0b100)?1:-1;
      int b = (i&0b10)?1:-1;
      int c = (i&0b1)?1:-1;
      vec3 displacement(width/2.0f * a, height/2.0f * b, depth/2.0f * c);
      vec3 temp(displacement);
      temp = temp + position;
      children[i] = new octree(layers - 1, width/2, height/2, depth/2, temp);
    }
  }else{
    for(int i = 0; i < TREE_SIZE; i++){
      children[i] = nullptr;
    }
  }
}

octree::octree(int _data, int layers, float _width, float _height, float _depth, vec3 & _position){
  data = _data;
  position = _position;
  if(layers > 0){
    for(int i = 0; i < TREE_SIZE; i++){
      int a = (i&0b100)?1:-1;
      int b = (i&0b10)?1:-1;
      int c = (i&0b1)?1:-1;
      vec3 displacement(width/2.0f * a, height/2.0f * b, depth/2.0f * c);
      vec3 temp(displacement);
      temp = temp + position;
      children[i] = new octree(0, layers - 1, width/2, height/2, depth/2, temp);
    }
  }else{
    for(int i = 0; i < TREE_SIZE; i++){
      children[i] = nullptr;
    }
  }
}

octree::octree(octree & other){
  data = other.data;
  position = other.position;
  if(children[0] != nullptr && other.children[0] != nullptr){
    for(int i = 0; i < TREE_SIZE; i++){
      children[i] = new octree(*(other.children[i]));
    }
  }else{
    for(int i = 0; i < TREE_SIZE; i++){
      children[i] = nullptr;
    }
  }
}

octree & octree::operator=(octree & other){
  data = other.data;
  position = other.position;
  if(children[0] != nullptr && other.children[0] != nullptr){
    for(int i = 0; i < TREE_SIZE; i++){
      children[i] = new octree(*(other.children[i]));
    }
  }else{
    for(int i = 0; i < TREE_SIZE; i++){
      children[i] = nullptr;
    }
  }
  return *this;
}

octree::~octree(){
  for(int i = 0; i < TREE_SIZE; i++){
    delete children[i];
  }
}

void octree::print(std::ostream & output){
  //output << data;
  output << "x: " << position.x << " y: " << position.y << " z: " << position.z << std::endl;
  if(children[0] != nullptr){
    for(int i = 0; i < TREE_SIZE; i++){
      children[i]->print(output);
      if(i == TREE_SIZE - 1){
        output << std::endl;
      }
    }
  }
}

bool octree::inside(const vec3 & quarry){
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
