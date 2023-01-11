#ifndef CS352_JSONLANG_H
#define CS352_JSONLANG_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <map>

#define PROGRAM_BEGIN ;int main(){
#define PROGRAM_END ;return 0;}

// Var definition
#define JSON(name) ;auto name

// Object definitions
#define STRING(text) Object(STRING,text)
#define NUMBER(x)    Object(getNumberType(x),std::to_string(x))
#define OBJECT std::vector <Object>
#define KEY(name) Object(OBJ,name) , (false) ? STRING("NULL")
#define ARRAY  std::array <Object>
#define TRUE Object(BOOL,"true");
#define FALSE Object(BOOL,"false");

// Editing definitions
#define SET
#define ASSIGN =
#define ERASE

//Output
#define PRINT print(T obj)

// Function definitions
#define SIZE_OF(name) CheckSize(name).result
#define IS_EMPTY(name) CheckEmpty(name).result
#define HAS_KEY(obj,key) hasKey(obj,key)
#define TYPE_OF(name)

typedef enum type { INT , FLOAT , STRING , BOOL , OBJ , ARR , NUL }Type;

class Object {
public:
    std::string value;
    Type type;
    Object(){}
    Object(Type t,std::string val):value(val),type(t){}
    ~Object(){};
};

Type getNumberType(float x){
    if (abs(x- int(x) > 0) )
        return FLOAT;
    else
        return INT;
}

//Class for instance checking

class CheckSize {
public:
    bool result;
    CheckSize(Object obj){
        result = false;
    }
    CheckSize(std::vector<Object> vec){
        if(vec.size()>0)
            result = true;
        else
            result = false;
    }
};

class CheckEmpty {
public:
    bool result;
    CheckEmpty(Object obj){
        result = false;
    }
    CheckEmpty(std::vector<Object> vec){
        if(vec.size()>0)
            result = false;
        else
            result = true;
    }
};

#endif //CS352_JSONLANG_H
