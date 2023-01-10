#ifndef CS352_JSONLANG_H
#define CS352_JSONLANG_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <map>

#define PROGRAM_BEGIN ;int main(){
#define PROGRAM_END ;return 0;}

#define JSON(name) ;auto name

#define STRING(text) Object<std::string>(text)
#define NUMBER(x)  Object<float>(x)

#define OBJECT std::vector <std::string>

#define KEY(name)  "#name" , false ? ""

#define TRUE Object<bool>(true);
#define FALSE Object<bool>(false);

class O{};

template<typename T>
class Object : public O{
public:
    T value;
    Object(){}

    Object(T val){ value = val;}

};




#endif //CS352_JSONLANG_H
