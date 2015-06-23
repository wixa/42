/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:28:18 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:28:18 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat a("test", 1);
    Form *rrf;

    try {
//        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender2");
        a.signForm(*rrf);
        a.executeForm(*rrf);
        std::cout << a << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what();
    }
    try {
        rrf = someRandomIntern.makeForm("test bidon", "Bender3");
    }
    catch (std::exception &e) {
        std::cerr << e.what();
    }
    return 0;

}