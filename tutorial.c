/* ---------------------------------------------------
 * > Tutorial made by Iker Saborit
 * > | GitHub: https://github.com/iSaborit
 * > | If this is ever posted on GitHub, please star the repository.
 *
 * Special thanks to anyone who wants to collaborate on this project.
 * Feel free to submit a pull request (PR) and add your message here!
 * -------
 * -------
 *
 * This tutorial follows the slides from "Le langage C," created by:
 * | V. Nicomette, T. Monteil, S. Hernando, and F. Pompignac.
 * However, the explanations are written in my own style.
 * Also I added some extra things.
 * --------------------------------------------------- */

/* -----------------------------
 * TL;DR: C is a cool language.
 * TL;DR: "Too Long; Didn't Read"
 * -----------------------------
 *
 * C is a programming language created by Dennis Ritchie at Bell Laboratories in
 * 1972. It was derived from 'ALGOL', 'BCPL', and 'B' programming languages,
 * with the goal of combining the best elements of high-level languages with the
 * control and flexibility of assembly.
 *
 * By 1973, the entire UNIX operating system was rewritten in C.
 *
 * In 1978, "The C Programming Language" was published, now commonly referred to
 * as the "K&R standard" after its authors, Brian Kernighan and Dennis Ritchie.
 * Some enthusiasts consider this book the "Bible" of the C language.
 *
 * During the 1980s, C was primarily associated with UNIX development, and
 * numerous dialects emerged due to the lack of standardized version control
 * (*as K&R themselves noted*). A highly influential organization, ANSI
 * (American National Standards Institute), established a formal standard for C
 * in 1989, which was later approved by ISO (International Organization for
 * Standardization) in 1990. This version became known as "ANSI C."
 *
 * Subsequent updates have been made to the language, with the latest version
 * being C23.
 */

/// we include the "stdio.h" file header so we can print
/// data while executing the program. More later on header files.
#include <stdio.h>

/* This is the function that the program will execute when executing (never
 * better said) the program. Is also called the "main" function.
 *
 * ```c
 * int main (void)
 * int main ()
 * int main (int argc, char *argv[])
 * int main (int argc, char ** argv)
 * ```
 *
 * you are free to go with this options, but if you ever put
 * ```aberration
 * void main()
 * ```
 * I will appear in your dreams.
 * More later on the return types. But for now, just keep in mind main always
 * return an
 * ****INTEGER****.
 */
int main() {
    // ########## VARIABLES. Chapter 2.

    /* To declare a variable, we write:
     * <data_type> <variable_name>; */
    char first_letter;
    /* Boom, variable declared.
     *
     * Let's first talk about data types:
     *
     * List of basic data types and is usual sizes:
     * | char: 1 byte
     * | short: 2 bytes
     * | int: 4 bytes
     * | long int: (4 bytes on x32, 8 bytes on x64)
     * | long long int: (8 bytes)
     * | float: 4 bytes
     * | double: (8 bytes)
     *
     *
     * There are also "unsigned" data types.
     * Let me explain what that keyword does with an example:
     *
     * Here we have a short:    || Here we have an unsigned short:
     * 00000000 00000000        00000000 00000000
     * ^ sign bit.              ^.....
     * Did you notice something?
     * Yeah, the unsigned short "ignores" the sign bit, so all values are
     * positive. That's why our short goes from  -2^15      to  2^15 - 1 -32,768
     * to  32,767 and our unsigned short goes from      0    to  2^16 - 1 0 to
     * 65,535
     *
     * To know the size of a data type, just use sizeof()! */
    printf("%zu\n", sizeof(long int));

    /* to say something is true, just use an integer!
     * 0                            => false!
     * every another f****** value  => true!
     *
     * if you are coding in C99 or above, you can always import
     * <bool.h>!
     * with:
     * > `#import <bool.h>`
     *
     * you will be able to:
     *
     * ```c
     * bool i_am_fine = false;
     * bool are_you_reading_this = true; // probably false.
     * ```
     *
     * we are cool guys so we won't import bool.h.
     *
     * Let's practice a bit! (and give values to our data)...
     */

    int best_num;
    best_num = 3;
    int second_best_num = 6;

    char best_letter = 'i';

    first_letter = 'a';
    // Remember we declared "first_letter" before? if we tried to re-declare the
    // variable with `char first_letter`, our program would not compile :(.
    //
    // tutorial.c:126:10: error: redefinition of 'first_letter'
    // 126 |     char first_letter = 'b';
    //     |          ^
    // tutorial.c:67:10: note: previous definition is here
    //  67 |     char first_letter;

    // later we will see how to format strings with printf.
    printf("Printing \"best num\": %d\n"
           "Printing \"second_best_num\": %d\n"
           "Printing \"first_letter\": %c\n"
           "Printing \"best_letter\": %c\n\n\n\n",
           best_num, second_best_num, first_letter, best_letter);

    // Let's talk about arrays!!! ! ! !  !  !  !    !    !    !     .     . .
    printf("ARRAYS --------------------------------------------- THE FUNNIEST TOPIC\n");
    // It's not a fun topic.

    /*
     * To declare an array, we just write this:
     * <data_type> <array_name>[<max_length?>];
     *
     * To illustrate this properly, I'm going to create one:
     */

    int prime_numbers[10] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};

    printf("prime_numbers[0]: %d\n"
           "prime_numbers[6]: %d\n"
           "prime_numbers[10]  <-- error, length = 10, index from 0 to 9\n"
           "prime_numbers[9]: %d\n",
           prime_numbers[0], prime_numbers[6], prime_numbers[9]);

    // For the sake of testing, let's see what happens...
    int prime_number_10 = prime_numbers[10];
    printf("\"prime_number_10\" = %d\n\n", prime_number_10);

    /*
     * COMPILATION WARNING:
     * tutorial.c:160:27: warning: array index 10 is past the end of the array (that has type 'int[10]') [-Warray-bounds]
     * 160 |     int prime_number_10 = prime_numbers[10];
     *     |                           ^             ~~
     * tutorial.c:151:5: note: array 'prime_numbers' declared here
     * 151 |     int prime_numbers[10] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};
     *     |     ^
     * 1 warning generated.
     *
     * RUNTIME OUTPUT:
     * ...
     * prime_number_10 = 514719753
     *
     * Welcome to your first "XD" moment in C.
     * In C, there are no strict boundaries—you can do whatever you want.
     * But you better know what you're doing, or you might modify things you
     * never intended to, causing unexpected behavior in your program.
     *
     * So, are arrays infinite? Kind of, but not really.
     */

    /*
     * Let me reveal you a secret: strings never have been a data type. 
     * Instead, they are an array of characters, that ALWAYS end with '\0'. 
     * And yes, '\0' is a character, that's why it has the ' surrounding it.
     * So, lets declare some strings! */
    char the_coolest_string[24] = "I'm the coolest string!";
    char the_coolest_univ[5] = "INSA";
    /* 
     * But wait, why the_coolest_univ has is 5-char-spaced?
     * you stupid moron you dont listen to me: '\0' is ALWAYS there!!!! */
    printf("the_coolest_univ[5]: %c\n"
           ">>>> there is no value because is the null character '\\0'\n\n", the_coolest_univ[4]); 
    // Also you can make the coolest compiler of all time deduce the length of your array for you.


    char deduce_my_length[] = "mystery_length !! you will never know what's the length";

    printf("deduce_my_length: %s\n"
           "sizeof(deduce_my_length): %zu\n",
           deduce_my_length,
           sizeof(deduce_my_length));
    

    return 0;
}
