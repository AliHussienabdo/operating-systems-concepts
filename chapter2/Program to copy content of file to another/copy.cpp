#include <iostream>
#include <fstream>
using namespace std;

int main(){

    string SourceFileName, DestinationFileName;

    std::cout << "Enter the Source file: ";
    std::cin >> SourceFileName;

    std::cout << "Enter the Destination file: ";
    std::cin >> DestinationFileName;

    ifstream SourcFile;
    SourcFile.open(SourceFileName);

    ofstream DestinationFile;
    DestinationFile.open(DestinationFileName);

    if(!SourcFile){
        cout << SourceFileName << " not found" << endl;
        exit(EXIT_FAILURE);
    }

    if(!DestinationFile){
        cout << DestinationFileName << " not found" << endl;
        exit(EXIT_FAILURE);
    }

    string Line;

    while( SourcFile >> Line){
        DestinationFile << Line << endl;
    }

    SourcFile.close();
    DestinationFile.close();

    std::system( "pause" );
}