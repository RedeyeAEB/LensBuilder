#include "project.h"

Project::Project() {
    filename = "";
}
Project::Project(std::string &nfilename) {
    readProject(nfilename);
}
bool Project::readProject(std::string &nfilename) {

}
bool Project::saveProject(){

}
bool Project::writeProject(std::string &filename) {

}
bool Project::forceWrite(std::string &filename) {

}

bool Project::changeFilepath(std::string &nfilename) {
    filename = nfilename;
}