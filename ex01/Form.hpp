/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:40:41 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/22 20:25:48 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include <ostream>

class	Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;

	public:
		Form();
		Form(const std::string &name, int sign_grade, int execute_grade);
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();

		const std::string	&getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void	beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif
