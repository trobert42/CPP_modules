/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:25:36 by trobert           #+#    #+#             */
/*   Updated: 2023/02/09 18:07:27 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main(void)
{
	std::cout << "------- INITIALIZING THE SPAN -------" << std::endl;
	Span sp(5);
	std::cout << "Span max size is : " << sp.getSize() << std::endl;
	sp.print();
	std::cout << std::endl;



	std::cout << "------- TEST WITH LONGEST SPAN FUNCTION WITH NOTHING INSIDE -------" << std::endl;
	try
	{
		unsigned int longestSpanNbr = sp.longestSpan();
		std::cout << "Longest span: " << longestSpanNbr << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl; 
	}
	std::cout << std::endl;
	sp.addNumber(1);



	std::cout << "------- TEST WITH LONGEST SPAN FUNCTION WITH ONE NBR INSIDE -------" << std::endl;
	try
	{
		unsigned int longestSpanNbr = sp.longestSpan();
		std::cout << "Longest span: " << longestSpanNbr << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl; 
	}
	std::cout << std::endl;
	

	
	std::cout << "------- VALID TEST -------" << std::endl;
	try
	{
		sp.addNumber(19);
		sp.addNumber(7);
		sp.addNumber(-213);
		sp.addNumber(-212);
		sp.print();
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl; 
	}
	std::cout << std::endl;



	std::cout << "------- ADDIND ONE TOO MUCH INTO THE SPAN -------" << std::endl;
	try
	{
		sp.addNumber(0);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl; 
	}
	
	std::cout << std::endl;
	sp.print();
	std::cout << std::endl;



	std::cout << "------- BIG SPAN TEST -------" << std::endl;
	int size = 10001;
	Span bigSp(size);
	std::vector<int> test;
	for (int i(0); i < size; i++)
		test.push_back(i);
	try
	{
		bigSp.addNumber(test.begin(), test.end());
		std::cout << "Longest span: " << bigSp.longestSpan() << std::endl;
		std::cout << "Shortest span: " << bigSp.shortestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl; 
	}

	std::cout << std::endl;
	return 0;
}