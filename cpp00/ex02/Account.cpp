/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:26:57 by trobert           #+#    #+#             */
/*   Updated: 2022/12/16 11:15:15 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);

	std::cout
		<< "[" 
		<< 1900 + local_time->tm_year 
		<< 1 + local_time->tm_mon 
		<< local_time->tm_mday << "_" 
		<< local_time->tm_hour 
		<< 1 + local_time->tm_min 
		<< 1 + local_time->tm_sec << "] ";
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex 
		<< ";account:" << initial_deposit 
		<< ";created" << std::endl;
	Account::_nbAccounts += 1;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex 
		<< ";account:" << _amount 
		<< ";closed" << std::endl;
}

int Account::getNbAccounts( void ) // private
{
	return (Account::_nbAccounts);
}

int	Account::getNbDeposits( void ) // private
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) // private
{
	return (Account::_totalNbWithdrawals);
}

int	Account::getTotalAmount( void ) // private
{
	return (Account::_totalAmount);
}

int	Account::checkAmount( void ) const // public
{
	return (this->_amount);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout 
		<< "accounts:" <<  Account::getNbAccounts() 
		<< ";total:" << Account::getTotalAmount() 
		<< ";deposits:" << Account::getNbDeposits() 
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}	

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex 
		<< ";amount:" << this->_amount 
		<< ";deposit:" << this->_nbDeposits 
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = this->_amount;

	this->_nbDeposits += 1;
	this->_amount += deposit;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex 
		<< ";p_amount:" << p_amount 
		<< ";deposit:" << deposit 
		<< ";amount:" << this->_amount 
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = this->_amount;

	if (withdrawal < this->_amount)
	{
		this->_nbWithdrawals += 1;
		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals += 1; 	
		Account::_totalAmount -= withdrawal;
		Account::_displayTimestamp();
		std::cout 
			<< "index:" << this->_accountIndex 
			<< ";p_amount:" << p_amount 
			<< ";withdrawal:" << withdrawal 
			<< ";amount:" << this->_amount 
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		Account::_displayTimestamp();
		std::cout 
			<< "index:" << this->_accountIndex 
			<< ";p_amount:" << p_amount 
			<< ";withdrawal:refused" << std::endl;
		return (false);	
	}
}
