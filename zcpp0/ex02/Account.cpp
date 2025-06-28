#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

///////////////////////////////////////////////////////////////////////////////]
//  DEFAULT CONSTRUCTOR
// Account( void ) {};
Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp(); std::cout << "index:" << _accountIndex
		<< ";amount:" << initial_deposit << ";created" << std::endl;
}

//  DEFAULT DESTRUCTOR
Account::~Account( void ) {
		_displayTimestamp(); std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount << ";closed" << std::endl;
}

//  SETTER
void	Account::makeDeposit( int deposit ) 
{
	_displayTimestamp(); std::cout << "index:" << _accountIndex 
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit 
		<< ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbDeposits + 1 << std::endl;
	
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp(); std::cout << "index:" << _accountIndex 
		<< ";p_amount:" << _amount
		<< ";withdrawal:";
	if (_amount - withdrawal < 0) {
		std::cout << "refused" << std::endl;
		return 1;
	}
	std::cout << withdrawal << ";amount:" << _amount - withdrawal
		<< ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
	
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	return 0;
}
//  GETTER
int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }
///////////////////////////////////////////////////////////////////////////////]
//  OTHER FUNCTIONS
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp(); std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount 
		<< ";deposits:" << _totalNbDeposits 
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int		Account::checkAmount( void ) const { return _amount; };

void	Account::displayStatus( void ) const
{
	_displayTimestamp(); std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount 
		<< ";deposits:" << _nbDeposits 
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
};

void	Account::_displayTimestamp( void ) 
{
	std::time_t now = std::time(0);
	std::tm* localTime = std::localtime(&now);

	std::cout << "[" << (localTime->tm_year + 1900)
			<< std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
			<< std::setw(2) << std::setfill('0') << localTime->tm_mday << "_"
			<< std::setw(2) << std::setfill('0') << localTime->tm_hour 
			<< std::setw(2) << std::setfill('0') << localTime->tm_min 
			<< std::setw(2) << std::setfill('0') << localTime->tm_sec << "] ";
}
///////////////////////////////////////////////////////////////////////////////]
