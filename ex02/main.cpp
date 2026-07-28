/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:39:07 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/28 21:07:35 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	std::srand(std::time(NULL));

	Bureaucrat				boss("Boss", 1);
	Bureaucrat				intern("Intern", 150);

	ShrubberyCreationForm	shrubbery("garden");
	RobotomyRequestForm		robotomy("Bender");
	PresidentialPardonForm	pardon("Arthur Dent");

	std::cout << "========== Shrubbery ==========" << std::endl;
	shrubbery.beSigned(boss);
	shrubbery.execute(boss);

	std::cout << "\n========== Robotomy ==========" << std::endl;
	robotomy.beSigned(boss);
	robotomy.execute(boss);
	robotomy.execute(boss);
	robotomy.execute(boss);

	std::cout << "\n========== Presidential ==========" << std::endl;
	pardon.beSigned(boss);
	pardon.execute(boss);

	std::cout << "\n========== Exceptions ==========" << std::endl;
	try
	{
		shrubbery.beSigned(intern);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		robotomy.execute(intern);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	PresidentialPardonForm unsigned_form("Ford Prefect");

	try
	{
		unsigned_form.execute(boss);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
