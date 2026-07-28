/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:00:00 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/28 18:08:24 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	protected:
		virtual void	executeAction() const;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();

		class	FileOpenException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};


#endif
