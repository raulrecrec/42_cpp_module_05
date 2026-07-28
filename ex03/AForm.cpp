/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:40:43 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/23 14:57:43 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"), _signed(false), _sign_grade(150), _execute_grade(150)
{
}

AForm::AForm(const std::string &name, int sign_grade, int execute_grade)
	: _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade)
{
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other._signed;

	return (*this);
}

AForm::~AForm()
{
}

const std::string	&AForm::getName() const
{
	return (_name);
}

bool	AForm::isSigned() const
{
	return (_signed);
}

int		AForm::getSignGrade() const
{
	return (_sign_grade);
}

int		AForm::getExecuteGrade() const
{
	return (_execute_grade);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed.");
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _execute_grade)
		throw GradeTooLowException();
	
	executeAction();
}

std::ostream	&operator<<(std::ostream &out, const AForm &form)
{
	out << "Form: " << form.getName() << "\nSigned: " << form.isSigned() << "\nSign grade: " << form.getSignGrade() << "\nExecute grade: " << form.getExecuteGrade();
	return (out);
}
