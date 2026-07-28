/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:12:54 by rexposit          #+#    #+#             */
/*   Updated: 2026/07/28 23:45:15 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
	private:
		AForm	*createShrubbery(const std::string &target) const;
		AForm	*createRobotomy(const std::string &target) const;
		AForm	*createPresidential(const std::string &target) const;

	public:
		Intern();
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(const std::string &form_name, const std::string &target) const;
};

#endif
