#ifndef PROJECT_H
#define PROJECT_H

#include "opticassembly.h"
#include <string>

class Project {
private:
    std::string filename;
public:
    // Public variables
    OpticAssembly optics;

    // Project creation and file management
    Project();  // Generates a blank project
    Project(std::string &nfilename); // Loads a project from file
    bool readProject(std::string &nfilename);    // Read file data into project
    bool saveProject();   // Save project data to filename
    bool writeProject(std::string &filename);   // Writes to new filename. Returns true if it worked and the file didn't already exist, false otherwise.
    bool forceWrite(std::string &filename);  // Force writes, like write() except it doesn't check if the file was there.

    bool changeFilepath(std::string &nfilename);




};


#endif
