#include <bits/stdc++.h>
#include "count_lines.h"

using namespace std;

int validation(char filename[])   // Passing filename as an argument
{
    unsigned int comp_num_lines=0,num_line_two=0;

    ifstream infile(filename);

    vector<std::vector<double> > numbers;   //creating A 2 dimensional vector having arbitrary size

    string temp;    //temp for temporarily storing vector which will make the complete 2 d vector

    while (getline(infile, temp)) {
        istringstream buffer(temp);
        vector<double> line((istream_iterator<double>(buffer)),
                                istream_iterator<double>());

        numbers.push_back(line);
    }
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i].size()==2)
        {
            comp_num_lines+=numbers[i][1];
            num_line_two++;              //storing the number of lines containing 2 int values
        }
    }
    comp_num_lines=comp_num_lines+1+num_line_two+numbers[0][0];  //computing the expected number of lines in input file

//----------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------------

    if(numbers[0].size()!=1)            //determining whether first line containing 1 integer otherwise throw error
    {
        return 1;
    }


//-------------------------------------------------------------------------------------------------------------------
    for(int i=1;i<numbers.size();i++)
    {
        if(numbers[i].size()==2 || numbers[i].size()==3)     //Determining whether every line containing 2 or 3 int otherwise through error
        {
            //do nothing
        }
        else
        {
            return 2;
        }
    }

//----------------------------------------------------------------------------------------------------------------------
    if(numbers[0][0]!=num_line_two)   //check whether the number of test cases is equal to the number given in the file
    {
        return 3;
    }
//---------------------------------------------------------------------------------------------------------------------

    unsigned int m=count_line(filename);

    if(m>comp_num_lines)    //check whether the expected number of lines and obtained number of lines are equal
    {
        return 4;
    }

    if(m<comp_num_lines)
    {
        return 5;
    }
//------------------------------------------------------------------------------------------------------------------------------
    return 0;
}
