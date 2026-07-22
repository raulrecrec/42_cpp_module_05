/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:39:07 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/22 18:14:19 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <exception>
#include <iostream>
#include <string>

static void	printTitle(const std::string &title)
{
	std::cout << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

static void	testValidConstruction()
{
	printTitle("Valid construction");

	try
	{
		Bureaucrat defaultBureaucrat;
		Bureaucrat highest("Highest", 1);
		Bureaucrat middle("Middle", 75);
		Bureaucrat lowest("Lowest", 150);

		std::cout << defaultBureaucrat << std::endl;
		std::cout << highest << std::endl;
		std::cout << middle << std::endl;
		std::cout << lowest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
}

static void	testInvalidConstruction()
{
	printTitle("Invalid construction");

	try
	{
		Bureaucrat tooHigh("Too high", 0);

		std::cout << "Unexpected success: " << tooHigh << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Grade 0: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("Too low", 151);

		std::cout << "Unexpected success: " << tooLow << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Grade 151: " << e.what() << std::endl;
	}
}

static void	testGradeChanges()
{
	Bureaucrat bureaucrat("Raul", 75);

	printTitle("Grade changes");

	std::cout << "Initial:   " << bureaucrat << std::endl;

	bureaucrat.incrementGrade();
	std::cout << "Increment: " << bureaucrat << std::endl;

	bureaucrat.decrementGrade();
	std::cout << "Decrement: " << bureaucrat << std::endl;
}

static void	testGradeLimits()
{
	printTitle("Highest grade limit");

	Bureaucrat highest("Highest", 1);

	std::cout << "Before: " << highest << std::endl;

	try
	{
		highest.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "After:  " << highest << std::endl;

	printTitle("Lowest grade limit");

	Bureaucrat lowest("Lowest", 150);

	std::cout << "Before: " << lowest << std::endl;

	try
	{
		lowest.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "After:  " << lowest << std::endl;
}

static void	testCopyAndAssignment()
{
	printTitle("Copy constructor and assignment operator");

	Bureaucrat original("Original", 42);
	Bureaucrat copy(original);
	Bureaucrat assigned("Assigned", 100);

	assigned = original;

	std::cout << "Original: " << original << std::endl;
	std::cout << "Copy:     " << copy << std::endl;
	std::cout << "Assigned: " << assigned << std::endl;
}

int	main()
{
	testValidConstruction();
	testInvalidConstruction();
	testGradeChanges();
	testGradeLimits();
	testCopyAndAssignment();
	return (0);
}
