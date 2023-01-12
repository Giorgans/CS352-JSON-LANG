#ifndef CS352_JSONLANG_H
#define CS352_JSONLANG_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>

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
#define ASSIGN
#define ERASE

// Output
#define PRINT ;std::cout <<

// Function definitions
#define SIZE_OF(name) CheckSize(name).result
#define IS_EMPTY(name) CheckEmpty(name).result
#define HAS_KEY(obj,key) CheckKey(obj,key).result
#define TYPE_OF(name) CheckType(name).type

typedef enum type { INT , FLOAT , STRING , BOOL , OBJ  , ARR , NUL }Type;

class Object {
public:
    std::string value;
    std::vector<Object> arr ;
    Type type;

    std::vector<Object> operator [] (std::vector<Object> &obj) {
        return obj;
    }

    Object operator [] (std::string &s) {

    }

    Object operator + (Object const &obj){
        if( ( obj.type == FLOAT || obj.type == INT ) && ( type == INT || type == FLOAT ) ) {
            float x1 = std::stof(value), x2 = std::stof(obj.value) ,x;
            x = x1 + x2;
            if(obj.type == INT && type == INT)
                return Object(INT,std::to_string(int(x)));
            else
                return Object(FLOAT,std::to_string(x));
        }
        if(obj.type == STRING && type == STRING) {
            std::string x1 = value, x2 = obj.value ,x;
            x = x1 + x2;
            return Object(STRING,x);
        }
        if(obj.type == BOOL || type == BOOL)
            assert(false && "Cannot add booleans" );
        if(obj.type == NUL || type == NUL)
            assert(false && "Cannot add null" );
        assert(false && "Cannot add different types");
    }

    Object operator - (Object const &obj){
        if(( obj.type == FLOAT || obj.type == INT ) && ( type == INT || type == FLOAT )) {
            float x1 = std::stof(value), x2 = std::stof(obj.value) ,x;
            x = x1 - x2;
            if(obj.type == INT && type == INT)
                return Object(INT,std::to_string(int(x)));
            else
                return Object(FLOAT,std::to_string(x));
        }
        assert(false && "Cannot subtract  non arithmetic types");
    }

    Object operator * (Object const &obj){
        if( ( obj.type == FLOAT || obj.type == INT ) && ( type == INT || type == FLOAT )) {
            float x1 = std::stof(value), x2 = std::stof(obj.value) ,x;
            x = x1 * x2;
            if(obj.type == INT && type == INT)
                return Object(INT,std::to_string(int(x)));
            else
                return Object(FLOAT,std::to_string(x));
        }
        assert(false && "Cannot multiply non arithmetic types");
    }

    Object operator / (Object const &obj){
        if( ( obj.type == FLOAT || obj.type == INT ) && ( type == INT || type == FLOAT ) ) {
            float x1 = std::stof(value), x2 = std::stof(obj.value) ,x;
            x = x1 / x2;
            return Object(FLOAT,std::to_string(x));
        }
        assert(false && "Cannot divide non arithmetic types");
    }

    Object operator % (Object const &obj){
        if(obj.type == INT && type == INT) {
            int x1 = std::stoi(value), x2 = std::stoi(obj.value) ,x;
            x = x1 % x2;
            return Object(INT,std::to_string(x));
        }
        assert(false && "Cannot modulo other types");

    }

    Object operator > (Object const &obj){
        if( ( obj.type == FLOAT || obj.type == INT ) && ( type == INT || type == FLOAT ) ) {
            float x1 = std::stof(value), x2 = std::stof(obj.value);
            if ( x1 > x2 )
                return TRUE;
            return FALSE;
        }
        assert(false && "Cannot compare different types");
    }

    Object operator >= (Object const &obj){
        if( ( obj.type == FLOAT || obj.type == INT ) && ( type == INT || type == FLOAT ) ) {
            float x1 = std::stof(value), x2 = std::stof(obj.value);
            if (x1 >= x2 )
                return TRUE;
            return  FALSE;
        }
        assert(false && "Cannot compare different types");
    }

    Object operator < (Object const &obj){
        if( ( obj.type == FLOAT || obj.type == INT ) && ( type == INT || type == FLOAT ) ) {
            float x1 = std::stof(value), x2 = std::stof(obj.value);
            if (x1 < x2 )
                return TRUE;
            return  FALSE;
        }
        assert(false && "Cannot compare different types");
    }

    Object operator <= (Object const &obj){
        if( ( obj.type == FLOAT || obj.type == INT ) && ( type == INT || type == FLOAT ) ) {
            float x1 = std::stof(value), x2 = std::stof(obj.value);
            if (x1 <= x2 )
                return TRUE;
            return  FALSE;
        }
        assert(false && "Cannot compare different types");
    }

    Object operator && (Object const &obj){
        if(obj.type == BOOL && type == BOOL ) {
            if ( value == "true" && obj.value == "true" )
                return TRUE;
            return FALSE;
        }
    }

    Object operator || (Object const &obj){
        if(obj.type == BOOL && type == BOOL ) {
            if ( value == "true" || obj.value == "true" )
                return TRUE;
            return FALSE;
        }
        assert(false && " Cannot compare different types");
    }

    Object operator ! () {
        if (type == BOOL){
            if ( value == "true")
                return FALSE;
            return TRUE;
        }
        assert(false && "Cannot compare other type than boolean");
    }

    Object(){}
    Object(Type t):type(t){}
    Object(Type t,std::string val):value(val),type(t){}
    ~Object(){};
};

Type getNumberType(float x){
    if (abs(x-int(x) > 0) )
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
    Object result;
    CheckEmpty(Object obj){
        result = FALSE;
    }
    CheckEmpty(std::vector<Object> vec){
        result = TRUE;
        if(vec.size()>0)
            result = FALSE;
    }
};

class CheckKey {
public:
    Object result;
    CheckKey(Object obj){
        result = FALSE;
    }
    CheckKey(std::vector<Object> vec,std::string key){
        result = FALSE;
        for(int i = 0 ; i<vec.size() ; i++)
            if(vec.at(i).value == key)
                result = TRUE;
    }
};

class CheckType {
public:
    Type type;
    CheckType(Object obj){
        type = obj.type;
    }
    CheckType(std::vector<Object> vec){
        type = OBJ;
    }
};

// Operator overloading

std::vector<Object> operator + (std::vector<Object> const &obj1,std::vector<Object> const &obj2){
    std::vector<Object> result;
    result.insert(result.end(), obj1.begin(), obj1.end());
    result.insert(result.end(), obj2.begin(), obj2.end());
    return result;

}


void operator , (Object const &ob1,Object const &ob2){

}


std::ostream& operator << (std::ostream& os,Object const &obj) {
    os << obj.value;
}

std::ostream& operator << (std::ostream& os,std::vector<Object> const &obj) {
    std::string s;
    for(int i = 0 ; i < obj.size() ; i+=2)
        s +=  obj.at(i).value + " : " + obj.at(i+1).value + "\n";
    os << s;
}

#endif //CS352_JSONLANG_H