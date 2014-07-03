#include <stdio.h>
#include <string.h>

#include "cspec.h"
#include "cspec_output_header.h"
#include "cspec_output_verbose.h"
#include "cspec_output_unit.h"

DESCRIBE(strcmp, "int strcmp ( const char * str1, const char * str2 )")

    IT( "returns 0 only when strings are equal" )
        SHOULD_EQUAL( strcmp("hello","hello"), 1)
        SHOULD_NOT_BE_NULL( strcmp("hello", "world") )
    END_IT

    IT( "returns a negative integer when str1 is less than str2" )
        SHOULD_BE_TRUE( strcmp("hello", "world") > 0 )
        SHOULD_BE_TRUE( strcmp("0123", "1321431") < 0 )
    END_IT

END_DESCRIBE

int main(){
    CSpec_Run( DESCRIPTION( strcmp ), CSpec_NewOutputVerbose() );

    return 0;
}
