/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:40:41 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/23 14:57:39 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>
#include <ostream>

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;

	protected:
		virtual void	executeAction() const = 0;

	public:
		AForm();
		AForm(const std::string &name, int sign_grade, int execute_grade);
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		virtual ~AForm();

		const std::string	&getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		class	GradeTooHighException : public	std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	FormNotSignedException : public	std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		void	beSigned(const Bureaucrat &bureaucrat);
		void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif
