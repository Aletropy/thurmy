#include "Shader.h"
#include "Core/Logger.h"

#include <fstream>
#include <sstream>

#include "Platform/OpenGL46/OpenGL46Shader.h"

namespace Thurmy
{
    std::shared_ptr<Shader> Shader::Create(const std::string& vertexPath, const std::string& fragmentPath)
    {
        return std::make_shared<OpenGL46Shader>(vertexPath, fragmentPath);
    }

    std::string Shader::ReadFile(const std::string& filepath)
    {
        std::ifstream stream(filepath);

        if (!stream.is_open())
        {
            THURMY_LOG("Error: the file %s cannot be opened", filepath.c_str());
            return std::string();
        }

        std::string line;
        std::stringstream ss;

        while (getline(stream, line))
        {
            ss << line << "\n";
        }

        return ss.str();
    }
}
