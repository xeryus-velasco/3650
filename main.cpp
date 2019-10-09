//
// Created by Xeryus on 10/8/2019.
//
#include "fp.h"
#include <iostream>
#include <array>

int main()
{
    static constexpr std::array<float, 4> test_data{5, 0,-5,-0};

    fp my_fpu{};

    union raw_float {
        float f;
        int raw;
    };



    for(auto lhs : test_data)
    {
		for(auto rhs : test_data)
		{
			raw_float lhs_value{lhs}, rhs_value{rhs};

			//addition testing
			raw_float result{};
			result.raw = my_fpu.add(lhs_value.raw, rhs_value.raw);

			std::cout << std::hex << "   " << lhs_value.raw << " ( " << lhs << " )\n + "
			<< rhs_value.raw << " ( " << rhs << " )\n = "
			<< result.raw << " ( " << result.f << " )\nGood? "
			<< std::boolalpha
			<< (result.f == (lhs + rhs)) << '\n'
			<< std::endl;

			//multiplication test
			result.raw = my_fpu.mul(lhs_value.raw, rhs_value.raw);
			std::cout << std::hex << "   " << lhs_value.raw << " ( " << lhs << " )\n * "
			          << rhs_value.raw << " ( " << rhs << " )\n = "
			          << result.raw << " ( " << result.f << " )\nGood? "
			          << std::boolalpha
			          << (result.f == (lhs * rhs)) << '\n'
			          << std::endl;
		}

    }
}

