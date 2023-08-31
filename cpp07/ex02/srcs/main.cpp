/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:28:55 by trobert           #+#    #+#             */
/*   Updated: 2023/02/09 13:19:56 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>

template <typename T>
void	printArray(Array<T> &array)
{
	if (array.size() == 0)
		std::cout << "size equals " << array.size() << ", nothing inside the array" << std::endl;
	for (unsigned int i(0); i < array.size(); i++)
		std::cout << i << ": " << array[i] << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "-------- TESTING EMPTY ARRAY --------" << std::endl;
	Array<char> nothing;
	printArray(nothing);


	std::cout << "-------- TESTING VALID INDEX --------" << std::endl;
	Array<int> numbers(4);
	printArray(numbers);


	std::cout << "-------- TESTING INVALID INDEX --------" << std::endl;
	try 
	{
		std::cout 
			<< 4 << ": " << std::endl
			<< numbers[4] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl;
	}
	try 
	{
		std::cout
			<< -1 << ": " << std::endl
			<< numbers[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "-------- TESTING CONST ARRAY --------" << std::endl;
	Array<int> const constArray(3);
	// constArray[0] = 6; // can't write this one because const
	// constArray[1] = 6; // can't write this one because const
	// constArray[2] = 6; // can't write this one because const
	for (unsigned int i(0); i < constArray.size(); i++)
		std::cout << i << ": " << constArray[i] << std::endl;
	std::cout << std::endl;


	std::cout << "-------- TESTING DEEP COPY --------" << std::endl;
	numbers[0] = 3;
	numbers[1] = 2;
	numbers[2] = 1;
	numbers[3] = 0;
	std::cout << "Printing numbers array" << std::endl;
	printArray(numbers);
	
	Array<int> testDeepCopy(3);
	testDeepCopy[0] = 0;
	testDeepCopy[1] = 1;
	testDeepCopy[2] = 2;
	std::cout << "Printing testDeepCopy array before assignment operator" << std::endl;
	printArray(testDeepCopy);

	
	testDeepCopy = numbers;
	std::cout << "Printing testDeepCopy array after assignment operator" << std::endl;
	printArray(testDeepCopy);
	
	std::cout << "Changing elements of original array and checking both arrays" << std::endl;
	numbers[0] = 432;
	numbers[1] = 32;
	numbers[2] = 21;
	numbers[3] = 1;
	std::cout << "Printing numbers array" << std::endl;
	printArray(numbers);
	std::cout << "Printing testDeepCopy array" << std::endl;
	printArray(testDeepCopy);
	
	std::cout << "Checking addresses of both arrays" << std::endl;
	std::cout << &testDeepCopy << std::endl;
	std::cout << &numbers << std::endl << std::endl;

	std::cout << "Creating an another array testDeepCopy2 to check cpy constructor" << std::endl;
	Array<int> testDeepCopy2(numbers);
	printArray(testDeepCopy2);
	
	std::cout << "Changing elements of original array and checking both arrays" << std::endl;
	numbers[0] = 543;
	numbers[1] = 6546;
	numbers[2] = 56645;
	numbers[3] = 2145345;
	std::cout << "Printing numbers array" << std::endl;
	printArray(numbers);
	std::cout << "Printing testDeepCopy2 array" << std::endl;
	printArray(testDeepCopy2);


	std::cout << std::endl;
	return 0;
}



// #include "../includes/Array.hpp"
// #include <iostream>
// #include <cstdlib>


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }