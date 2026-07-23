/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:40:43 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/23 11:00:24 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _signed(false), _sign_grade(150), _execute_grade(150)
{
}

Form::Form(const std::string &name, int sign_grade, int execute_grade)
	: _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade)
{
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;

	return (*this);
}

Form::~Form()
{
}

const std::string	&Form::getName() const
{
	return (_name);
}

bool	Form::isSigned() const
{
	return (_signed);
}

int		Form::getSignGrade() const
{
	return (_sign_grade);
}

int		Form::getExecuteGrade() const
{
	return (_execute_grade);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << "\nSigned: " << form.isSigned() << "\nSign grade: " << form.getSignGrade() << "\nExecute grade: " << form.getExecuteGrade();
	return (out);
}
