#ifndef CS352_JSONLANG_H
#define CS352_JSONLANG_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

#define PROGRAM_BEGIN ;int main(){
#define PROGRAM_END ;return 0;}

// Var definition
#define JSON(name) ;auto name

// Object definitions
#define STRING(text) Object(STRING,text)
#define NUMBER(x)    Object(getNumberType(x),std::to_string(x))
#define OBJECT std::vector<Object>
#define KEY(name) Object(OBJ,name) , (false) ? STRING("NULL")
#define ARRAY  Object(ARR)
#define TRUE Object(BOOL,"true")
#define FALSE Object(BOOL,"false")

// Editing definitions
#define SET ;
#define ASSIGN =
#define ERASE delete[]

// Output
#define PRINT ;std::cout <<

// Function definitions
#define SIZE_OF(name) CheckSize(name).result
#define IS_EMPTY(name) CheckEmpty(name).result
#define HAS_KEY(obj,key) CheckKey(obj,key).result
#define TYPE_OF(name) CheckType(name).result


typedef enum type { INT , FLOAT , STRING , BOOL , OBJ  , ARR , NUL }Type;

class Object {
public:
    std::string value;
    std::vector<Object> arr ;
    Type type;

    Object operator [] (Object obj) {
        arr.push_back(obj);
        return *this;
    }
    Object operator [] (std::vector<Object> obj) {
        arr = obj;
        return *this;

    }
    Object operator [] (std::string &s) {
        for(int i = 0 ; i < arr.size() ; i++)
            if(arr.at(i).value == s && type == OBJ)
                return arr.at(i+1);
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
        if(obj.type == ARR && type == ARR){
            Object result;
            result.arr.insert(result.arr.end(), arr.begin(), arr.end());
            result.arr.insert(result.arr.end(), obj.arr.begin(), obj.arr.end());
            return result;
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
    Object result;
    CheckType(Object obj){
        if(obj.type == STRING) result = STRING("STRING");
        if(obj.type == INT) result = STRING("INT");
        if(obj.type == FLOAT) result = STRING("FLOAT");
        if(obj.type == BOOL) result = STRING("BOOL");
        if(obj.type == ARR) result = STRING("ARRAY");
        if(obj.type == NUL) result = STRING("NULL");
    }

    CheckType(std::vector<Object> vec){
        result = STRING("OBJECT");
    }
};

// Operator overloading

std::vector<Object> operator + (std::vector<Object> const &obj1,std::vector<Object> const &obj2){
    std::vector<Object> result;
    result.insert(result.end(), obj1.begin(), obj1.end());
    result.insert(result.end(), obj2.begin(), obj2.end());
    return result;
}

std::vector<Object> operator , (Object const &ob1,Object const &ob2){
    std::vector<Object> result;
    result.push_back(ob1);
    result.push_back(ob2);
    return result;
}

std::vector<Object> operator , (Object const &ob1,std::vector<Object> const &ob2){
    std::vector<Object> result;
    result.push_back(ob1);
    result.insert(result.end(), ob2.begin(), ob2.end());
    return result;
}

std::vector<Object> operator , (std::vector<Object> const &ob1,std::vector<Object> const &ob2){
    std::vector<Object> result;
    result.insert(result.end(), ob1.begin(), ob1.end());
    result.insert(result.end(), ob2.begin(), ob2.end());
    return result;
}

std::ostream& operator << (std::ostream& os,Object const &obj) {
    os << obj.value;
    return os;
}

std::ostream& operator << (std::ostream& os,std::vector<Object> const &obj) {
    std::string s;
    for(int i = 0 ; i < obj.size() ; i++)
        os <<  obj.at(i).value << " \n ";
    return os;
}



#endif //CS352_JSONLANG_H