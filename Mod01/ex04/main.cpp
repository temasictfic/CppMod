/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:01:52 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/05 19:24:35 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

void replace(char const *argv[])
{
    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    std::ifstream ifs(filename.c_str());
    if (ifs.good())
    {
        if (ifs.peek() == std::ifstream::traits_type::eof())
        {
            ifs.close();
            std::cerr << "Error: Empty File!" << std::endl;
            return;
        }
        std::stringstream newfile;
        std::size_t diffnum = 0;
        std::string line;
        std::size_t index;
        while (ifs.good() && newfile.good())
        {
            std::getline(ifs, line);
            index = line.find(s1, 0);
            while (index != std::string::npos)
            {
                diffnum++;
                line.erase(index, s1.length());
                line.insert(index, s2);
                index = line.find(s1, index);
            }
            newfile << line;
            if (ifs.eof())
                break;
            newfile << std::endl;
        }
        if (diffnum == 0)
        {
            ifs.close();
            std::cout << "Not found any " << s1 << std::endl;
            return;
        }
        std::ofstream ofs(filename.append(".replace").c_str());
        ofs << newfile.str();
        ifs.close();
        ofs.close();
    }
    else
    {
        ifs.close();
        std::cerr << strerror(errno) << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    if (argc == 4)
        replace(argv);
    else
        std::cout << "Wrong Usage!" << std::endl
                  << "./replace <filename> <current str> <new str>" << std::endl;
    return 0;
}
