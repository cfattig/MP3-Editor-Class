/*************************************************************************//**
 * @file
 *
 * @brief the file containing int main
 *
 * @mainpage Program 4 - MP3 Editor Class
 *
 * @section course_section Course Information
 *
 * @author Bailey Ezra Thorson, Christian Fattig, Jeffrey Ross
 *
 * @date 12/05/2016
 *
 * @par Professor:
 *         Roger Schrader
 *
 * @par Course:
 *         CSC 250
 *
 * @par Location:
 *         McLaury - Room 107
 *
 * @section program_section Program Information
 *
 * @details This program modifies the tags of MP3 files. It must be passed at 
 * least one file name in order to function. The program begins by checking
 * that it was passed at least two arguements (A file name and the execution
 * path). It then opens a genres.bin file containing a list of possible genres.
 * if this file fails to open, it outputs an error and exits, this file is very
 * important, the program cannot function without it. After those checks have 
 * been made, the program beings looping through all the filenames passed to it.
 *
 * For each filename, the program begins by attempting to open the file. If it 
 * fails to do so, it will exit. Once it successfully opens the file, it will 
 * import the information contained in the last 128 bytes to a mp3Tag structure.
 * This structure stores id3v1.1 data tags for modification. The program will
 * then give the user a list of modifiable fields in that structure, as well as
 * options to save changes, play the song, or edit the next song. Modifiable
 * fields presented to the user are: title, artist, album, year, genre, track
 * number, and comments. Selecting any of these option will bring the user to 
 * another field where they may modify these fields. 
 *
 * Once the desired changes have been made to the file, the user may save the
 * file, or edit a new file. Saving the file will modify the original tags in
 * the .mp3 file. Choosing to edit a new file will discard any unsaved changes
 * and close the file, then open up the next file in the list of files passed to
 * the program when it was started. Once the list of files to be edited has been
 * exhausted, the program will close all open files, and exit.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      
 *
 * @par Usage:
   @verbatim
   c:\> Prog1.exe file1.mp3 .... fileN.mp3
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug none
 *
 * @todo
 * 
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date           Modification
   -------------  -------------------------------------------------------------
  https://gitlab.mcs.sdsmt.edu/csc250fa16p4/team10/commits/master

   @endverbatim
 *
 *****************************************************************************/

#pragma pack(1)

#define _CRT_SECURE_NO_WARNINGS 1

#include "mp3Editor.h"
#include "functions.h"


/***************************************************************************//**
* @author Jeffrey Ross
*
* @par Description :
* This function is the main body of the program. It first checks to make sure
* that mp3 files were included. The function then cycles through the mp3 files
* but only advances from file to file when the user requests to. It loads the
* contents of the current mp3 file and calls a function to display the menu to
* the user for what options they have. It then calls another function to act
* upon that choice.
* 
* @param[in] argc - the number of arguments from the command prompt.
* @param[in] argv - a 2d array of characters containing the arguments.
*
* @returns 0 if the program has gone through everything successfully
* @returns 1 if there were any errors
*
******************************************************************************/
int main(int argc, char **argv)
{
    if (argc == 1) //no files included
    {
        cout << "Usage: prog4.exe file1 file2 ... filen" << endl;
        cout << "No mp3 files included . . . ending program" << endl;
        return 1;
    }

    int i; // counter for for loops
    mp3Editor mp3; // holds the info for a file

    for (i = 1; i < argc; i++) // goes through each file given
    {
        int choice = 0;
        ifstream fin;
        ofstream fout;
        fin.open(argv[i], ios::in | ios::out | ios::binary);

        if (!fin.is_open())
        {
            cout << "File did not open" << endl;
            return 1;
        }

        fin >> mp3; // loads file info into mp3
        fin.close();
        fout.open(argv[i], ios::in | ios::out | ios::binary);
        if (!fout.is_open())
        {
            cout << "File did not open" << endl;
            return 1;
        }

        while (choice != 10) //displays menu until 10 is entered
        {
            cout << mp3;
            displayMenu();
            cin >> choice;
            pickChoice(choice, mp3, fout, argv[i]);
            if (choice < 1 || choice > 13)
                cout << "not a valid choice" << endl;
        }

        fout.close();
        cout << endl << endl << endl;
    }

    return 0;
}