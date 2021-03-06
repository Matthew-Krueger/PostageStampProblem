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


#ifndef POSTAGE_STAMP_PROBLEM_UTILS_HPP
#define POSTAGE_STAMP_PROBLEM_UTILS_HPP

#include <vector>
#include <cstdint>
#include <sstream>

namespace PostageStampProblem::Backend{

    template<typename T>
    uint32_t sumVector(const std::vector<T>& vector){

        uint32_t sum = 0;
        for(T n:vector){
            sum+=n;
        }

        return sum;

    }

    template<typename T>
    std::string formatVector(const std::vector<T>& vector){

        std::stringstream result;

        bool firstFlag = false;
        for(T number:vector){

            if(firstFlag){
                result << '+';
            }
            firstFlag = true;

           result << (int)number;

        }

        return result.str();

    }

    template<typename T>
    inline std::vector<T>& pushback_repeated(std::vector<T>& vector, T number, uint32_t count){

        for(unsigned int i=0; i<count; ++i){
            vector.push_back(number);
        }

        return vector;

    }

}

#endif //POSTAGE_STAMP_PROBLEM_UTILS_HPP
