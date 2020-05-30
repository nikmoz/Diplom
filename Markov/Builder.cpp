#include "Builder.h"
#include "StringConcat.h"
#include <string>

static constexpr char ResourcePath[] = "Chains/";

Builder::Builder()
{
	try
	{
		m_linker = std::make_shared<Linker>("Chains/Global.txt");
	}
	catch (const char* msg)
	{
		throw msg;
	}
}

size_t Builder::PreBuild(std::ifstream& file) const
{
	if (!file)
	{
		return 0;
	}

	std::string header;
	std::getline(file, header);

	const auto backup = file.tellg();

	const size_t size = std::count(std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>(), '\n');

	file.clear();
	file.seekg(backup);
	return size;
}

std::string Builder::ParsePath(const std::string& path)
{
	if (path.find('/') == std::string::npos)
	{
		return ResourcePath + path;
	}
	return path;
}

void Builder::Build(std::ifstream& file, const std::shared_ptr<Chain>& head)
{
	const auto size = PreBuild(file);

	if (size == 0)
	{
		throw "File not found or empty";
	}

	head->m_arcs.reserve(size);

	while (!file.eof())
	{
		auto tmpArc = std::make_shared<Arc>();

		std::string type, string;
		file >> tmpArc->m_from >> tmpArc->m_to >> tmpArc->m_chance >> type;
		file.get();
		std::getline(file, string);
		if (type == "Chain")
		{
			auto file_path = ParsePath(string);

			const auto iPos = m_chainList.find(string);
			if (iPos != m_chainList.end())
			{
				tmpArc->m_iRunnable = iPos->second;

			}
			else
			{
				auto chainT = std::make_shared<Chain>();
				m_chainList.insert({ string, chainT });
				tmpArc->m_iRunnable = chainT;

				std::ifstream newFile(file_path);
				Build(newFile, chainT);
			}
		}
		else if (type == "String")
		{
			if (m_variableRegex.IsMatch(string))
			{
				string = m_linker->Link(string);
			}
			const auto stringRunner = std::make_shared<StringConcat>(string);
			tmpArc->m_iRunnable = stringRunner;
		}
		else
			throw "Wrong IRunnable type";

		head->m_arcs.push_back(tmpArc);
	}
	file.close();
}
