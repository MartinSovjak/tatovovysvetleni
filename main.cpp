#ifndef __PROGTEST__
#include <iostream>
#include <cstdlib>

#endif /* __PROGTEST__ */

#include <fstream>

using namespace std;

/* Vase pomocne funkce (jsou-li potreba) */

int evenOdd ( const char * srcFileName, const char * dstFileName )
 {

   ifstream myFile;

    int nacitani;

   myFile.exceptions ( ifstream::failbit | ifstream::badbit );
    try {
        myFile.open (srcFileName, std::ifstream::out | std::ifstream::app);

        while (myFile >> nacitani){


                if (nacitani%2 == 0) {

                    ofstream fileInto;
                    fileInto.exceptions ( ofstream::failbit | ofstream::badbit);
                    try {
                        fileInto.open(dstFileName, std::ofstream::out | std::ofstream::app);
                        fileInto << nacitani << endl;


                    }
                    catch (const ofstream::failure& e){

                        return (0);
                    }

                    fileInto.close();
                }
                if(myFile.eof())
                    break;

        }
    }
    catch (const ifstream::failure& e) {

        return(0);
    }

    myFile.close();


ifstream myFile2;
   myFile2.exceptions ( ifstream::failbit | ifstream::badbit );
    try {

        myFile2.open (srcFileName, std::ifstream::out | std::ifstream::app);
        while (myFile2 >> nacitani){



                if ((nacitani-1)%2 == 0) {

                    ofstream fileInto2;
                    fileInto2.exceptions ( ofstream::failbit | ofstream::badbit);
                    try {
                        fileInto2.open(dstFileName, std::ofstream::out | std::ofstream::app);
                        fileInto2 << nacitani << endl;


                    }
                    catch (const ofstream::failure& e){

                        return (0);
                    }

                    fileInto2.close();
                }
                 if(myFile2.eof())
                    break;

        }
    }
    catch (const ifstream::failure& e) {

        return(0);
    }

    myFile2.close();

    return(1);
 }

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
 {

   char srcFileName[] = "in.txt";
   char dstFileName[] = "out.txt";
   cout << evenOdd(srcFileName,dstFileName);
   return 0;
 }
#endif /* __PROGTEST__ */
