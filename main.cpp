#include "JSONlang.h"
        JSON(string) = STRING("HELLO WORLD ")
        JSON(num) = NUMBER(69)
        JSON(flo) = NUMBER(69.665)
        JSON(boolt) = TRUE
        JSON(boolf) = FALSE
        JSON(ob) = OBJECT {
            KEY("test1")  : STRING("value") ,
            KEY("test2")  : NUMBER(69) ,
            KEY("test3")  : NUMBER(69.665)
        }
        JSON(ob2) = OBJECT{}

        PROGRAM_BEGIN

    std::cout << string.value  << std::endl << num.value  << std::endl << flo.value  << std::endl;
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


PROGRAM_END