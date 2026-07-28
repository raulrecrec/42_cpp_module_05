/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:39:07 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/28 23:53:40 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));

	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	worker("Worker", 50);

	AForm	*form;

	std::cout << "\n===== Shrubbery =====" << std::endl;
	form = intern.makeForm("shrubbery creation", "home");
	if (form)
	{
		form->beSigned(boss);
		form->execute(boss);
		delete form;
	}

	std::cout << "\n===== Robotomy =====" << std::endl;
	form = intern.makeForm("robotomy request", "Bender");
	if (form)
	{
		form->beSigned(boss);
		form->execute(boss);
		form->execute(boss);
		form->execute(boss);
		delete form;
	}

	std::cout << "\n===== Presidential =====" << std::endl;
	form = intern.makeForm("presidential pardon", "Arthur Dent");
	if (form)
	{
		form->beSigned(boss);
		form->execute(boss);
		delete form;
	}

	std::cout << "\n===== Unknown form =====" << std::endl;
	form = intern.makeForm("pizza request", "Pepperoni");
	if (form)
		delete form;

	std::cout << "\n===== Grade too low =====" << std::endl;
	form = intern.makeForm("robotomy request", "Marvin");
	if (form)
	{
		form->beSigned(boss);

		try
		{
			form->execute(worker);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		delete form;
	}

	std::cout << "\n===== Execute unsigned form =====" << std::endl;
	form = intern.makeForm("shrubbery creation", "garden");
	if (form)
	{
		try
		{
			form->execute(boss);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		delete form;
	}

	return (0);
}
