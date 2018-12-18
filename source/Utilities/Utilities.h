/******************************************************************************
Filename: Utilities.h

Purpose:  Cool

******************************************************************************/
#pragma once
#define RUNNING_WINDOWS
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

namespace Utils {
    #ifdef RUNNING_WINDOWS
    #define WIN32_MEAN_BEAN_MACHINE
    #include <windows.h>
    #include <Shlwapi.h>

    inline std::string GetWorkingDirectory() {
        // Obtain the handle to the process created by the executable
        HMODULE hModule = GetModuleHandle(nullptr);
        if (!hModule) { return ""; }
        
        unsigned char path[256];
        // Get the path string
        GetModuleFileName(hModule, path, sizeof(path));
        // Remove executable name and extension from path
        PathRemoveFileSpec(path);

        return std::string(path) + "\\";
    }

    //TODO: COMMENT
    inline std::vector<std::pair<std::string, bool>> GetFileList(
        const std::string& l_directory,
        const std::string& l_search = "*.*",
        bool l_directories = false)
    ) {
        std::vector<std::pair<std::string, bool>> files;
        if (l_search.empty()) { return files; }

        std::string path = l_directory + l_search;
        WIN32_FIND_DATA data;
        HANDLE found = FindFirstFile(path.c_str(), &data);
        if (found == INVALID_HANDLE_VALUE) { return files; }
        do {
            if (!(data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) || l_directories) {
                files.emplace_back(std::make_pair(
                std::string(data.cFileName),
                ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
                ));
            }
        } while (FindNextFile(found, &data));
        FindClose(found);
        return files;
    }

    //TODO: ADD LINUX
    
    //TODO: COMMENT
    #endif
    inline void ReadQuotedString(std::stringstream& l_stream, std::string& l_string) {
        l_stream >> l_string;
        if (l_string.at(0) == '"') {
            while (l_string.at(l_string.length() - 1) != '"' || !l_stream.eof()) {
                std::string str;
                l_stream >> str;
                l_string.append(" " + str);
            }
        }
        l_string.erase(std::remove(l_string.begin(), l_string.end(), '"'), l_string.end());
    }

    //TODO: COMMENT
    template<class T>
    inline T Interpolate(float tBegin, float tEnd, const T& begin_val, const T& end_val, float tX) {
        return static_cast<T>((((end_val - begin_val) / (tEnd - tBegin)) * (tX - tBegin)) + begin_val);
    }
    //TODO: EAT ASS
}