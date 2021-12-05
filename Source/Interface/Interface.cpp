/*###########################################################################################################
#                                                                                                           #
#    Postage Stamp Problem - Explains the Postage Stamp problem also known as the Chicken McNuggett Theorem #
#    Copyright (C) 2021 Matthew Krueger <contact@matthewkrueger.com>                                        #
#                                                                                                           #
#    This program is free software: you can redistribute it and/or modify                                   #
#    it under the terms of the GNU General Public License as published by                                   #
#    the Free Software Foundation, either version 3 of the License, or                                      #
#    (at your option) any later version.                                                                    #
#                                                                                                           #
#    This program is distributed in the hope that it will be useful,                                        #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of                                         #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                          #
#    GNU General Public License for more details.                                                           #
#                                                                                                           #
#    You should have received a copy of the GNU General Public License                                      #
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.                                 #
#                                                                                                           #
###########################################################################################################*/

#include "Interface.hpp"
#include <iostream>

#include <PostageStampProblem/Backend.hpp>

int main(int argc, char** argv){

    /* Print welcome message and give overview of the functionality */
    {
        std::cout <<    "Postage Stamp Problem Copyright (C) 2021 Matthew Krueger <contact@matthewkrueger.com>\n\n" <<
                        "This program comes with ABSOLUTELY NO WARRANTY; for details type `w'.\n" <<
                        "This is free software, and you are welcome to redistribute it\n"<<
                        "under certain conditions; type `c' for details.\n\n\n";

        std::cout <<    "\tThe Postage Problem, otherwise known as the Chicken McNuggett Theorem, is a theory that\n" <<
                        "given a specific combination of two or more items is reached, such as 11 and 13, that there\n" <<
                        "exists a number (mn-n-m, where m and n are the two numbers) where every number after that\n" <<
                        "can be made by a combination of the starting numbers. This program attempts to illustrate that.\n\n\n";
    }

    while(true){

        std::cout <<    "Below are the available examples. Select their number to continue. Or type e to exit.\n" <<
                        "\t1. 11 and 13\n\n";
        std::cout <<    "Your Choice: ";

        std::string choice;
        std::cin >> choice;

        /* exit condition */
        if(choice=="e") break;
        if(choice=="w") PostageStampProblem::warrenty();
        if(choice=="c") PostageStampProblem::conditions();
        if(choice=="g") PostageStampProblem::g();
        if(choice=="1") PostageStampProblem::elevenByThirteenInterface();


    }

    std::cout << "\nThank you for using the application!\n";

    return 0;

}

namespace PostageStampProblem{

    void elevenByThirteenInterface(){
        uint32_t minimum = (13 * 11) - 13 - 11 + 1;

        while(true) {

            uint32_t selection = 0;

	    /* ask for a number */
            std::cout << "\n11x13 Postage Stamp Problem. The minimum number you can have is ((11*13) - 11 - 13 + 1) or "
                      << minimum << ".\n" <<
                      "Select the number you would like to see (or 0 to return to to the previous menu): ";
            std::cin >> selection;

            if(selection == 0) break;
            if(selection < minimum) {
                std::cout << '\n' << selection << " is not a valid selection. Please select a number greater than or equal to " << minimum;
                continue;
            };

	    /* Process the numbers and get a vector back of the numbers */
            std::cout << '\n';
            std::cout << "Processing....\n";
            auto numbers = Backend::elevenByThirteen(selection);

	    /* Ensure what we generated is correct */
            std::cout << "Verifying.....\n";
            if(selection != Backend::sumVector(numbers)){
                std::cout << "There was an error coming up with your selection.\n";
                std::cout << Backend::formatVector(numbers) << " != " << selection;
            }

	    /* Finally, print the vector */
            std::cout << "Verified\n\n";
            std::cout << Backend::formatVector(numbers) << " == " << selection;
	    std::cout << "\n\n";
	    
        }
    }

    void warrenty(){

        std::cout << R"(
  THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY
APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT
HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY
OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM
IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF
ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
)";

    }

    void conditions(){

        std::cout << "\nI don't want to format it. Just see the GNU Public License V3.\n";

    }

    void g(){
        std::cout<<"\n\nI love you Gordon!\n\n";
    }

}
