#include "JSONlang.h"
        JSON(string) = STRING("HELLO ") + STRING(" WORLD ")
        JSON(num) = NUMBER(69)
        JSON(flo) = NUMBER(69.665) + NUMBER(69.665)
        JSON(numsum) = NUMBER(69) + NUMBER(31)

        JSON(floflo) = NUMBER(30)

        JSON(boolt) = TRUE
        JSON(boolf) = FALSE
        JSON(ob) = OBJECT {
            KEY("test1")  : STRING("value") ,
            KEY("test2")  : NUMBER(69) ,
            KEY("test3")  : NUMBER(69.665)
        }
        JSON(ob2) = OBJECT{
            KEY("test4")  : STRING("TEST")
        }
        JSON(OB3) = ob + ob2
        PROGRAM_BEGIN
    std::cout << string.value  << std::endl << num.value  << std::endl << flo.value << std::endl << numsum.value << std::endl;
    std::cout << std::endl;
    if( SIZE_OF(ob) )
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    if( SIZE_OF(ob2) )
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    if( IS_EMPTY(ob) )
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    if( IS_EMPTY(ob2) )
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    if( HAS_KEY(ob,"test2") )
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;


    if( HAS_KEY(ob,"lol") )
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    if(TYPE_OF(ob2)==OBJ)   std::cout << "object" << std::endl;
    if(TYPE_OF(ob2)==STRING)   std::cout << "string" << std::endl;
    if(TYPE_OF(ob2)==FLOAT)   std::cout << "float" << std::endl;
    if(TYPE_OF(ob2)==INT)   std::cout << "int" << std::endl;

    if(TYPE_OF(flo)==OBJ)   std::cout << "object" << std::endl;
    if(TYPE_OF(flo)==STRING)   std::cout << "string" << std::endl;
    if(TYPE_OF(flo)==FLOAT)   std::cout << "float" << std::endl;
    if(TYPE_OF(flo)==INT)   std::cout << "int" << std::endl;

    if(TYPE_OF(num)==OBJ)   std::cout << "object" << std::endl;
    if(TYPE_OF(num)==STRING)   std::cout << "string" << std::endl;
    if(TYPE_OF(num)==FLOAT)   std::cout << "float" << std::endl;
    if(TYPE_OF(num)==INT)   std::cout << "int" << std::endl;


    for(int i = 0; i < OB3.size() ; i++){
        std::cout << OB3.at(i).value << std::endl;
    }


PROGRAM_END