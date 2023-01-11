#ifndef CS352_JSONLANG_H
#define CS352_JSONLANG_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <map>
bool isObject = false;
#define PROGRAM_BEGIN ;int main(){
#define PROGRAM_END ;return 0;}

#define JSON(name) ;auto name

// Object definitions
#define STRING(text) Object(STRING,text)
#define NUMBER(x)    Object(getNumberType(x),std::to_string(x))
#define OBJECT std::vector <Object>
#define KEY(name) STRING(name) , (false) ? STRING("NULL")
#define ARRAY  std::vector <Object>
#define TRUE Object(BOOL,"true");
#define FALSE Object(BOOL,"false");

// Editing definitions
#define SET
#define ASSIGN =
#define ERASE

//Output
#define PRINT

typedef enum type { INT , FLOAT , STRING , BOOL , NUL }Type;
class Object {
public:
    std::string value;
    Type type;
    Object(){}
    Object(Type t,std::string val):value(val),type(t){}
    ~Object();
};

Type getNumberType(float x){
    if (abs(x- int(x) > 0) )
        return FLOAT;
    else
        return INT;
}




#endif //CS352_JSONLANG_H
