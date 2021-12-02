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


#include <iostream>
#include "ElevenByThirteen.hpp"
#include "Utils.hpp"

/* This maps how many thirteens are in each item, useful for mapping the cycle on to the result */
static uint8_t thirteenMap[] = {5,0,6,1,7,2,8,3,9,4,10};

namespace PostageStampProblem::Backend{

    std::vector<uint8_t> elevenByThirteen(uint32_t target){

        std::vector<uint8_t> list;

        /* Determine Starting Eligibility */
        if(target<120){
            std::cerr << "Cannot complete an 11x13 backend with less than 120 as a target.\n";
            return list;
        }

        /* The offset determines the distance from our starting position. I.e. how offset our target is from
         * our starting position. This helps us to determine our starting formula */
        uint32_t offset = target-120;

        /* Our index is how far into the 11 cycle we are. */
        uint8_t index = offset%11;

        /* If we have less than 5 13s in the final result, we follow the longer pattern */
        if(thirteenMap[index]<5){
            uint32_t elementCount = (offset/11)+11; // Default count is 11, every cycle add 1
            list.reserve(elementCount);
            list = pushback_repeated<uint8_t>(list, 13, thirteenMap[index]);
            list = pushback_repeated<uint8_t>(list, 11, elementCount-thirteenMap[index]);
        }else{
            /* otherwise we follow the shorter pattern. */
            uint32_t elementCount = (offset/11)+10; // Default count is 10, every cycle add 1
            list.reserve(elementCount);
            list = pushback_repeated<uint8_t>(list, 13, thirteenMap[index]);
            list = pushback_repeated<uint8_t>(list, 11, elementCount-thirteenMap[index]);
        }

        return list;

    }

}