#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::string line;
	if (s1.empty() || s2.empty())
	{
		std::cerr << "String must not be empty." << std::endl;
		return;
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "The file could not be opened: " << filename << std::endl;
		return;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "The file could not be created: " << filename + ".replace" << std::endl;
		inputFile.close();
		return;
	}
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();

}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Invalid format" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	replaceInFile(filename, s1, s2);
	return 0;
}
