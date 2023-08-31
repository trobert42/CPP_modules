/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:27:04 by trobert           #+#    #+#             */
/*   Updated: 2022/12/21 12:06:40 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	replace(std::string s1, std::string s2, std::istream& file, std::ostream& outfile)
{
	std::string ret;
	size_t 		index_word_found;
	int			i = 0;
	bool		status = true;

	while (status)
	{
		if (i != 0)
			outfile << std::endl;
		getline(file, ret, '\n');
		if (file.eof())
			status = false;
		index_word_found = ret.find(s1.c_str(), 0, s1.length());
		while (s1 != s2 && (index_word_found != std::string::npos))
		{
			ret.erase(index_word_found, s1.length());
			ret.insert(index_word_found, s2);
			index_word_found = ret.find(s1.c_str(), index_word_found + s1.length());
		}
		i++;
		outfile << ret;
	}
}

int main(int ac, char **av)
{
	std::string		s1, s2, file_str;
	std::ifstream	file;
	std::ofstream	outfile;

	if (ac != 4)
	{
		std::cout
			<< "Error: nb of arg != 4 !" << std::endl
			<< "Try : ./replace <file_name> <old_string> <new_string>" << std::endl;
		return (-1);
	}
	s1 = av[2];
	s2 = av[3];
	file_str = av[1];
	if (s1.empty() || s2.empty())
		return (std::cout << "Error, empty string doesn't work" << std::endl, -1);
	file.open(av[1], std::ios_base::in);
	if (file.is_open())
	{
		file_str += ".replace";
		outfile.open(file_str.c_str(), std::ios_base::out);
		if (outfile.is_open())
		{
			replace(s1, s2, file, outfile);
			outfile.close();
		}
		else
			std::cout << "Failed to create file named : " << file_str << std::endl;
		file.close();
	}
	else
		std::cout << "Failed to open file named : " << av[1] << std::endl;
	return (0);
}