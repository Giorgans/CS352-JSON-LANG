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
JSON(arr) = ARRAY[ (STRING("TEXT"),NUMBER(23),STRING("32")),OBJECT{STRING(""), NUMBER(23)}]
JSON(OB3) = ob + ob2
PROGRAM_BEGIN
        PRINT OB3
        PRINT (TYPE_OF(flo),STRING("eskm s"))
        SET flo ASSIGN NUMBER(43)
        PRINT flo
PROGRAM_END