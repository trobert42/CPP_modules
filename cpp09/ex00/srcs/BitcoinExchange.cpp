/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:36:36 by trobert           #+#    #+#             */
/*   Updated: 2023/04/25 14:23:22 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _inputFileName(NULL), _dataFileName(NULL)
{
	// std::cout << "Default constructor called for BitcoinExchange" << std::endl;
}

BitcoinExchange::BitcoinExchange(char *av) : _inputFileName(av), _dataFileName("data.csv")
{
	if (_inputFileName.empty())
		throw EmptyArgException();
	_inputFile.open(_inputFileName.c_str(), std::ios_base::in);
	if (_inputFile.is_open() == false) // CHECK IF IT ENDS BY .CSV !!
		throw InvalidFileException();
	_dataFile.open(_dataFileName.c_str(), std::ios_base::in);
	if (_dataFile.is_open() == false)
	{
		_inputFile.close();
		throw InvalidFileException();
	}
	// std::cout << "Constructor called for BitcoinExchange" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & cpy)
{
	// std::cout << "Copy constructor called for BitcoinExchange" << std::endl;
	*this = cpy;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) 
{
	// std::cout << "Assignment operator called for BitcoinExchange" << std::endl;
	if (this != &rhs)
	{
		this->_btc_rates = rhs._btc_rates;
		this->_inputFileName = rhs._inputFileName;
		this->_dataFileName = rhs._dataFileName;
		this->_inputFile.open(rhs._inputFileName.c_str(), std::ios_base::in);
		this->_dataFile.open(rhs._dataFileName.c_str(), std::ios_base::in);
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	_inputFile.close();
	_dataFile.close();
	// std::cout << "Destructor called for BitcoinExchange" << std::endl;
}

void	BitcoinExchange::getRatesFromDatabase(void)
{
	std::string	line;
	bool is_eof = false;

	getline(_dataFile, line, '\n');
	if (line != "date,exchange_rate" || _dataFile.eof() == true)
		throw InvalidDataFileException();
	while (is_eof == false)
	{
		getline(_dataFile, line, '\n');
		if (_dataFile.eof() == true)
			is_eof = true;
		size_t	found = line.find(",", 0);
		if (found == std::string::npos && is_eof != true)
			throw InvalidDataFileException();
		std::string date = line.substr(0, found);
		std::string tmp_rate = line.substr(found + 1, line.size());
		float	rate = std::strtof(tmp_rate.c_str(), NULL);
		_btc_rates[date] = rate;
	}
}

void	BitcoinExchange::isValidDate(std::string date) const
{
	struct tm tm;

	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		throw InvalidDateException();
	std::string	day = date.substr(8, 10);
	if (std::strtod(day.c_str(), NULL) > 31)
		throw InvalidDateException();
}

void	BitcoinExchange::isValidLine(std::string line, size_t index) const
{
	std::string sep = line.substr(index, 3);
	if (sep != " | ")
		throw BadInputException();
}

void	BitcoinExchange::isValidValue(std::string value) const
{
	size_t count = 0;
	for (size_t i(0); i < value.size(); i++)
	{
		if ((value[0] == '+' || value[0] == '-') && value.size() < 2)
			throw BadInputException();
		if (value[i] == '.')
			count++;
		if ((!std::isdigit(value[i]) && value[i] != '.' && value[0] != '-') || count > 1)
			throw BadInputException();
	}
	if (std::strtod(value.c_str(), NULL) > 1000)
		throw TooLargeNumberException();
	if (std::strtod(value.c_str(), NULL) < 0)
		throw NotPositiveNumberException();
}

std::string	BitcoinExchange::findClosestDate(std::string old_date)
{
	std::string found;
	std::string	month_year_to_find = old_date.substr(0, 8);
	std::map<std::string, float>::iterator it = _btc_rates.lower_bound(month_year_to_find);
	while (it != _btc_rates.end())
	{	
		if (month_year_to_find == it->first.substr(0, month_year_to_find.size()))
		{
			std::string potential_date = it->first;
			if (std::strtof(potential_date.substr(8, 10).c_str(), NULL) <= std::strtof(old_date.substr(8, 10).c_str(), NULL))
				found = it->first;
		}
		++it;
	}
	if (found.empty())
	{
		found = (--_btc_rates.lower_bound(month_year_to_find))->first;
		if (found.empty())
			throw DateTooOldException();
	}
	return found;
}

void	BitcoinExchange::printValue(std::string old_date, std::string value)
{
	std::map<std::string, float>::iterator i = _btc_rates.find(old_date);
	std::string	date = old_date;
	if (i == _btc_rates.end())
		date = findClosestDate(old_date);
	float float_value = strtof(value.c_str(), NULL);
	float float_rate = _btc_rates[date];
	float new_value = float_value * float_rate;
	std::cout.precision(7);
	std::cout << old_date << " => " << float_value << " = " << new_value << std::endl;
}

void	BitcoinExchange::getParsingInput(void)
{
	std::string	line;
	bool		is_eof = false;

	getline(_inputFile, line, '\n');
	try
	{
		if (line != "date | value" || _inputFile.eof() == true)
			throw InvalidInputFileException();
		std::cout << line << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return ;
	}

	while (is_eof == false)
	{
		getline(_inputFile, line, '\n');
		if (_inputFile.eof() == true)
			is_eof = true;
		size_t 		index = line.find_first_of(' ', 0);
		std::string	date = line.substr(0, index);
		try
		{
			if (date.empty())
				throw NoDateFoundException();
			isValidDate(date);
			if (line.size() <= 13)
				throw BadInputException();
			std::string value = line.substr(index + 3, line.size());
			isValidLine(line, index);
			isValidValue(value);
			printValue(date, value);
		}
		catch(const BitcoinExchange::InvalidDateException &e)
		{
			std::cerr << "Error: " << e.what() << " => " << date << std::endl;
		}
		catch(const BitcoinExchange::NoDateFoundException &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
