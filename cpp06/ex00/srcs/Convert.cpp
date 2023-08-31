	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:38:36 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 15:13:29 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Convert.hpp"

Convert::Convert(void) : _value("Default"), _isOverflow(false), _isAscii(true)
{
	this->getValueType();
	// std::cout << "Default constructor Convert called" << std::endl;
}

Convert::Convert(std::string v) : _value(v), _isOverflow(false), _isAscii(true)
{
	this->getValueType();
	// std::cout << "Parametric constructor Convert called" << std::endl;
}

Convert::~Convert(void)
{
	// std::cout << "Destructor Convert constructor called" << std::endl;	
}

Convert::Convert(Convert const & cpy)
{
	// std::cout << "Copy constructor Convert called" << std::endl;
	*this = cpy;
}

Convert & Convert::operator=(Convert const & rhs)
{
	//std::cout << "Assignment operator Convert called" << std::endl;
	if (this != & rhs)
	{
		this->_value = rhs._value;
		this->_specialCase = rhs._specialCase;
		this->_isOverflow = rhs._isOverflow;
		this->_isAscii = rhs._isAscii;
		this->_char = rhs._char;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
	}
	return *this;
}


int	Convert::parseLitteral(void)
{
	int	countPoint = 0;
	int	countFloat = 0;
	
	/*move this somewhere else*/
	std::string specialCases[SIZE_TAB] = {
		"-inff",
		"+inff",
		"-inf",
		"+inf",
		"nan",
		"nanf",
	};

	for (int i(0); i < SIZE_TAB; i++)
	{
		if (_value == specialCases[i])
		{
			_specialCase.assign((char *)specialCases[i].c_str());
			return 1;
		}
	}
	for (size_t i(0); i < _value.length(); i++)
	{
		if (_value[i] == 'f')
			countFloat++;
		if (_value[i] == '.')
			countPoint++;
		if (i != 0 && !std::isdigit(_value[i]) && _value[i] != '.' && _value[i] != 'f')
			return 0;
	}
	if ((countFloat == 1 && countPoint < 1) || countPoint > 1 || countFloat > 1)	
		return 0;
	
	double doubleTmp = strtod(this->_value.c_str(), NULL);
	if (doubleTmp > INT_MAX || doubleTmp < INT_MIN)
		_isOverflow = true;
	if (doubleTmp < 0 || doubleTmp > 255)
		_isAscii = false;

	return 1;
}

void	Convert::getValueType(void)
{
	try
	{
		if (!parseLitteral())
			throw ScalarNotManagedException();
	}
	catch (const std::exception &e)
	{
		std::cerr
			<< "char: " << e.what() << std::endl
			<< "int: " << e.what() << std::endl
			<< "float: " << e.what() << std::endl
			<< "double: " << e.what() << std::endl;
		return ;
	}
	std::size_t foundPoint = _value.find(".");
	if (this->_value.length() == 1 && !std::isdigit(this->_value[0]))
		this->castFromChar();
	else if ((this->_value[this->_value.size() - 1] == 'f' && foundPoint != std::string::npos) \
		|| (_value == _specialCase && _specialCase[_specialCase.length() - 1] == 'f'))
		castFromFloat();
	else if (foundPoint != std::string::npos || _value == _specialCase)
		castFromDouble();
	else
		castFromInt();
	printCast();

}

void	Convert::castFromChar(void)
{
	this->_char = static_cast<char>(this->_value[0]);
	this->_int = static_cast<int>(this->_value[0]);
	this->_float = static_cast<float>(this->_value[0]);
	this->_double = static_cast<double>(this->_value[0]);
}

void	Convert::castFromFloat(void)
{
	float floatNbr = strtof(this->_value.c_str(), NULL);
	this->_char = static_cast<char>(floatNbr);
	this->_int = static_cast<int>(floatNbr);
	this->_float = static_cast<float>(floatNbr);
	this->_double = static_cast<double>(floatNbr);
}

void	Convert::castFromDouble(void)
{
	double doubleNbr = strtod(this->_value.c_str(), NULL);
	this->_char = static_cast<char>(doubleNbr);
	this->_int = static_cast<int>(doubleNbr);
	this->_float = static_cast<float>(doubleNbr);
	this->_double = static_cast<double>(doubleNbr);
}

void	Convert::castFromInt(void)
{
	long longNbr = atof(this->_value.c_str());
	this->_char = static_cast<char>(longNbr);
	this->_int = static_cast<int>(longNbr);
	this->_float = static_cast<float>(longNbr);
	this->_double = static_cast<double>(longNbr);
}

void	Convert::printCast(void)
{
	//////////////////// PRINT CHAR CONVERSION ////////////////////
	try
	{
		if (!_specialCase.empty() || _isAscii == false)
			throw ImpossibleConvertionException();
		if (!std::isprint(this->_char))
			throw NotPrintableException();
		std::cout << "char: \'" << this->_char << "\'" << std::endl;
	}
	catch (Convert::NotPrintableException &e)
	{
		std::cerr << "char: " << e.what() << std::endl;
	}
	catch (Convert::ImpossibleConvertionException &e)
	{
		std::cerr << "char: " << e.what() << std::endl;
	}

	//////////////////// PRINT INT CONVERSION ////////////////////
	try
	{
		if (!_specialCase.empty() || _isOverflow == true)
			throw ImpossibleConvertionException();
		std::cout << "int: " << this->_int << std::endl;
	}
	catch (Convert::ImpossibleConvertionException &e)
	{
		std::cerr << "int: " << e.what() << std::endl;
	}

	//////////////////// PRINT FLOAT CONVERSION ////////////////////
	if (!_specialCase.empty() && this->_float >= 0)
		std::cout << "float: +" << this->_float << "f" << std::endl;
	else if (!_specialCase.empty() || (_float > _int && _float < _int + 1))
		std::cout << "float: " << this->_float << "f" << std::endl;
	else
		std::cout << "float: " << this->_float << ".0f" << std::endl;
	

	//////////////////// PRINT DOUBLE CONVERSION ////////////////////
	if (!_specialCase.empty() && this->_float >= 0)
		std::cout << "double: +" << this->_double << std::endl;
	else if (!_specialCase.empty() || (_double > _int && _double < _int + 1))
		std::cout << "double: " << this->_double << std::endl;
	else
		std::cout << "double: " << this->_double << ".0" << std::endl;
}