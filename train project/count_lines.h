#include<iostream>
#include<fstream>
using namespace std;

unsigned int count_line(char Filename[])
{
    unsigned int number_of_lines = 0;
    FILE *infile = fopen(Filename, "r");
    int ch;

    while (EOF != (ch=getc(infile)))
        if ('\n' == ch)
            ++number_of_lines;
    number_of_lines++;
    return number_of_lines;
}
