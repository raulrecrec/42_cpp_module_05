/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:39:07 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/23 11:16:58 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "========== VALID CONSTRUCTION ==========\n";
	try
	{
		Bureaucrat	boss("Boss", 1);
		Bureaucrat	intern("Intern", 150);

		Form	contract("Contract", 50, 25);

		std::cout << boss << std::endl;
		std::cout << intern << std::endl;
		std::cout << contract << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << "\n========== FORM GRADE TOO HIGH ==========\n";
	try
	{
		Form	form("Invalid", 0, 50);
	}
	catch (const std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << "\n========== FORM GRADE TOO LOW ==========\n";
	try
	{
		Form	form("Invalid", 50, 151);
	}
	catch (const std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << "\n========== SUCCESSFUL SIGN ==========\n";
	try
	{
		Bureaucrat	boss("Boss", 10);
		Form		contract("Contract", 20, 50);

		std::cout << contract << std::endl;
		boss.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << "\n========== FAILED SIGN ==========\n";
	try
	{
		Bureaucrat	intern("Intern", 100);
		Form		contract("Contract", 20, 50);

		std::cout << contract << std::endl;
		intern.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	return (0);
}