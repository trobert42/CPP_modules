/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:09:10 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 10:33:48 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", "Default", 145, 137)
{
	std::cout << "Default constructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout
		<< "Parametric constructor for " << this->getName() 
		<< " with sign grade " << this->getSignGrade()
		<< ", execute grade " << this->getExecGrade()
		<< " and target \"" << this->getTarget()
		<< "\" called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & cpy) : AForm(cpy.getName(), cpy.getTarget(), cpy.getSignGrade(), cpy.getExecGrade())
{
	std::cout << "Copy constructor for " << this->getName() << " called" << std::endl;
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor for " << this->getName() << " called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << "Assignment operator ShrubberyCreationForm called" << std::endl;
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > AForm::getExecGrade())
		throw AForm::GradeTooLowException();
	else if (this->getStatusSign() == false)
		throw AForm::NotSignedYetException();
	else
	{
		std::ofstream	outfile;
		std::string		outfile_name = this->getTarget();

		outfile_name += "_shrubbery";
		outfile.open(outfile_name.c_str(), std::ios_base::out);
		if (outfile.is_open())
		{
			outfile
				<< "                                   .         ;" << std::endl
				<< "      .              .              ;%     ;;" << std::endl
				<< "        ,           ,                :;%  %;" << std::endl
				<< "         :         ;                   :;%;\'     .," << std::endl
				<< ",.        %;     %;            ;        %;\'    ,;" << std::endl
				<< "  ;       ;%;  %%;        ,     %;    ;%;    ,%\'" << std::endl
				<< "   %;       %;%;      ,  ;       %;  ;%;   ,%;\'" << std::endl
				<< "    ;%;      %;        ;%;        % ;%;  ,%;\'" << std::endl
				<< "     `%;.     ;%;     %;\'         `;%%;.%;\'" << std::endl
				<< "      `:;%.    ;%%. %@;        %; ;@%;%\'" << std::endl
				<< "         `:%;.  :;bd%;          %;@%;\'" << std::endl
				<< "           `@%:.  :;%.         ;@@%;\'" << std::endl
				<< "             `@%.  `;@%.      ;@@%;" << std::endl
				<< "               `@%%. `@%%    ;@@%;" << std::endl
				<< "                 ;@%. :@%%  %@@%;" << std::endl
				<< "                   %@bd%%%bd%%:;" << std::endl
				<< "                     #@%%%%%:;;" << std::endl
				<< "                     %@@%%%::;" << std::endl
				<< "                     %@@@%(o);  . \'" << std::endl
				<< "                     %@@@o%;:(.,\'" << std::endl
				<< "                 `.. %@@@o%::;" << std::endl
				<< "                    `)@@@o%::;" << std::endl
				<< "                     %@@(o)::;" << std::endl
				<< "                    .%@@@@%::;" << std::endl
				<< "                    ;%@@@@%::;." << std::endl
				<< "                   ;%@@@@%%:;;;." << std::endl
				<< "               ...;%@@@@@%%:;;;;,..  " << std::endl;
			std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		}
		else
		{
			std::cout 
				<< executor.getName() << " couldn't executed " << this->getName() 
				<< " because it has failed to create file named " << outfile_name << std::endl;
		}
		outfile.close();
	}
}
