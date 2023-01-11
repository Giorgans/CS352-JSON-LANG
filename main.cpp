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
PROGRAM_BEGIN

    std::cout << string.value  << std::endl << num.value  << std::endl << flo.value  << std::endl;
PROGRAM_END