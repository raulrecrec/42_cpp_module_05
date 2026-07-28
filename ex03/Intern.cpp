/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:12:52 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/28 23:51:04 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm	*Intern::createShrubbery(const std::string &target) const
{
	std::cout << "Intern creates shrubbery creation." << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomy(const std::string &target) const
{
	std::cout << "Intern creates robotomy request." << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidential(const std::string &target) const
{
	std::cout << "Intern creates presidential pardon." << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &form_name, const std::string &target) const
{
	if (form_name == "shrubbery creation")
		return (createShrubbery(target));

	if (form_name == "robotomy request")
		return (createRobotomy(target));

	if (form_name == "presidential pardon")
		return (createPresidential(target));

	std::cout << "Intern cannot create " << form_name << "." << std::endl;
	return (NULL);
}
