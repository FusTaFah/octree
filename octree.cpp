#include "octree.h"

octree::octree(){

}

octree::octree(int layers, const node_data & _data){
  data = _data;
  if(layers > 0){
    for(int i = 0b0; i < TREE_SIZE; i++){
      node_data temp(_data, i);
      children[i] = new octree(layers - 1, temp);
    }
  }else{
    for(int i = 0; i < TREE_SIZE; i++){
      children[i] = nullptr;
    }
  }
}

octree::octree(octree & other){
  data = other.data;
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
  data.print(output);
  if(children[0] != nullptr){
    for(int i = 0; i < TREE_SIZE; i++){
      children[i]->print(output);
      if(i == TREE_SIZE - 1){
        output << std::endl;
      }
    }
  }
}
