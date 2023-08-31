/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:02:52 by trobert           #+#    #+#             */
/*   Updated: 2023/03/28 17:42:53 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <map>
#include <cmath>


class BitcoinExchange
{
	public:
		BitcoinExchange(char *av);
		BitcoinExchange(BitcoinExchange const & cpy);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		void		getRatesFromDatabase(void);
		void		getParsingInput(void);


		class EmptyArgException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("arg's empty");
				}
		};

		class InvalidFileException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("file doesn't exist or can't be opened");
				}
		};

		class InvalidInputFileException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("invalid content inside input file");
				}
		};

		class InvalidDataFileException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("invalid content inside data.csv file");
				}
		};

		class InvalidDateException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("invalid date");
				}
		};

		class BadInputException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("bad input");
				}
		};

		class NoDateFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("no date found or line is empty");
				}
		};

		class DateTooOldException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("no data for this date");
				}
		};

		class TooLargeNumberException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("too large number");
				}
		};

		class NotPositiveNumberException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("not a positive number");
				}
		};


	private:
		BitcoinExchange(void);
		void		isValidDate(std::string date) const;
		void		isValidLine(std::string line, size_t index) const;
		void		isValidValue(std::string value) const;
		void		printValue(std::string old_date, std::string value);
		std::string	findClosestDate(std::string old_date);
		
		std::ifstream	_inputFile;
		std::ifstream	_dataFile;
		std::string		_inputFileName;
		std::string		_dataFileName;
		std::map<std::string, float> _btc_rates;
};

#endif